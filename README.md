# TASTE_Lossless_Compression_Decompression
This repository includes reusable components that supports the lossless compression and decompression of data

## Content
This repository contains 2 reusable components:
- DataCompressor
- DataUncompressor

Both of the above are implemented as individual TASTE functions. They make use of the Zlib compression library

The repository also contains a test function called TestCompressUncompress which is designed to demonstrate the compression and decompression over a UART interface running on a SAMRH71 processor.

## Depedencies
This reusable component depends upon the latest install of TASTE, see https://gitlab.esa.int/taste/taste-setup/-/wikis/home for details on installation.
The demonstration of the reusable component depends upon the SAMRH71 runtime produced by N7 Space. This will become part of the TASTE install by the end of 2026.
The demonstration of the reusable component runs on the SAMRH71 EK development board and makes use of the FLEXCOM1 UART interface that is accessible via a USB port on the SAMRH71 EK board.

## Installation & building
Clone this repository into a directory off your home directory on a Linux installation.

Enter the directory where you have cloned the TASTE project.

type "taste" to launch the TASTE IDE

![interface view of TASTE reusable components](https://github.com/KISPE-Space/TASTE_Lossless_Compression_Decompression/blob/main/screenshots/TASTE%20model_1.png)

You'll note the 2 reusable components on the right side of the interface view, these can be exported using the TASTE export tool to be placed into your model.

In order to build the model for a SAMRH71 target, navigate to the deployment view and then click the build button (bottom left).

![deployment view of TASTE reusable components](https://github.com/KISPE-Space/TASTE_Lossless_Compression_Decompression/blob/main/screenshots/TASTE%20model_2.png)

This build is designed to run from the internal SRAM of the SAMRH71. 

### Build Configurations
The underlying ZLib library relies upon dynamic memory allocation with a heap. Since the SAMRH71 Runtime provided by N7 uses an RTEMS distribution that does not support dynamic memory allocation, Zlib has been modified so that a number of buffers are statically allocated at compile time. These buffers are used to:
- Hold the incoming data (to be compressed/decompressed) and the output data (post-compression/decompression). they default to 4096 bytes in size, this can be overwritten by defining the compile time #define "DATACOMPRESSOR_INPUT_BUFFER_SIZE", "DATACOMPRESSOR_OUTPUT_BUFFER_SIZE", "DATAUNCOMPRESSOR_INPUT_BUFFER_SIZE", "DATAUNCOMPRESSOR_OUTPUT_BUFFER_SIZE", setting these constants will define the max size of the uncompressed and compressed data at compile time.
- Internal Memory for the ZLib library. Zlib tends to use around ~400 kBytes of memory to perform its compression (decompression temds to be less costly). The maximum memory available to Zlib is defined by the compile time constant "STATIC_POOL_SIZE". This defaults to 384kBytes (the number is specified in bytes). If the compression fails, it may be that Zlib requires more memory, adjusting this compile time contant can be done to provide it further resource.

## Running the example model
In order to run the example model: 
- use a JTAG probe (e.g. Segger J-Link) and connect via GDB to the SAMRH71 EK development board
- connect the FLEXCOM1 UART to a computer using a USB connection to the SAMRH71 EK board, baud 115200, 8E1
- load the code and run via GDB.

You should now see the following output on the terminal:

![deployment view of TASTE reusable components](https://github.com/KISPE-Space/TASTE_Lossless_Compression_Decompression/blob/main/screenshots/TASTE%20model_3.png)

By streaming data to the terminal (either a file or by typing a message), you will observe the compression and decompression process. Note, the example program waits for "####" to be typed on the terminal to signify the end of the data to compress and then decompress.

