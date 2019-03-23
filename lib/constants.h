#ifndef CONSTANTSH
#define CONSTANTSH

#include <stdio.h>
#include <stdlib.h>

#define Max_Byte 20480   // max random byte
#define Min_Byte 2048    // min random byte
#define PAGE_SIZE 512    //page size
#define MAX_MEMPRY 65536 // PHYSICAL MEMORY
#define FRAME_NUMBER 256 // frame number
#define FRAME_SIZE 256   // frames size
#define MAX_ASCII 126 // max ascii character
#define MIN_ASCII 33 // min ascii character
#define PAGE_ENTRIES 2 // each page entries are 2 bytes each
#define OFFSET_LAST 8 //8 bit mask
#define OFFSET_MASK 0x00FF // mask offet

FILE *physicalMemory, *pageTable;
int frameCount;
int randomBytes;
char asciiCharacters;
int randomiseFrames;
unsigned int offset_mask;
unsigned int offset;
unsigned int page_table_size;
unsigned int user_input;

#endif