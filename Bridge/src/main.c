#include <stdio.h>

#include "base.h"
#include "imessage_sender.h"
#include "sms_sender.h"
#include "email_sender.h"
#include "abstract_message.h"
#include "findpwd_message.h"
#include "signup_message.h"

int main()
{
	SMSSender* smsSender = new (SMSSender);
	EmailSender* emailSender = new (EmailSender);

	FindPwdMessage* smsFindPwdMessage = new (FindPwdMessage, &smsSender->imessageSender);
	FindPwdMessage* emailFindPwdMessage = new (FindPwdMessage, &emailSender->imessageSender);
	SignupMessage* smsSignupMessage = new (SignupMessage, &smsSender->imessageSender);
	SignupMessage* emailSignupMessage = new (SignupMessage, &emailSender->imessageSender);

	smsFindPwdMessage->setContent(&smsFindPwdMessage->abstractMessage, "findpwd message");
	emailFindPwdMessage->setContent(&emailFindPwdMessage->abstractMessage, "findpwd message");
	smsSignupMessage->setContent(&smsSignupMessage->abstractMessage, "signup message");
	emailSignupMessage->setContent(&emailSignupMessage->abstractMessage, "signup message");

	smsFindPwdMessage->sendMessage(&smsFindPwdMessage->abstractMessage);
	emailFindPwdMessage->sendMessage(&emailFindPwdMessage->abstractMessage);
	smsSignupMessage->sendMessage(&smsSignupMessage->abstractMessage);
	emailSignupMessage->sendMessage(&emailSignupMessage->abstractMessage);

	delete (FindPwdMessage, smsFindPwdMessage);
	delete (FindPwdMessage, emailFindPwdMessage);
	delete (SignupMessage, smsSignupMessage);
	delete (SignupMessage, emailSignupMessage);

	delete (SMSSender, smsSender);
	delete (EmailSender, emailSender);

	return 0;
}
