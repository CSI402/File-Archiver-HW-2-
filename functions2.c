/*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/
#include "constants.h"
#include "prototypes2.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(FILE *fp);

void printFileInfo(char* archiveFile){
   int numFiles; // Number of Files
   int archiveLength; //Size of archive file
   int numBytes; //Size of individual size
   char lenFileName;
   char *fileContents;
   char *fileName = malloc(sizeof(char *));
   FILE *archive = fopen(archiveFile, "rb");

   if (archive == NULL){
     fprintf(stderr, "Error: File %s cannot be opened to read\n", archiveFile);
    return;
    }

  //Gets the Length of the archive
   archiveLength = getFileSize(archive);
   printf("Total Size of Archive: %d\n", archiveLength);

   //Gets the number of files in the archive
   fread((void *)&numFiles, BYTE_SIZE_INT, 1, archive);
   printf("Number of Files: %d\n", numFiles);
   int i;
   for (i = 0; i < numFiles; i++){
  //fread the file name of each file (lenFileName + 1)
    fread((void *)&lenFileName, BYTE_SIZE_CHAR, 1, archive);
    fread(fileName, (lenFileName + 1), 1, archive);
    printf("File name: %s ", fileName);
    //Get the size of the file
    fread(&numBytes, BYTE_SIZE_INT, 1, archive);
    printf("File Size: %d\n", numBytes);
    fileContents = (char *)malloc(sizeof(char)*numBytes);
    //fread the contents of each file (numBytes bytes)
    fread(fileContents, numBytes, 1, archive);
    free(fileContents);
    }
fclose(archive);
  }



void isDamaged(char **fileNames, int numFiles , char* archiveFile){

  int numberOfFiles; //Stores the number of files in the archive file
  char lenFileName;
  char *fileName = malloc(sizeof(char *));
  int numBytes;
  char *fileContents;
  int fSize; //to store size of file in bytes
  char *fName;
  FILE *fp; //temp file pointer
  FILE *archive = fopen(archiveFile, "rb+");
  int counter1;
  int counter2;

  fread(&numberOfFiles, BYTE_SIZE_INT, 1, archive);
  if(numberOfFiles != numFiles){
    fprintf(stderr, "Error: Missing a File" );
  }

  int i;
  for (i = 0; i < (int)numFiles; i++){

    fName = fileNames[i];
    //If file does not open, print error and quit
    fp = fopen((const char *)fName, "r");
    if (fp == NULL){
      fprintf(stderr, "Error: File %s cannot be opened to read\n", fName);
      return;
    }

    fSize = getFileSize(fp);

    //fread the length of each file name (1-byte unsigned char)
    fread((void *)&lenFileName, BYTE_SIZE_CHAR, 1, archive);

    //fread the file name of each file (lenFileName + 1)
    fread(fileName, (lenFileName + 1), 1, archive);

    //fread the number of bytes of the contents of each file (4-byte unsigned integer)
    fread(&numBytes, BYTE_SIZE_INT, 1, archive);

    //allocate memory for fileContents
    fileContents = (char *)malloc(sizeof(char)*numBytes);

    //fread the contents of each file (numBytes bytes)
    fread(fileContents, numBytes, 1, archive);

    //Compare file size to the file size listed in archive file
    if(fSize != numBytes){
      fprintf(stderr, "Archive is Missing %d Bytes", fSize);
    }
    counter1 += fSize; //cumlative bytes of files
    counter2 += numBytes; //Cumulative bytes of files in archive

  }
  if(counter1 == counter2){
    printf("%s\n", "Archive Verified");
  }


}
