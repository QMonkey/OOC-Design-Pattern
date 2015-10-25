#ifndef ABSTRACT_MESSAGE_H
#define ABSTRACT_MESSAGE_H

#include "imessage_sender.h"

typedef struct _AbstractMessage AbstractMessage;

struct _AbstractMessage
{
	char* content;
	IMessageSender* sender;

	char* (*getContent)(AbstractMessage*);
	void (*setContent)(AbstractMessage*, char*);
	void (*sendMessage)(AbstractMessage*);
};

extern void AbstractMessage_construct(void*, IMessageSender*);
extern void AbstractMessage_destruct(AbstractMessage*);

#endif
