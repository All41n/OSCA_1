#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "constants.h"

/*
    Ascii Integer to Char Conversion :
    https://stackoverflow.com/questions/6660145/convert-ascii-number-to-ascii-character-in-c
*/
/*
    Generating Randoms :
    https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
*/
/*
    Video Explaining TLB :
    https://www.youtube.com/watch?v=95QpHJX55bM
*/
/*
    https://2019-moodle.dkit.ie/pluginfile.php/567340/mod_resource/content/2/32bit-address-parts.c
    https://2019-moodle.dkit.ie/pluginfile.php/567342/mod_resource/content/2/32bit-address-parts-reconstruct.c
*/
////
void user(unsigned char *physical, unsigned char *page_table)
{
    while (1) //while not -1 keeps the input working
    {
        printf("Input any Hexadecimal Address: ");
        scanf("%04x", &user_input);//allow only 4 characters 

        //get the offset
        offset_mask = OFFSET_MASK;
        offset = user_input & offset_mask; //combine both the first 8 bit offset to the offset mask

        //get virtual page number by shifting the extracted offset and combining it with the 8 bit offset
        unsigned int virtual_page = user_input >> OFFSET_LAST; // the inputted hexadecimal address is shifted 8 bits to the right
        //physical frame number, getting address from page table
        unsigned int physical_add = physical[virtual_page];

        printf("Extracted Offset : 0x%x\n", offset);
        printf("\nVirtual Page Number is 0x%x\n", virtual_page);
        printf("\nFrame Number is 0x%x\n", physical_add);

        if (physical[virtual_page + FRAME_SIZE] == 0) // if address does not match any proceed to the swap function
        {
            swap(physical, page_table, physical_add, virtual_page);
        }
        else // show content and what was inputted
        {
            //shows the content
            unsigned int inputtedAddress = physical_add << OFFSET_LAST; // shift bits to the left
            unsigned char content = physical[inputtedAddress];
            printf("\t\tPhysical Address: 0x%x\n", inputtedAddress);
            printf("\t\tContent: %c\n", content);
        }
    }
}

void write_to_physical(unsigned char *physical)
{
    physicalMemory = fopen("./data/physical_memory2.txt", "w");
    fprintf(physicalMemory, "Address\t\t\t\tFrame/Hex\t\t\t\tContent\n");
    srand(time(NULL));
    randomBytes = generateRandomBytes(Max_Byte, Min_Byte);

    /*
        Frame size = 256

    */
    // int randomiseFrames2 = (rand() % (80-2-randomBytes/256))+8;
    int randomiseFrames2 = (rand() % (256 - 1)) + 1;
    int currentFrame = 0;
    int currentAddress = 0;

    for (int i = 0; i < MAX_MEMPRY; ++i)
    {
        asciiCharacters = rand() % (127 - 33) + 33;
        /*
        This for loop is needed to divide the address once its full
        This splits the random bytes once it the address is equals to the frame size

        The frame table doesnt work properly, all of the frames are 0;
        Even with the this for loop, the frames doesnt go all the way to 255
        */
        if (currentAddress == PAGE_SIZE)
        {
            currentFrame++;
            currentAddress = 1;
        }

        if (i >= randomiseFrames2 && i < (PAGE_SIZE + randomBytes))
        {
            fprintf(physicalMemory, "0x%02x\t\t\t%d\t\t\t\t%c\n", i, currentFrame, asciiCharacters);
        }
        else
        {
            physical[i] = ' '; //leave the physical memory empty
            //if a fprintf was used instead of the array, it would wipe the text file
        }
        currentAddress++; // increment the currentAddress
    }

    fclose(physicalMemory);
}

void write_to_page(unsigned char *page_table, unsigned char *physicalAdd)
{

    pageTable = fopen("./data/page_table.txt", "w");
    fprintf(pageTable, "Page\t\tPage Entry\t\tContent\n");

    for (int i = 0; i < PAGE_SIZE; i++)
    {
        char content = (rand() % (127 - 33)) + 33;
        fprintf(pageTable, "0x%02x\t\t0x%02x\t\t%c\n", i, (int)i/ 256, page_table[i]); // without the (int) the while loops keeps looping infinitely
    }

    fclose(pageTable);
}

//Swapping
int swap(unsigned char *physMem, unsigned char *pageT, unsigned int pfn, unsigned int vpn)
{
    int tinyMemory = PAGE_SIZE; // the swap space has a total of 512 bytes
    printf("\nSWAPPING \n");

    for (int i = tinyMemory; i < MAX_MEMPRY; i++)
    {
        if (physMem[i] == ' ') // physicalMem is empty
        {
            //iterate through it 256 times
            for (int x = 0; x < FRAME_SIZE; x++)
            {
                //physicalMem malloc will then take the combined values of i and j.
                //so if i in the physical memory is found along with j
                // the values are then mapped to the page table
                physMem[i + x] = pageT[pfn * 256 + x]; // the physicalMem is equals to physical
                                                        // frame is multiplied by 256 + the value of x
                                                        //
            }
            i = MAX_MEMPRY;
        }
    }
    physMem[vpn + 256] = 0x01;
    return 0;
}

unsigned char *allocate_malloc(int size)
{
    unsigned char *allocating;
    allocating = malloc(size * sizeof(unsigned char));

    return allocating;
}

int generateRandomBytes(int max, int min)
{
    //generate random process to insert into the process
    srand(time(NULL));

    int random;
    random = rand() % (max - min) - min;

    return random;
}

// void initialize_size(unsigned char *holder, int size)
// {

//     for (int i = 0; i < size; i++)
//     {
//         holder[i] = -1;
//     }
// }

/*
    function to generate a single random byte 
    between 2048 and 20480
*/
/*
    This function was supposed to return ascii characters
    but it only filled the frames with the same ascii characters.
*/
// int asciiContent(int max, int min){
//     srand(time(NULL));
//     int asciiChars;
//     asciiChars = (rand() % (126 - 33)) + 33;
//     return asciiChars;
// }