#ifndef IQRCODE_STATE_H
#define IQRCODE_STATE_H

typedef struct _IQRCodeState IQRCodeState;

struct _IQRCodeState
{
	void (*getQRCode)(IQRCodeState*);
	void (*scanQRCode)(IQRCodeState*);
	void (*auth)(IQRCodeState*);
	void (*cancel)(IQRCodeState*);
	void (*spend)(IQRCodeState*);
};

#endif
