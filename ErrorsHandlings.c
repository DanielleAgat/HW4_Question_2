//Student's name: Danielle Agat Levi
//Student's ID: 313357329

#include <stdio.h>
#include <stdlib.h>

void checkMemoryAllocation(void* ptr){
    if(ptr == NULL){
        printf("ERROR: Memery allocation failed!");
        exit(1);
    }
}