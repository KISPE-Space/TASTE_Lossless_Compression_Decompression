divert(-1)
/*
*  This m4 file uses the following diverts:
*    1 for overall structure
*    5 for cast functions for GUI parameter subtypes
*    7 for num functions on Enum types
*    10 for signals
*    20 for functions
*/dnl
include(templates.m4)
divert(-1)
define(`m4_testcompressuncompress_comp_clearbuffer',`datacompressor_clearbuffer')dnl
define(`m4_testcompressuncompress_Comp_ClearBuffer_provider',`datacompressor')dnl
define(`m4_testcompressuncompress_comp_readdata',`datacompressor_readdata')dnl
define(`m4_testcompressuncompress_Comp_ReadData_provider',`datacompressor')dnl
define(`m4_testcompressuncompress_comp_startcompression',`datacompressor_startcompression')dnl
define(`m4_testcompressuncompress_Comp_StartCompression_provider',`datacompressor')dnl
define(`m4_testcompressuncompress_comp_status',`datacompressor_status')dnl
define(`m4_testcompressuncompress_Comp_Status_provider',`datacompressor')dnl
define(`m4_testcompressuncompress_comp_writebuffer',`datacompressor_writebuffer')dnl
define(`m4_testcompressuncompress_Comp_WriteBuffer_provider',`datacompressor')dnl
define(`m4_testcompressuncompress_uncomp_clearbuffer',`datauncompressor_clearbuffer')dnl
define(`m4_testcompressuncompress_Uncomp_ClearBuffer_provider',`datauncompressor')dnl
define(`m4_testcompressuncompress_uncomp_readdata',`datauncompressor_readdata')dnl
define(`m4_testcompressuncompress_Uncomp_ReadData_provider',`datauncompressor')dnl
define(`m4_testcompressuncompress_uncomp_startuncompression',`datauncompressor_startuncompression')dnl
define(`m4_testcompressuncompress_Uncomp_StartUncompression_provider',`datauncompressor')dnl
define(`m4_testcompressuncompress_uncomp_status',`datauncompressor_status')dnl
define(`m4_testcompressuncompress_Uncomp_Status_provider',`datauncompressor')dnl
define(`m4_testcompressuncompress_uncomp_writebuffer',`datauncompressor_writebuffer')dnl
define(`m4_testcompressuncompress_Uncomp_WriteBuffer_provider',`datauncompressor')dnl
define(`m4_testcompressuncompress_samrh71tx',`uartotherend_samrh71tx')dnl
define(`m4_testcompressuncompress_samrh71tx_provider',`uartotherend')dnl
define(`m4_uartotherend_samrh71rx',`testcompressuncompress_samrh71rx')dnl
define(`m4_uartotherend_samrh71rx_provider',`testcompressuncompress')dnl
define(`m4_env_runonce',`testcompressuncompress_runonce')dnl
define(`m4_env_RunOnce_provider',`testcompressuncompress')dnl
divert(1)dnl
system taste;
/*
 *
 * Data View
 *
 */
include(dataview.if)

type math = abstract
    integer abs(integer);
    real abs(real);
    integer fix(real);
    real power(real, real);
    integer Shift_Left(integer, integer);
    integer Shift_Right(integer, integer);
    integer ceil(real);
    integer floor(real);
    real float(integer);
    integer round(real);
    real sin(real);
    real cos(real);
    integer trunc(real);
endabstract;

type enum_functions = abstract
undivert(7)
endabstract;


divert(20)
m4_c_function(datacompressor,(ClearBuffer,(),(),(), 0),

(ReadData,(dataOut, byteOffset, bytesToRead, bytesWritten),(CompressorDataBuffer, T_UInt32, T_UInt32, T_UInt32),(PARAM_OUT, PARAM_IN, PARAM_IN, PARAM_OUT), 0),

(StartCompression,(),(),(), 0),

(Status,(currentStatus, compressedDataLength),(CompressorState, T_UInt32),(PARAM_OUT, PARAM_OUT), 0),

(WriteBuffer,(dataBuffer, dataLength),(CompressorDataBuffer, T_UInt32),(PARAM_IN, PARAM_IN), 0),

)

m4_c_function(datauncompressor,(ClearBuffer,(),(),(), 0),

(ReadData,(dataOut, byteOffset, bytesToRead, bytesWritten),(CompressorDataBuffer, T_UInt32, T_UInt32, T_UInt32),(PARAM_OUT, PARAM_IN, PARAM_IN, PARAM_OUT), 0),

(StartUncompression,(),(),(), 0),

(Status,(currentStatus, decompressedDataLength),(CompressorState, T_UInt32),(PARAM_OUT, PARAM_OUT), 0),

(WriteBuffer,(dataBuffer, dataLength),(CompressorDataBuffer, T_UInt32),(PARAM_IN, PARAM_IN), 0),

)

m4_c_function(testcompressuncompress,(RunOnce,(),(),(), 0),

// ERROR: Interface "samrh71rx" in function "TestCompressUncompress" has unsupported kind: "SPORADIC_OPERATION"

)

m4_sporadic_itf_handler(
    uartotherend,
    samrh71tx,
    T_UInt8,
     0,
     1)




include(uartotherend.if)



divert(1)
type assign = abstract
undivert(5)
endabstract;

/*
 *
 * Interface View
 *
 */
signal set_timer(integer);
signal reset_timer();

undivert(10)

undivert(20)

endsystem;

priorityrules
undivert(30)
endpriorityrules;
