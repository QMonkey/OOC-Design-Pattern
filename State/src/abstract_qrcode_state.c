#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "abstract_qrcode_state.h"

static AbstractQRCodeState_unsupportedOperation(IQRCodeState*);

void constructAbstractQRCodeState(void *addr, QRCodeStateMachine *stateMachine)
{
	if(addr == NULL)
	{
		return NULL;
	}

	AbstractQRCodeState *abstractQRCodeState = addr;
	abstractQRCodeState->stateMachine = stateMachine;

	abstractQRCodeState->iqrcodeState.getQRCode = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->iqrcodeState.scanQRCode = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->iqrcodeState.auth = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->iqrcodeState.cancel = AbstractQRCodeState_unsupportedOperation;
}

void destructAbstractQRCodeState(AbstractQRCodeState *abstractQRCodeState)
{
}

AbstractQRCodeState_operation(IQRCodeState*)
{
	fprintf(stderr, "UnsupportedOperation\n");
	abort();
}
