#ifndef utils_h
#define utils_h

void *in_TLB(unsigned char *physicalAdd);
unsigned char *allocate_malloc(int size); //function that allocates blocks of memory
// void *allocate_memories(unsigned char *size); //function that initializes the memories - NOT IN USE
int generateRandomBytes(int max, int min); //generates random bytes to fill the frame

char asciiContent(int max, int min); /*works with a flaw*/
void write_to_physical(unsigned char *physical);
void write_to_page(unsigned char *page_table, unsigned char *physical);
void user(unsigned char *physical, unsigned char *page_table);
int swap(unsigned char *physMem, unsigned char *pageT, unsigned int pfn, unsigned int vpn);

#endif