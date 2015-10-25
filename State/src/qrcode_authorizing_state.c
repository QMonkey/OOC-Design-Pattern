#include <stdio.h>

#include "base.h"
#include "qrcode_state_machine.h"
#include "abstract_qrcode_state.h"
#include "qrcode_authorizing_state.h"

static void QRCodeAuthorizingState_auth(IQRCodeState*);
static void QRCodeAuthorizingState_cancel(IQRCodeState*);

QRCodeAuthorizingState* QRCodeAuthorizingState_construct(void* addr, QRCodeStateMachine* stateMachine)
{
	if (addr == NULL)
	{
		return NULL;
	}

	QRCodeAuthorizingState* qrcodeAuthorizingState = addr;
	AbstractQRCodeState_construct(&qrcodeAuthorizingState->abstractQRCodeState, stateMachine);

	qrcodeAuthorizingState->auth = QRCodeAuthorizingState_auth;
	qrcodeAuthorizingState->cancel = QRCodeAuthorizingState_cancel;

	return qrcodeAuthorizingState;
}

void QRCodeAuthorizingState_destruct(QRCodeAuthorizingState* qrcodeAuthorizingState)
{
	AbstractQRCodeState_destruct(&qrcodeAuthorizingState->abstractQRCodeState);
}

void QRCodeAuthorizingState_auth(IQRCodeState* iqrcodeState)
{
	QRCodeAuthorizingState* qrcodeAuthorizingState = container_of(iqrcodeState, QRCodeAuthorizingState, iqrcodeState);
	qrcodeAuthorizingState->stateMachine->setState(qrcodeAuthorizingState->stateMachine, AUTHORIZED);
	printf("QRCode state from authorizing to authorized.\n");
}

void QRCodeAuthorizingState_cancel(IQRCodeState* iqrcodeState)
{
	QRCodeAuthorizingState* qrcodeAuthorizingState = container_of(iqrcodeState, QRCodeAuthorizingState, iqrcodeState);
	qrcodeAuthorizingState->stateMachine->setState(qrcodeAuthorizingState->stateMachine, NOQRCODE);
	printf("QRCode state from authorizing to noqrcode.\n");
}
