#ifndef testcompressuncompress_RunOnce_INCLUDED
#define testcompressuncompress_RunOnce_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadTestcompressuncompress_RunonceRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[TESTCOMPRESSUNCOMPRESS_RUNONCE_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task testcompressuncompress_runonce_job(rtems_task_argument unused);

#endif // testcompressuncompress_RunOnce_INCLUDED
