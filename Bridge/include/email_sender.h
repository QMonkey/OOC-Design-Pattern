#ifndef EMAIL_SENDER_H
#define EMAIL_SENDER_H

#include "imessage_sender.h"

typedef struct _EmailSender EmailSender;

struct _EmailSender
{
	union
	{
		IMessageSender;
		IMessageSender imessageSender;
	};
};

extern EmailSender* EmailSender_construct(void*);
extern void EmailSender_destruct(EmailSender*);

#endif
