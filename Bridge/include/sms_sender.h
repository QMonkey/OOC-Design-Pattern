#ifndef SMS_SENDER_H
#define SMS_SENDER_H

#include "imessage_sender.h"

typedef struct _SMSSender SMSSender;

struct _SMSSender
{
	union
	{
		IMessageSender;
		IMessageSender imessageSender;
	};
};

extern SMSSender* SMSSender_construct(void*);
extern void SMSSender_destruct(SMSSender*);

#endif
