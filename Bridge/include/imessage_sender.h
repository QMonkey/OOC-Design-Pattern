#ifndef IMESSAGE_SENDER_H
#define IMESSAGE_SENDER_H

typedef struct _IMessageSender IMessageSender;

struct _IMessageSender
{
	void (*send)(IMessageSender*, char*);
};

#endif
