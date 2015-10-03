#include "base.h"
#include "qrcode_state_machine.h"

int main()
{
	QRCodeStateMachine *stateMachine = new(QRCodeStateMachine);

	stateMachine->getQRCode(&stateMachine->iqrcodeState);
	stateMachine->scanQRCode(&stateMachine->iqrcodeState);
	stateMachine->auth(&stateMachine->iqrcodeState);
	stateMachine->spend(&stateMachine->iqrcodeState);

	stateMachine->getQRCode(&stateMachine->iqrcodeState);
	stateMachine->scanQRCode(&stateMachine->iqrcodeState);
	stateMachine->cancel(&stateMachine->iqrcodeState);

	delete(QRCodeStateMachine, stateMachine);

	return 0;
}
