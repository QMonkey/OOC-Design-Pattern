#include <stdio.h>

#include "base.h"
#include "qrcode_state_machine.h"
#include "abstract_qrcode_state.h"
#include "noqrcode_state.h"

static void NoQRCodeState_getQRCode(IQRCodeState*);

NoQRCodeState* constructNoQRCodeState(void *addr, QRCodeStateMachine *stateMachine)
{
	if(addr == NULL)
	{
		return NULL;
	}
	
	NoQRCodeState *noqrcodeState = addr;
	constructAbstractQRCodeState(&noqrcodeState->abstractQRCodeState, stateMachine);

	noqrcodeState->getQRCode = NoQRCodeState_getQRCode;

	return noqrcodeState;
}

void destructNoQRCodeState(NoQRCodeState *noqrcodeState)
{
	destructAbstractQRCodeState(&noqrcodeState->abstractQRCodeState);
}

void NoQRCodeState_getQRCode(IQRCodeState *iqrcodeState)
{
	NoQRCodeState *noqrcodeState = container_of(iqrcodeState, NoQRCodeState, iqrcodeState);
	noqrcodeState->stateMachine->setState(noqrcodeState->stateMachine, VALID);
	printf("QRCode state from noqrcode to valid.\n");
}
