# OSCA_1
Repo for CA1 of Operating System
OS_Memory_Virtualization

Objectives In this project students are required to create an application which simulates the structures and processes used by both an Operating System and a Central Processing Unit to implement memory virtualization for a 16 bit virtual address space which employs a page size of 256 bytes. The simulated system must make use of a single-level linear page table which is stored in the system’s simulated physical memory. Additional requirements for how your solution must operate are listed later in this document (note that you are only required to simulate the page table for a single process).

SPECIFICATIONS:

•Allocate a block of memory sufficient to store bytes for the full system address space (note: you may assume the system will always have access to a quantity of physical memory equal to the full address space)

• Create a Page Table for a single process (note: you are not required to model any other components of a process)

• Randomly write between 2048 and 20480 bytes of data belonging to the ‘process’ previously created. Both the content and locations of these bytes should be pseudo-randomised to some extent.

•Write a file to [your solution]/data/physical_memory.txt which displays the contents of your simulation of physical memory in linear, readable form. You must clearly label the memory addresses that are and are not used.

•Write a file to [your solution]/data/page_table.txt which displays the contents of your simulated page table in linear, readable form.

•Add 2 entries to the Page Table which point to pages which are not stored in your simulated physical memory, and store content for these pages in your solution’s data folder (the naming convention is at your discretion). You should print 1 virtual address from each of these pages, clearly labelled, to the console.

•Print, to the console, a human-readable description of the structure of a single page table entry that you have elected to use (note: you should also document your decisions regarding this in your README.md file)

•Display a prompt which allows the user to enter any virtual memory address in your system, in hexadecimal form.

Dependencies

Ubuntu 18.04+
gcc
CMake
