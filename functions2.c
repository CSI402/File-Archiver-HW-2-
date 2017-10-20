/*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/
#include "constants.h"

//use stats 
void printFileInfo(char* archiveFile){

FILE *fp = fopen(archiveFile,"rb");
long siz;
char *result;
if (fp == NULL)
return NULL;

fseek(f,0,SEEK_END);
sz = ftell(fp);
fseek(f,0,SEEK_SET);
result = calloc(1,siz+1);
if (result) {
fread(result,1,siz,f);
}
fclose(f);
return result;
}




void isDamaged(char **fileNames, int numFiles , char* archiveFile){

}
/*
int tryOpen(FILE* fp){

	if(fopen(fp, "r") )
}*/