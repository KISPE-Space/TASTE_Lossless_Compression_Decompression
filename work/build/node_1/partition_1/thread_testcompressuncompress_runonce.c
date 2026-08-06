#include "thread_testcompressuncompress_runonce.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"
#include <Hal.h>
#include <ThreadsCommon.h>

#include "partition_1_interface.h"

extern rtems_id testcompressuncompress_runonce_Global_Queue;

rtems_task testcompressuncompress_runonce_job(rtems_task_argument unused)
{
    const bool createCyclicRequestStatus = ThreadsCommon_CreateCyclicRequest( 5000 * NANOSECONDS_IN_MILLISECOND,
                                                                              0 * NANOSECONDS_IN_MILLISECOND,
                                                                             testcompressuncompress_runonce_Global_Queue,
                                                                             sizeof(struct CyclicInterfaceEmptyRequestData));
    assert(createCyclicRequestStatus);

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadTestcompressuncompress_RunonceRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(testcompressuncompress_runonce_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            testcompressuncompress_runonce_sender_pid = (asn1SccPID)request.m_sender_pid;

            ThreadsCommon_ProcessRequest((char*)request.m_data, request.m_length,
                                         (void (*)(const char *,size_t))call_testcompressuncompress_runonce, testcompressuncompress_runonce);
        }
    }
}
