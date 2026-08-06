# TASTE_Lossless_Compression_Decompression
This repository includes reusable components that supports the lossless compression and decompression of data

# Content
This repository contains 2 reusable components:
- DataCompressor
- DataUncompressor
Both of the above are implemented individual TASTE functions. They make use of the Zlib compression library

The repository also contains a test function called TestCompressUncompress which is designed to demonstrate the compression and decompression over a UART interface running on a SAMRH71 processor.

# Depedencies
This reusable component depends upon the latest install of TASTE, see https://gitlab.esa.int/taste/taste-setup/-/wikis/home for details on installation.
The demonstration of the reusable component depends upon the SAMRH71 runtime produced by N7 Space. This will become part of the TASTE install by the end of 2026.
The demonstration of the reusable component runs on the SAMRH71 EK development board and makes use of the FLEXCOM1 UART interface that is accessible via a USB port on the SAMRH71 EK board.

# Installation & building
Clone this repository into a directory off your home directory on a Linux installation. 

