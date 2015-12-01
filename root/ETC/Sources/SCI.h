/*
 * Serial Command Interpreter
 * Created by Josh Chadwick
 * Date: 29/11/2015
 * AUTHCODE 63
 */

#ifndef __SCI_H
#define __SCI_H

#include "MPI.h"

int checkStr(char input[], int length);
void parseETC(char str[]);
void parseGS(char str[]);
int strIs(char str[], char value[]);

#endif
