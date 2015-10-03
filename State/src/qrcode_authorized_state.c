#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "qrcode_state_machine.h"
#include "abstract_qrcode_state.h"
#include "qrcode_authorized_state.h"

static void QRCodeAuthorizedState_spend(IQRCodeState*);

QRCodeAuthorizedState* constructQRCodeAuthorizedState(void *addr, QRCodeStateMachine *stateMachine)
{
	if(addr == NULL)
	{
		return NULL;
	}

	QRCodeAuthorizedState *qrcodeAuthorizedState = addr;
	constructAbstractQRCodeState(&qrcodeAuthorizedState->abstractQRCodeState, stateMachine);

	qrcodeAuthorizedState->spend = QRCodeAuthorizedState_spend;

	return qrcodeAuthorizedState;
}

void destructQRCodeAuthorizedState(QRCodeAuthorizedState *qrcodeAuthorizedState)
{
	destructAbstractQRCodeState(&qrcodeAuthorizedState->abstractQRCodeState);
}

void QRCodeAuthorizedState_spend(IQRCodeState *iqrcodeState)
{
	QRCodeAuthorizedState *qrcodeAuthorizedState = container_of(iqrcodeState, QRCodeAuthorizedState, iqrcodeState);
	qrcodeAuthorizedState->stateMachine->setState(qrcodeAuthorizedState->stateMachine, NOQRCODE);
	printf("QRCode state from authorized to noqrcode.\n");
}
