#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Zinbi
{
    int value;
    struct Zinbi *next;

} Zinbi;


Zinbi *ft_add(Zinbi *list, int insert, int value, int argc)
{
    Zinbi *head;
    Zinbi *reminder;
    int i = 1;

    head = list;

    if (insert > argc - 1)
    {
        printf("erreur \n");
        exit(0);
    }

    while(list->next != NULL && ((i <= insert) || (insert == 0)) )
    {
        if (insert == 0)
        {
            Zinbi *node;
            node = malloc(sizeof(Zinbi) * 1);
            head = node;
            node->value = value;
            node->next = list;
            break;
        }
        else if (i == insert)
        {
            reminder = list->next;
            Zinbi *node;
            node = malloc(sizeof(Zinbi) * 1);
            node->value = value;
            list->next = node;
            node->next = reminder;
        }
        i++;
        list = list->next;
    }
    return head;
}
int main(int argc , char **argv)
{
    Zinbi *list;
    Zinbi *head;

    int i = 0;
    int j = 1;


    list = malloc(sizeof(Zinbi) * 1);
    head = list;
    while(i < argc - 1)
    {
        list->value = atoi(argv[j]);
        list->next = malloc(sizeof(Zinbi) * 1);
        list = list->next;
        i++;
        j++;
    }
    list = NULL;
    list = head;
    list = ft_add(list,2,6,argc);
    //list = ft_add(list,2,200);



    while(list->next != NULL)
    {
        printf("%d\n", list->value);
       list = list->next;
    }
    
}