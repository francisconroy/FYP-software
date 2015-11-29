/*
 * Message Passing Interface
 * Created by Josh Chadwick
 * Date: 29/11/2015
 * AUTHCODE 63
 */

#ifndef __MPI_H
#define __MPI_H

#include "SCI.h"

#define MSG_SIZE 20

char moduleName[4];
int moduleState;
int ackWait;
char ackWaitMsg[MSG_SIZE];
char sendingMsg[MSG_SIZE];
char lastReceivedMsg[MSG_SIZE];

void initialiseMPI(char mod[4]);
void sendMsg(char msg[]);

#endif
