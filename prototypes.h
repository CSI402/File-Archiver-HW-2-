#include <stdio.h>
#include <structs.h>


logLine_t* parseLine(char* line);
void deleteList(logList_t* l);
void printLines(logList_t* l);
logList_t* mergeLists(logList_t* resultList, logList_t* inList);
logList_t* sortList(logList_t* inList);