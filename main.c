#include <stdio.h>
#include <string.h>
#include "functions.c"
#include "prototypes.h"
#include <structs.h>

#define MAX_LEN 142

typedef struct logLine{
   char level[20];
   char timeStamp[20];
   char message[100];
 // struct logLine *next;
} logLine_t;

 typedef struct logList {
   ogLine_t line;
   struct logList *next;
} logList_t;






int main(int argc, char** argv){
  if (argc > 2){
    fprintf(stderr, "%s\n", "Error: Parameter number may not exceed one");
  }

  FILE *file1 = fopen("test.log", "r");
  FILE *file2 = fopen("test2.log", "r");


  if (file1 == NULL){
    printf("Error: File 'test.log' could not be opened.\n");
    return 0;
  }
  if (file2 == NULL){
    printf("Error: File 'test2.log' could not be opened.\n");
    return 0;
  }
  


  }





