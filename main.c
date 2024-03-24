#include <stdio.h>
#include <stdlib.h>
#include "shell_array.h"
#include "shell_list.h"

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("\nWrong number of arguments\n");
        return EXIT_FAILURE;
    }
  
    if (argv[1][1] == 'a')
    {
        int size = 0;
        long comp = 0;
        long* array = Array_Load_From_File(argv[2], &size);
  
        if(!array)
        {
            return EXIT_FAILURE;
        }
  
        Array_Shellsort(array, size, &comp);
        Array_Save_To_File(argv[3], array, size);
        printf("%ld\n", comp);
        free(array); 
    }
    else if(argv[1][1] == 'l')
    {
        long comp = 0;
        Node* head = List_Load_From_File(argv[2]);
        if (!head)
        {
            return EXIT_FAILURE;
        }
        head = List_Shellsort(head, &comp); 
        printf("%ld\n", comp);
        List_Save_To_File(argv[3], head);

        Node* temp;
        while(head != NULL)
        {
            temp = head->next;
            free(head);
            head = temp;
        }
    } 

    return EXIT_SUCCESS;
}