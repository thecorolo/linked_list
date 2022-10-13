#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Zinbi
{
    int value;
    struct Zinbi *next;

} Zinbi;


Zinbi *add_last(Zinbi *list, int value)
{
    Zinbi *head;
    
    head = list;

    Zinbi *last;
    last = malloc(sizeof(Zinbi) * 1);
    last->value = value;
    last->next = NULL;

    while(list->next->next)
    {
        list = list->next;
    }
    list->next = last;
    return head;
}

Zinbi *add_index(Zinbi *list,int value,int insert)
{
    Zinbi *head;
    head = list;
    int len = 0;
    while(list->next)
    {
       // printf("1");
        len++;
        list = list->next;
    }
    list = head;
    if (insert > len)
    {
        exit(0);
    }
    
    Zinbi *middle;
    middle = malloc(sizeof(Zinbi) * 1);
    middle->value = value;
    
    // middle->next = list;
    int i = 0;
    while (i <= insert)
    {
      //  printf("1");
        if (i == insert)
        {
            middle->next = list->next;
            list->next = middle;
        }
        list = list->next;
        i++;
    }
    return head;
}

Zinbi *add_first(Zinbi *list, int value)
{
    Zinbi *first;
    first = malloc(sizeof(Zinbi));
    first->value = value;
    first->next = list;
    return first;
}

int main(int argc, char **argv)
{
    Zinbi *list;
    Zinbi *head;

    int i = 0;
    int j = 1;

    list = malloc(sizeof(Zinbi) * 1);
    head = list;

    while( i < argc - 1)
    {
        list->value = atoi(argv[j]);
        list->next = malloc(sizeof(Zinbi) * 1);
        //list = list->next;
        i++;
        j++;
    }
    list = NULL;

    list = head;
    // while(list->next)
    // {
    //     printf("%d\n",list->value);
    //     list = list->next;
    // }
   // list = head;
    //list = add_last(list,18);
    while(list->next)
    {
        printf("%d\n",list->value);
        list = list->next;
    }

}