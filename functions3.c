/*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/

#include <stdio.h>

int getFileSize(FILE *fp){
  if (fp != NULL){
    if (fseek(fp, 0L, SEEK_END)){
      return -1;
    }

    rewind(fp);
    return ftell(fp);
  }

  return -1;
}
