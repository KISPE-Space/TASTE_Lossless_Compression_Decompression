//// Includes
#include "dataview-uniq.h"
#include "uartotherend_datamodel.h"
#include "uartotherend.h"
//// SDL Constants
[[maybe_unused]]
static const asn1SccPID self = asn1SccPID_uartotherend;

//// Aliases

//// Context
static asn1SccUartotherend_Context ctxt = {0};
//// State Aggregations Start functions
//// Declaration Of Inner Procedures

//// Startup
void CInituartotherend()
{
   ctxt.sender = asn1SccPID_env;
   ctxt.offspring = asn1SccPID_env;

   runTransitionUartotherend(startup_transition);
   ctxt.init_done = true;
}

// Required To Work With TASTE's Wrappers
void uartotherend_startup()
{
   CInituartotherend();
}

//// Input Signals
void uartotherend_PI_samrh71tx(asn1SccT_UInt8 * iByteOut)
{
   runTransitionUartotherend(continuous_signals);
}

//// Output Signals
// Required interface "samrh71rx"
//// Definition Of Inner Procedures

// CONNECTION Startup_Transition
static enum Uartotherend_Branches branch_startup_transition(void)
{
   // NEXT_STATE Wait (6,15) at None, None
   ctxt.state = asn1SccUartotherend_States_wait;
   return continuous_signals;
}

//// Definition Of Run Transition
void runTransitionUartotherend(enum Uartotherend_Branches Id)
{
   enum Uartotherend_Branches trId = Id;
   while (trId != branch_end)
   {
      switch (trId)
      {
         case startup_transition: trId = branch_startup_transition(); break;
         case continuous_signals: trId = branch_end; break;
         default: trId = branch_end; break;
      }
   }
}

//// Current State To String
char* uartotherend_state(void)
{
   return "Not_supported_in_C__Use_the_Ada_backend";
}
