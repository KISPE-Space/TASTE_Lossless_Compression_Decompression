#ifndef UARTOTHEREND_PROCESS_INCLUDE_GUARD_H
#define UARTOTHEREND_PROCESS_INCLUDE_GUARD_H

#include "dataview-uniq.h"
#include "uartotherend_datamodel.h"
enum Uartotherend_Branches {
   startup_transition, continuous_signals, branch_end
};

void runTransitionUartotherend(enum Uartotherend_Branches Id);
//// Startup
void uartotherend_startup();

//// Declaration Of Exported Inner Procedures

//// Input Signals
// Provided interface "samrh71tx"
void uartotherend_PI_samrh71tx(asn1SccT_UInt8 * iByteOut);
//// Output Signals
// Output signal "samrh71rx
void uartotherend_RI_samrh71rx(asn1SccT_UInt8 * iByteIn);
//// External Procedures
// Sync Required Interface "get_sender
void uartotherend_RI_get_sender(asn1SccPID * sender);
// Sync Required Interface "get_last_error
void uartotherend_RI_get_last_error(asn1SccT_Runtime_Error * err);
//// Timers

#endif /* UARTOTHEREND_PROCESS_INCLUDE_GUARD_H */