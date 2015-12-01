/*
 * Message Passing Interface
 * Created by Josh Chadwick
 * Date: 29/11/2015
 * AUTHCODE 63
 */

#include "string.h"

#include "MPI.h"

void initialiseMPI(char mod[]) {
	strcpy(moduleName, mod);
	moduleState = 0;
	ackWait = 0;
	strcpy(ackWaitMsg, "");
}

void sendMsg(char msg[]) {
	strcpy(sendingMsg, msg);
	strcat(sendingMsg, "\n");
	ackWait = 1;
	while (ackWait == 1) {
		//send sendingMsg
		//wait 1 second
		if (strIs(msg, "ACK")) {
			ackWait = 0;
		}
	}
	//msg successfully sent
}
