 /*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/
#include "constants.h"
#include <stdio.h>
//#define BYTE_SIZE 4
//Creates archive file from a set of individual files.
 void archive(char** fileNames, int numFiles, char* archiveName){
 	int i;
 	FILE* fp = fopen(archiveName, "w+");
 	//try to open(create) archive file to w+
 	
 	fwrite(&numFiles, BYTE_SIZE, 1, fp);
 	//fwrite to binary file the N(numfiles 4 Bytes)
 	for(i=0; i<numFiles; i++){
 		int length = strlen(*fileNames[i]);
 		fwrite(&length, BYTE_SIZE, 1, fp);

 	}

 }

 void unarchive(char* archivefile) {


 }