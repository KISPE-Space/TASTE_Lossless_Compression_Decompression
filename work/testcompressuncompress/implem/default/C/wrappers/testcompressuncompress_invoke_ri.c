// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error testcompressuncompress_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned testcompressuncompress_initialized;

void testcompressuncompress_RI_Comp_ClearBuffer_To_PID(asn1SccPID dest_pid);
void testcompressuncompress_RI_Comp_ClearBuffer(void);
void testcompressuncompress_RI_Comp_ClearBuffer(void)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Comp_ClearBuffer_To_PID(PID_env);
}

void testcompressuncompress_RI_Comp_ClearBuffer_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_comp_clearbuffer(asn1SccPID);
   vm_testcompressuncompress_comp_clearbuffer(dest_pid);

  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Comp_ReadData_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
);
void testcompressuncompress_RI_Comp_ReadData(
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
);
void testcompressuncompress_RI_Comp_ReadData(
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Comp_ReadData_To_PID(PID_env, OUT_dataout, IN_byteoffset, IN_bytestoread, OUT_byteswritten
);
}

void testcompressuncompress_RI_Comp_ReadData_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
)
{

   size_t      size_OUT_buf_dataout = 0;
   size_t      size_OUT_buf_byteswritten = 0;

   // Send the message via the middleware API
   extern void vm_testcompressuncompress_comp_readdata
     (asn1SccPID,
      void *, size_t *,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_testcompressuncompress_comp_readdata
     (dest_pid,
      (void *)OUT_dataout, &size_OUT_buf_dataout,
      (void *)IN_byteoffset, sizeof(asn1SccT_UInt32),
      (void *)IN_bytestoread, sizeof(asn1SccT_UInt32),
      (void *)OUT_byteswritten, &size_OUT_buf_byteswritten);


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Comp_StartCompression_To_PID(asn1SccPID dest_pid);
void testcompressuncompress_RI_Comp_StartCompression(void);
void testcompressuncompress_RI_Comp_StartCompression(void)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Comp_StartCompression_To_PID(PID_env);
}

void testcompressuncompress_RI_Comp_StartCompression_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_comp_startcompression(asn1SccPID);
   vm_testcompressuncompress_comp_startcompression(dest_pid);

  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Comp_Status_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_compresseddatalength
);
void testcompressuncompress_RI_Comp_Status(
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_compresseddatalength
);
void testcompressuncompress_RI_Comp_Status(
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_compresseddatalength
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Comp_Status_To_PID(PID_env, OUT_currentstatus, OUT_compresseddatalength
);
}

void testcompressuncompress_RI_Comp_Status_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_compresseddatalength
)
{

   size_t      size_OUT_buf_currentstatus = 0;
   size_t      size_OUT_buf_compresseddatalength = 0;

   // Send the message via the middleware API
   extern void vm_testcompressuncompress_comp_status
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testcompressuncompress_comp_status
     (dest_pid,
      (void *)OUT_currentstatus, &size_OUT_buf_currentstatus,
      (void *)OUT_compresseddatalength, &size_OUT_buf_compresseddatalength);


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Comp_WriteBuffer_To_PID(asn1SccPID dest_pid, 
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
);
void testcompressuncompress_RI_Comp_WriteBuffer(
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
);
void testcompressuncompress_RI_Comp_WriteBuffer(
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Comp_WriteBuffer_To_PID(PID_env, IN_databuffer, IN_datalength
);
}

void testcompressuncompress_RI_Comp_WriteBuffer_To_PID(asn1SccPID dest_pid, 
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
)
{


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_comp_writebuffer
     (asn1SccPID,
      void *, size_t,
      void *, size_t);

   vm_testcompressuncompress_comp_writebuffer
     (dest_pid,
      (void *)IN_databuffer, sizeof(asn1SccCompressorDataBuffer),
      (void *)IN_datalength, sizeof(asn1SccT_UInt32));


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Uncomp_ClearBuffer_To_PID(asn1SccPID dest_pid);
void testcompressuncompress_RI_Uncomp_ClearBuffer(void);
void testcompressuncompress_RI_Uncomp_ClearBuffer(void)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Uncomp_ClearBuffer_To_PID(PID_env);
}

void testcompressuncompress_RI_Uncomp_ClearBuffer_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_uncomp_clearbuffer(asn1SccPID);
   vm_testcompressuncompress_uncomp_clearbuffer(dest_pid);

  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Uncomp_ReadData_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
);
void testcompressuncompress_RI_Uncomp_ReadData(
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
);
void testcompressuncompress_RI_Uncomp_ReadData(
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Uncomp_ReadData_To_PID(PID_env, OUT_dataout, IN_byteoffset, IN_bytestoread, OUT_byteswritten
);
}

