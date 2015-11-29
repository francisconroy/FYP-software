/*
 * Serial Command Interpreter
 * Created by Josh Chadwick
 * Date: 29/11/2015
 * AUTHCODE 63
 */

#include "string.h"

#include "SCI.h"

int checkStr(char input[], int length) {
	char str[20];
	if (input[length - 1] == '\n') {
		strncpy(str, input, length - 1);
		if (strIs(moduleName, "ETC")) {
			parseETC(str);
		} else if (strIs(moduleName, "GS")) {
			parseGS(str);
		} else {
			return 0;
		}
		return 1;
	} else {
		return 0;
	}
}

void parseETC(char str[]) {
	if (strIs(str, "GS_online")) {
		sendMsg("ACK");
	} else if (strIs(str, "CAN_str?")) {
		sendMsg("ACK");
		sendMsg("YorN"); // TODO fix
	} else if (strIs(str, "ACK")) {
		ackWait = 0;
		if (!strIs(ackWaitMsg, "")) {
			sendMsg(ackWaitMsg);
			strcpy(ackWaitMsg, "");
		}
	}
}
void parseGS(char str[]) {
	if (strIs(str, "GS_mod_online?")) {
		sendMsg("ACK");
		strcpy(ackWaitMsg, "CAN_str?");
		sendMsg("GS_online");
	} else if (strIs(str, "YorN")) {
		// TODO remove
		sendMsg("ACK");
	} else if (strIs(str, "Y")) {
		// TODO fix
		sendMsg("ACK");
	} else if (strIs(str, "N")) {
		// TODO fix
		sendMsg("ACK");
	} else if (strIs(str, "ACK")) {
		ackWait = 0;
		if (!strIs(ackWaitMsg, "")) {
			sendMsg(ackWaitMsg);
			strcpy(ackWaitMsg, "");
		}
	}
}

int strIs(char str[], char value[]) {
	return strcmp(str, value) == 0;
}
