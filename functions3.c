/*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/

#include <stdio.h>

int getFileSize(FILE *fp){
  int len = -2;

  if (fp != NULL){
    if (fseek(fp, 0L, SEEK_END) == -1L){
      return -1;
    }

    len = ftell(fp);
    rewind(fp);
    return len;
  }

  return -1;
}
