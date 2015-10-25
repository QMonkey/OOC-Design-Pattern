#include <stdio.h>
#include <stdlib.h>

#include "abstract_qrcode_state.h"

static void AbstractQRCodeState_unsupportedOperation(IQRCodeState*);

void AbstractQRCodeState_construct(void* addr, QRCodeStateMachine* stateMachine)
{
	if (addr == NULL)
	{
		return NULL;
	}

	AbstractQRCodeState* abstractQRCodeState = addr;
	abstractQRCodeState->stateMachine = stateMachine;

	abstractQRCodeState->getQRCode = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->scanQRCode = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->auth = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->cancel = AbstractQRCodeState_unsupportedOperation;
	abstractQRCodeState->spend = AbstractQRCodeState_unsupportedOperation;
}

void AbstractQRCodeState_destruct(AbstractQRCodeState* abstractQRCodeState)
{
}

void AbstractQRCodeState_unsupportedOperation(IQRCodeState* iqrcodeState)
{
	fprintf(stderr, "Unsupported operation in current qrcode state.\n");
	abort();
}
