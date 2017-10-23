/*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(FILE *fp);

//Creates archive file from a set of individual files.
void archive(char** fileNames, int numFiles, char* archiveName){
  //Declare local variables
  int i; //counter
  FILE *archive = fopen(archiveName, "wb+"); //archive file pointer
  FILE *fp; //text files (temp for each loop iteration)
  char *fName; //to store file name
  int l; //to store length of file name
  int fSize; //to store size of file in bytes

  //If file does not open, print error and quit
  if (archive == NULL){
    fprintf(stderr, "Error: File %s cannot be opened to write\n", (char *)archiveName)\
;
    return;
  }

  //fwrite the number of files to the archive binary file (4-byte unsigned integer)
  fwrite((const void *)&numFiles, BYTE_SIZE_INT, 1, archive);

  //Loop through the files to be archived, file 0 through numFiles
  for(i = 0; i < numFiles; i++){
    //Set file name
    fName = fileNames[i];

    //If file does not open, print error and quit
    fp = fopen((const char *)fName, "r");
    if (fp == NULL){
      fprintf(stderr, "Error: File %s cannot be opened to read\n", fName);
      return;
    }

    //Set length of the file name
    l = strlen((const char *)fName);
    //fwrite the length of filename to archive binary file (1-byte unsigned char)
    fwrite((const void *)&l, BYTE_SIZE_CHAR, 1, archive);

    //fwrite the file name to archive binary file ((l+1)-bytes)
    fwrite((const void *)fName, (l+1), 1, archive);

    //Set size of file in bytes
    fSize = getFileSize(fp);
    //fwrite the size of the file in bytes to archive binary file (4-bytes)
    fwrite((const void *)&fSize, BYTE_SIZE_INT, 1, archive);

    //fwrite contents from file to archive binary file (fSize-bytes)
    fwrite((const void *)fp, fSize, 1, archive);
  }
}

void unarchive(char* archivefile) {
    FILE *archive = fopen(archiveFile, "rb"); //open archive file to be read
  // FILE *newFile = fopen(newFile, "w+"); //open new file to be written
  int numFile; //number of files

  if (archive == NULL){                 //check if archive file opened
    fprintf(stderr, "Error opening file.");
    exit(1); }                           //exit program
  /*if (newFile == NULL){                  //check if new file opened
    fprintf(stderr, "Error creating file.");
    exit(1); }  */                         //exit program

  fread(&numFile, 4, 1, archive);         //get number of files in archive

  
}
