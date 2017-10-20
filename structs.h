#ifndef __MYLIB_H__
#define __MYLIB_H__

#include <stdio.h>



extern typedef struct logLine{
  extern char level[20];
  extern char timeStamp[20];
  extern char message[100];
 // struct logLine *next;
} logLine_t;

extern typedef struct logList {
  extern ogLine_t line;
  extern struct logList *next;
} logList_t;

#endif