void testcompressuncompress_RI_Uncomp_ReadData_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorDataBuffer *OUT_dataout,
       const asn1SccT_UInt32       *IN_byteoffset,
       const asn1SccT_UInt32       *IN_bytestoread,
       asn1SccT_UInt32             *OUT_byteswritten
)
{

   size_t      size_OUT_buf_dataout = 0;
   size_t      size_OUT_buf_byteswritten = 0;

   // Send the message via the middleware API
   extern void vm_testcompressuncompress_uncomp_readdata
     (asn1SccPID,
      void *, size_t *,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_testcompressuncompress_uncomp_readdata
     (dest_pid,
      (void *)OUT_dataout, &size_OUT_buf_dataout,
      (void *)IN_byteoffset, sizeof(asn1SccT_UInt32),
      (void *)IN_bytestoread, sizeof(asn1SccT_UInt32),
      (void *)OUT_byteswritten, &size_OUT_buf_byteswritten);


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Uncomp_StartUncompression_To_PID(asn1SccPID dest_pid);
void testcompressuncompress_RI_Uncomp_StartUncompression(void);
void testcompressuncompress_RI_Uncomp_StartUncompression(void)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Uncomp_StartUncompression_To_PID(PID_env);
}

void testcompressuncompress_RI_Uncomp_StartUncompression_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_uncomp_startuncompression(asn1SccPID);
   vm_testcompressuncompress_uncomp_startuncompression(dest_pid);

  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Uncomp_Status_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_decompresseddatalength
);
void testcompressuncompress_RI_Uncomp_Status(
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_decompresseddatalength
);
void testcompressuncompress_RI_Uncomp_Status(
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_decompresseddatalength
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Uncomp_Status_To_PID(PID_env, OUT_currentstatus, OUT_decompresseddatalength
);
}

void testcompressuncompress_RI_Uncomp_Status_To_PID(asn1SccPID dest_pid, 
      asn1SccCompressorState *OUT_currentstatus,
       asn1SccT_UInt32        *OUT_decompresseddatalength
)
{

   size_t      size_OUT_buf_currentstatus = 0;
   size_t      size_OUT_buf_decompresseddatalength = 0;

   // Send the message via the middleware API
   extern void vm_testcompressuncompress_uncomp_status
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testcompressuncompress_uncomp_status
     (dest_pid,
      (void *)OUT_currentstatus, &size_OUT_buf_currentstatus,
      (void *)OUT_decompresseddatalength, &size_OUT_buf_decompresseddatalength);


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_Uncomp_WriteBuffer_To_PID(asn1SccPID dest_pid, 
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
);
void testcompressuncompress_RI_Uncomp_WriteBuffer(
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
);
void testcompressuncompress_RI_Uncomp_WriteBuffer(
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_Uncomp_WriteBuffer_To_PID(PID_env, IN_databuffer, IN_datalength
);
}

void testcompressuncompress_RI_Uncomp_WriteBuffer_To_PID(asn1SccPID dest_pid, 
      const asn1SccCompressorDataBuffer *IN_databuffer,
       const asn1SccT_UInt32             *IN_datalength
)
{


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_uncomp_writebuffer
     (asn1SccPID,
      void *, size_t,
      void *, size_t);

   vm_testcompressuncompress_uncomp_writebuffer
     (dest_pid,
      (void *)IN_databuffer, sizeof(asn1SccCompressorDataBuffer),
      (void *)IN_datalength, sizeof(asn1SccT_UInt32));


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testcompressuncompress_RI_samrh71tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_ibyteout
);
void testcompressuncompress_RI_samrh71tx(
      const asn1SccT_UInt8 *IN_ibyteout
);
void testcompressuncompress_RI_samrh71tx(
      const asn1SccT_UInt8 *IN_ibyteout
)
{
   // When no destination is specified, send to everyone (multicast)
   testcompressuncompress_RI_samrh71tx_To_PID(PID_env, IN_ibyteout
);
}

void testcompressuncompress_RI_samrh71tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_ibyteout
)
{
   int ibyteout_error_code = 0;
   // Encode parameter iByteOut using ASN.1 ACN
   
   static char IN_buf_ibyteout[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_ibyteout =
      Encode_ACN_T_UInt8
        ((void *)&IN_buf_ibyteout,
          asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_UInt8 *)IN_ibyteout,
          &ibyteout_error_code);
   if (-1 == size_IN_buf_ibyteout) {
      testcompressuncompress_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      testcompressuncompress_recent_error.u.encodeerror = ibyteout_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_testcompressuncompress_samrh71tx
     (asn1SccPID,
      void *, size_t);

   vm_testcompressuncompress_samrh71tx
     (dest_pid,
      (void *)&IN_buf_ibyteout, (size_t)size_IN_buf_ibyteout);


  testcompressuncompress_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void testcompressuncompress_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void testcompressuncompress_get_sender(asn1SccPID *sender_pid);
  testcompressuncompress_get_sender(sender_pid);
}

void testcompressuncompress_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = testcompressuncompress_recent_error;
}

void testcompressuncompress_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    testcompressuncompress_RI_get_last_error(err);
}

