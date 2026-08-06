/*
 * @copyright 2026 KISPE Space Systems Ltd.
 *
 * Licensed under the ESA Public License (ESA-PL) Permissive (Type 3),
 * Version 2.4 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://essr.esa.int/license/list
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "datauncompressor.h"
#include "zlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These 2 #defines provide the MAX size of the pre and post compression buffers.
// They default to 4096 (4kBytes) but this can be overridden by the TASTE main makefile
#ifndef DATAUNCOMPRESSOR_INPUT_BUFFER_SIZE
#define DATAUNCOMPRESSOR_INPUT_BUFFER_SIZE (4096)
#endif

#ifndef DATAUNCOMPRESSOR_OUTPUT_BUFFER_SIZE
#define DATAUNCOMPRESSOR_OUTPUT_BUFFER_SIZE (4096)
#endif


static uint8_t inputBuffer[DATAUNCOMPRESSOR_INPUT_BUFFER_SIZE];
static uint32_t inputBufferLength = 0;

static uint8_t outputBuffer[DATAUNCOMPRESSOR_OUTPUT_BUFFER_SIZE];
static uint32_t outputBufferLength = 0;

static asn1SccCompressorState state = CompressorState_compressor_not_initialized;

void datauncompressor_startup(void)
{
    datauncompressor_PI_ClearBuffer();
    state = CompressorState_compressor_idle;
}

void datauncompressor_PI_ClearBuffer(void)
{
    state = CompressorState_compressor_writing_data;
    inputBufferLength = 0;
    outputBufferLength = 0;

    state = CompressorState_compressor_idle;
}

void datauncompressor_PI_WriteBuffer(
    const asn1SccCompressorDataBuffer* dataBuffer,
    const asn1SccT_UInt32* dataLength
)
{
    state = CompressorState_compressor_writing_data;

    for (uint32_t byteIndex = 0; byteIndex < *dataLength; ++byteIndex)
    {
        inputBuffer[inputBufferLength + byteIndex] = dataBuffer->arr[byteIndex];
    }

    inputBufferLength += *dataLength;

    state = CompressorState_compressor_idle;
}

void datauncompressor_PI_StartUncompression(void)
{
    state = CompressorState_compressor_working;

    if (inputBufferLength == 0)
    {
        state = CompressorState_compressor_fail;
        return;
    }

    int result = Z_BUF_ERROR;
    uLong decompressedLength = 0;

    while (result == Z_BUF_ERROR)
    {
        decompressedLength = DATAUNCOMPRESSOR_OUTPUT_BUFFER_SIZE;

        result = uncompress(
            (Bytef*)outputBuffer,
            &decompressedLength,
            (const Bytef*)inputBuffer,
            (uLong)inputBufferLength
        );
    }

    if (result != Z_OK)
    {
        outputBufferLength = 0;
        state = CompressorState_compressor_fail;
        return;
    }

    outputBufferLength = (uint32_t)decompressedLength;

    state = CompressorState_compressor_success;
}

void datauncompressor_PI_Status(
    asn1SccCompressorState* currentStatus,
    asn1SccT_UInt32* decompressedDataLength
)
{
    *currentStatus = state;
    *decompressedDataLength = outputBufferLength;
}

void datauncompressor_PI_ReadData(
    asn1SccCompressorDataBuffer* dataOut,
    const asn1SccT_UInt32* byteOffset,
    const asn1SccT_UInt32* bytesToRead,
    asn1SccT_UInt32* bytesWritten
    )
{
    asn1SccT_UInt32 iDataLengthToRead;
    iDataLengthToRead = *bytesToRead;
    *bytesWritten = 0;

    // If we are trying to read off the end of the buffer
    if (*byteOffset >= outputBufferLength)
    {
        return;
    }

    // If we are goint to go off the end of the array, since we don't necessarily
    // know how much data to read, just set it to the bounds of the available data.
    if ((*byteOffset + *bytesToRead) > outputBufferLength)
    {
        iDataLengthToRead = outputBufferLength - *byteOffset;
    }


    // Read out the data
    for (uint32_t byteIndex = 0; byteIndex < iDataLengthToRead; ++byteIndex)
    {
        dataOut->arr[byteIndex] = outputBuffer[*byteOffset + byteIndex];
        *bytesWritten += 1;
    }
}
