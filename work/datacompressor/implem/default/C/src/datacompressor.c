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

#include "datacompressor.h"
#include "zlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These 2 #defines provide the MAX size of the pre and post compression buffers.
// They default to 4096 (4kBytes) but this can be overridden by the TASTE main makefile
#ifndef DATACOMPRESSOR_INPUT_BUFFER_SIZE
    #define DATACOMPRESSOR_INPUT_BUFFER_SIZE (4096)
#endif

#ifndef DATACOMPRESSOR_OUTPUT_BUFFER_SIZE
    #define DATACOMPRESSOR_OUTPUT_BUFFER_SIZE (4096)
#endif

static uint8_t inputBuffer[DATACOMPRESSOR_INPUT_BUFFER_SIZE];
static uint32_t inputBufferLength = 0;

static uint8_t outputBuffer[DATACOMPRESSOR_OUTPUT_BUFFER_SIZE];
static uint32_t outputBufferLength = 0;

static asn1SccCompressorState state = CompressorState_compressor_not_initialized;

void datacompressor_startup(void)
{
    datacompressor_PI_ClearBuffer();
    state = CompressorState_compressor_idle;
}

void datacompressor_PI_ClearBuffer(void)
{
    state = CompressorState_compressor_writing_data;

    inputBufferLength = 0;
    outputBufferLength = 0;

    state = CompressorState_compressor_idle;
}

void datacompressor_PI_WriteBuffer(
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

void datacompressor_PI_StartCompression(void)
{
    state = CompressorState_compressor_working;

    if (inputBufferLength == 0)
    {
        //printf("[DataCompressor Error] No input data - call WriteBuffer first\n");
        state = CompressorState_compressor_fail;
        return;
    }

    // compressBound gives the worst-case output size for a given input length
    uLong compressedCapacity = compressBound((uLong)inputBufferLength);

    uLong compressedLength = compressedCapacity;

    int result = compress2(
        (Bytef*)outputBuffer,
        &compressedLength,
        (const Bytef*)inputBuffer,
        (uLong)inputBufferLength,
        Z_BEST_COMPRESSION
        );

    if (result != Z_OK)
    {
        outputBufferLength = 0;
        state = CompressorState_compressor_fail;
        return;
    }

    outputBufferLength = (uint32_t)compressedLength;

    state = CompressorState_compressor_success;
}

void datacompressor_PI_Status(
    asn1SccCompressorState* currentStatus,
    asn1SccT_UInt32* compressedDataLength
    )
{
    *currentStatus = state;
    *compressedDataLength = outputBufferLength;
}

void datacompressor_PI_ReadData(
    asn1SccCompressorDataBuffer* dataOut,
    const asn1SccT_UInt32* byteOffset,
    const asn1SccT_UInt32* bytesToRead,
    asn1SccT_UInt32* bytesWritten
    )
{
    *bytesWritten = 0;


    if (*byteOffset >= outputBufferLength)
    {
        return;
    }

    if ((*byteOffset + *bytesToRead) > outputBufferLength)
    {
        return;
    }

    for (uint32_t byteIndex = 0; byteIndex < *bytesToRead; ++byteIndex)
    {
        dataOut->arr[byteIndex] = outputBuffer[*byteOffset + byteIndex];
        *bytesWritten += 1;
    }
}
