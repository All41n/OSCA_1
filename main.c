#include <stdio.h>
// #include "../lib/constants.h"
#include <stdlib.h>
#include <time.h>
#include "lib/utils.h"
#include "lib/constants.h"

/*
    Signed Vs Unsigned Char :
    http://www.differencebetween.info/difference-between-signed-char-and-unsigned-char
*/

int main(){

//I chose unsigned char because the range is 0-255 bytes.
// I also had some difficulties understanding and using unsigned short
    unsigned char *physical_memory = allocate_malloc(MAX_MEMPRY);
    unsigned char *page_table = allocate_malloc(PAGE_SIZE);
    //in_TLB(physical_memory);
    user(physical_memory,page_table);
    write_to_physical(physical_memory);
    write_to_page(page_table, physical_memory);

    free(physical_memory);
    free(page_table);

    
    return 0;
}