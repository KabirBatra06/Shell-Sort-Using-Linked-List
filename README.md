## GOAL

This code implements the Shell sort algorithm for sorting a linked list of integers.

## CODE EXPLAINATION

- Structures and Global Definitions:

  Defined a Node structure to represent each node in the linked list.\
  Provided functions to load data from a file into a linked list and save data from a linked list into a file.\
  Implemented utility functions like list_len to calculate the length of a linked list and makenode to create a new node.

- File I/O Functions:
  
  List_Load_From_File: Reads a binary file containing long integer values and creates a linked list with these values.\
  List_Save_To_File: Writes the values of a linked list to a binary file.

- Shell Sort Function (List_Shellsort):

  Uses the Shell sort algorithm to sort the linked list.\
  Calculates the sequence to be used in the Shell sort algorithm based on the length of the list.\
  Implements swapping of nodes to sort the list.\
  Utilizes a seq_calc function to determine the sequence for Shell sort.\
  Defines a swap_node function to swap nodes in the list.\
  Implements a next_k_node function to find the next kth node in the list.\
  Tracks the number of comparisons made during the sorting process through the n_comp pointer.\
  Executes the Shell sort algorithm on the list.
