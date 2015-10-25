#ifndef SIGNUP_MESSAGE_H
#define SIGNUP_MESSAGE_H

#include "abstract_message.h"

typedef struct _SignupMessage SignupMessage;

struct _SignupMessage
{
	union
	{
		AbstractMessage;
		AbstractMessage abstractMessage;
	};
};

extern SignupMessage* SignupMessage_construct(void*, IMessageSender*);
extern void SignupMessage_destruct(SignupMessage*);

#endif
