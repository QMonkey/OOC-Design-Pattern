#include <stdio.h>

#include "base.h"
#include "qrcode_state_machine.h"
#include "abstract_qrcode_state.h"
#include "qrcode_authorizing_state.h"

static void QRCodeAuthorizingState_auth(IQRCodeState*);
static void QRCodeAuthorizingState_cancel(IQRCodeState*);

QRCodeAuthorizingState* constructQRCodeAuthorizingState(void *addr, QRCodeStateMachine *stateMachine)
{
	if(addr == NULL)
	{
		return NULL;
	}

	QRCodeAuthorizingState *qrcodeAuthorizingState = addr;
	constructAbstractQRCodeState(&qrcodeAuthorizingState->abstractQRCodeState, stateMachine);

	qrcodeAuthorizingState->auth = QRCodeAuthorizingState_auth;
	qrcodeAuthorizingState->cancel = QRCodeAuthorizingState_cancel;

	return qrcodeAuthorizingState;
}

void destructQRCodeAuthorizingState(QRCodeAuthorizingState *qrcodeAuthorizingState)
{
	destructAbstractQRCodeState(&qrcodeAuthorizingState->abstractQRCodeState);
}

void QRCodeAuthorizingState_auth(IQRCodeState *iqrcodeState)
{
	QRCodeAuthorizingState *qrcodeAuthorizingState = container_of(iqrcodeState, QRCodeAuthorizingState, iqrcodeState);
	qrcodeAuthorizingState->stateMachine->setState(qrcodeAuthorizingState->stateMachine, AUTHORIZED);
	printf("QRCode state from authorizing to authorized.\n");
}

void QRCodeAuthorizingState_cancel(IQRCodeState *iqrcodeState)
{
	QRCodeAuthorizingState *qrcodeAuthorizingState = container_of(iqrcodeState, QRCodeAuthorizingState, iqrcodeState);
	qrcodeAuthorizingState->stateMachine->setState(qrcodeAuthorizingState->stateMachine, NOQRCODE);
	printf("QRCode state from authorizing to noqrcode.\n");
}
