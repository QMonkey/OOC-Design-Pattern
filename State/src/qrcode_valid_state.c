#include <stdio.h>

#include "base.h"
#include "qrcode_state_machine.h"
#include "abstract_qrcode_state.h"
#include "qrcode_valid_state.h"

static void QRCodeValidState_scanQRCode(IQRCodeState*);

QRCodeValidState* QRCodeValidState_construct(void* addr, QRCodeStateMachine* stateMachine)
{
	if (addr == NULL)
	{
		return NULL;
	}

	QRCodeValidState* qrcodeValidState = addr;
	AbstractQRCodeState_construct(&qrcodeValidState->abstractQRCodeState, stateMachine);

	qrcodeValidState->scanQRCode = QRCodeValidState_scanQRCode;

	return qrcodeValidState;
}

void QRCodeValidState_destruct(QRCodeValidState* qrcodeValidState)
{
	AbstractQRCodeState_destruct(&qrcodeValidState->abstractQRCodeState);
}

void QRCodeValidState_scanQRCode(IQRCodeState* iqrcodeState)
{
	QRCodeValidState* qrcodeValidState = container_of(iqrcodeState, QRCodeValidState, iqrcodeState);
	qrcodeValidState->stateMachine->setState(qrcodeValidState->stateMachine, AUTHORIZING);
	printf("QRCode state from valid to authorizing.\n");
}
