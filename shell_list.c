#include<stdio.h>
#include<stdlib.h>
#include "shell_list.h"
#include "list_of_list.h"


static long list_len(Node* head)
{
    long count = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

static Node* makenode(long value)
{
    Node* element = (Node*) malloc(sizeof(Node));

    element->value = value;
    element->next = NULL;

    return(element);
}

Node *List_Load_From_File(char *filename)
{
    FILE* fptr = fopen(filename, "rb");

    long val;

    if(fptr == NULL)
    {
        return NULL;
    }

    Node* head = NULL;
    Node* tail = NULL;
    Node* temp;

    while(fread(&val, sizeof(long), 1, fptr))
    {
        if(head == NULL && tail == NULL)
        {
            head = makenode(val);
            tail = head;
        }
        else
        {
            temp = makenode(val);
            tail->next = temp;
            tail = temp;
        }
    }

    fclose(fptr);
    return(head);
}

int List_Save_To_File(char *filename, Node *list)
{
    Node* temp = list;
    int count = 0;

    FILE* fptr = NULL;
    fptr = fopen(filename, "wb");

    while(temp != NULL)
    {
        count += fwrite(&(temp->value), sizeof(long), 1, fptr);
        temp = temp->next;
    }

    fclose(fptr);
    return count;
}

static Node* swap_node(Node* n0, Node* n1, Node* prevk, Node* nk, Node* head)
{
    // swapping head 
    if(n0 == NULL)
    {
        if(n1->next == nk)
        {
            n1->next = nk->next;
            nk->next = n1;
            return nk;
        }
        else
        {
            Node* temp = n1->next;
            n1->next = nk->next;
            nk->next = temp;
            prevk->next = n1;
            return nk;
        }
        
    }
    else
    {
        if(n1->next == nk)
        {
            n1->next = nk->next;
            nk->next = n1;
            n0->next = nk;
            return head;
        }
        else
        {
            Node* temp2;
            n0->next = nk;
            prevk->next = n1;
            temp2 = n1->next;
            n1->next = nk->next;
            nk->next = temp2;
            return head;
        }
    }
}


static int seq_calc(Node* head)
{
    int sequence = 1;
    int size = list_len(head);

    while(sequence < size)
    {
        sequence = 3 * sequence + 1;
    }

    sequence = (sequence - 1) / 3;

    return sequence;
}

static Node* next_k_node(Node* node, int k, Node** prev)
{
    int count = 0;
    *prev = NULL;

    while(count < k)
    {
        count++;
        *prev = node;
        node = node->next;
        if(node == NULL)
        {
            return NULL;
        }
    }
    return node;
}

Node *List_Shellsort(Node *list, long *n_comp)
{
    int seq = seq_calc(list);
    int len = list_len(list);

    int flag = 0;

    Node* temp;
    Node* prev;

    Node* next_k_ele;
    Node* prevk;

    Node* temp_swap;


    for(int k = seq; k > 0; k/=3)
    {
        for(int i = 0; i < len - k; i++)
        {
            temp = list;
            prev = NULL;
            next_k_ele = next_k_node(list, k, &prevk);

            flag = 0;
            
            for(int j = 0; j < len - k - i; j++)
            {
                if((++(*n_comp)) && temp->value > next_k_ele->value)
                {
                    list = swap_node(prev, temp, prevk, next_k_ele, list);
                    temp_swap = temp;
                    temp = next_k_ele;
                    next_k_ele = temp_swap;
                    flag = 1;
                }

                prev = temp;
                temp = temp->next;

                prevk = next_k_ele;
                next_k_ele = next_k_ele->next;
            }

            if(!flag)
            {
                break;
            }
        }

    }

    return list;

}