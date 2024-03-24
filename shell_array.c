#include<stdio.h>
#include<stdlib.h>
#include "shell_array.h"

long *Array_Load_From_File(char *filename, int *size)
{
    long* arr; // stores all the elements

    FILE* fptr = fopen(filename, "rb");

    if(fptr == NULL)
    {
        *size = 0;
        return NULL;
    }
    else
    {
        // FINDING AMOUNT OF MEMORY TO ALLOCATE
        fseek(fptr, 0, SEEK_END);
        *size = ftell(fptr);

        // ALLOCATING MEMORY
        arr = malloc(*size);

        //CALCULATING SIZE
        *size = *size / sizeof(long);

        fseek(fptr, 0, SEEK_SET);

        fread(arr, sizeof(long), *size, fptr);

    }

    fclose(fptr);

    return (arr);
    
}

int Array_Save_To_File(char *filename, long *array, int size)
{
    int ret_val = 0;

    if(array == NULL || size == 0)
    {
        FILE* fptr = NULL;
        fptr = fopen(filename, "wb");
        fclose(fptr);
        return ret_val;
    }

    FILE* fptr = NULL;
    fptr = fopen(filename, "wb");

    ret_val = fwrite(array, sizeof(long), size, fptr);

    fclose(fptr);
    return ret_val;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{
    long temp;
    int idx;
    int sequence = 1;

    while(sequence < size)
    {
        sequence = 3 * sequence + 1;
    }

    sequence = (sequence - 1) / 3;

    for(int i = sequence; i > 0; i = ((i - 1) / 3))
    {
        for(int j = i; j < size; j++)
        {
            temp = array[j];
            idx = j;

            while( (++(*n_comp)) && (idx >= i) && (array[idx - i] > temp))
            {
                array[idx] = array[idx - i];
                idx = idx - i;
            }

            array[idx] = temp;
        }
    }
}
