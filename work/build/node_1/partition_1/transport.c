#include "transport.h"

#include <rtems.h>
#include <interfaces_info.h>
#include <ThreadsCommon.h>

// Sporadic required
void deliver_to_uartotherend_samrh71tx(
   const asn1SccPID sender_pid,
   const uint8_t* const data,
   const size_t length)
{
    Broker_deliver_request(
            INTERFACE_UARTOTHEREND_SAMRH71TX,
            sender_pid,
            data,
            length);
}

// Sporadic provided


#include "thread_testcompressuncompress_samrh71rx.h"

#include <string.h>

void deliver_to_testcompressuncompress_samrh71rx(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern rtems_id testcompressuncompress_samrh71rx_Global_Queue;

    struct ThreadTestcompressuncompress_Samrh71rxRequest request = {0};
    if(length > 0)
    {
        memcpy(request.m_data, data, length);
    }
    request.m_length = length;
    request.m_sender_pid = (uint32_t)sender_pid;

    ThreadsCommon_SendRequest(&request,
                              sizeof(struct ThreadTestcompressuncompress_Samrh71rxRequest),
                              testcompressuncompress_samrh71rx_Global_Queue,
                              testcompressuncompress_samrh71rx);
}



void initialize_transport()
{
    interface_to_deliver_function[INTERFACE_TESTCOMPRESSUNCOMPRESS_SAMRH71RX] = &deliver_to_testcompressuncompress_samrh71rx;
}
