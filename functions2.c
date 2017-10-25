/*
Daniel Hug dhug@albany.edu: Recoder
Alana Ruth Aruth@albany.edu : Monitor
Jessica Kanczura jKanczura@albany.edu : Leader
*/
#include "constants.h"
#include <sys/stat.h>
#include <stdio.h>

int getFilesize(FILE *fp);

size_t getBinaryFileSize(const char* filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;   
}

//use stats 
void printFileInfo(char* archiveFile){
   int numFiles; // Number of Files
   int archiveLength; //Size of archive file
   int fileSize; //Size of individual size
   FILE *archive = fopen(archiveFile,"rb");

   //Gets the Length of the archive
   archiveLength = getBinaryFileSize(&archive); 
   printf("Total Size of Archive: %s\n", archive);
   //Gets the number of files in the archive
   fread(&numFiles, BYTE_SIZE_INT, 1, archiveFile); 
   printf("There are %s files in the archive\n", numFile);
   int i;
  for (i = 0; i < numFile; i++){
    //fread the file name of each file (lenFileName + 1)
    fread(fileName, (lenFileName + 1), 1, archive);
    //Get the size of the file
    fread(&fileSize, BYTE_SIZE_INT, 1, archive);
    printf("File Name: %s File Size: %s\n", fileName, fileSize);

}
}



 void isDamaged(char **fileNames, int numFiles , char* archiveFile){

 	int numberOfFiles; //Stores the number of files in the archive file
 	int lenFileName; 
 	int fileName;
 	int numBytes;
 	int fileContents;
 	int fSize; //to store size of file in bytes
 	int fName;
 	FILE *fp; //temp file pointer
 	FILE *archive = fopen(archiveName, "rb+");
 	int counter1;
 	int counter2;

 	fread(&numberOfFiles, BYTE_SIZE_INT, 1, archive);
 	if(numberOfFiles != numFiles){
 		printf(stderr, "Error: Missing a File" );
 	}

 	int i;
  for (i = 0; i < numFile; i++){

  	fName = fileNames[i];
  	  //If file does not open, print error and quit
    fp = fopen((const char *)fName, "r");
    if (fp == NULL){
      fprintf(stderr, "Error: File %s cannot be opened to read\n", fName);
      return;
    }

  	fSize = getFileSize(fp);
    //fread the length of each file name (1-byte unsigned char)
    fread(&lenFileName, BYTE_SIZE_CHAR, 1, archive);
    //fread the file name of each file (lenFileName + 1)
    fread(fileName, (lenFileName + 1), 1, archive);
    //fread the number of bytes of the contents of each file (4-byte unsigned integer)
    fread(&numBytes, BYTE_SIZE_INT, 1, archive);
    //fread the contents of each file (numBytes bytes)
    fread(fileContents, numBytes, 1, archive);

    //Compare file size to the file size listed in archive file
    if(fSize != numBytes){
    	printf(stderr, "Archive is Missing %d Bytes", fSize);
    }
    counter1 += fSize; //cumlative bytes of files
    counter2 += numBytes; //Cumulative bytes of files in archive

    }
    if(counter1 == counter2){
    	printf("%s\n", "Archive Verified");
    }


}










