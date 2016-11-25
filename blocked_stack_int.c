#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include "blocked_stack_int.h"

/*
*Program to implement a blocked stack
*which links to the demo program and then displays the stack accordingly.
*/



                                        /*------------------------------------------------*/
struct stack_node  /*------->           /* This defines the node, the stack_node points to*/
{                                       /* the memory address of a, the  * points to      */
    struct stack_node * a;              /* block, and the position variable shows the     */
    int * block;                        /* position in the array.                         */
    int position;                       /*------------------------------------------------*/
};



                                                /*--------------------------------------------------*/
struct stack_int_implementation /*------->      /* This simply highlights how the stack is defined  */
{                                               /* in other words,the stack node points to the node */
    struct stack_node * node;                   /* stack size = size of stack, block size = size of */
    int stacksize;                              /* array in the node.                               */
    int blocksize;                              /*--------------------------------------------------*/
};



                                                                            /*----------------------------------------------------------*/
struct stack_node * new_node(int blocksize)         /*------->              /*This creates a new node and allocates memory to the node  */
{                                                                           /*the parameter defines the size of the array in the node.  */
    struct stack_node * node = malloc(sizeof(struct stack_node));           /*the node -> block allocates memory to the array block size*/
    node -> block = malloc(sizeof(int)*blocksize);                          /*the node position equals 0 and finally it returns the node*/
    node -> position = 0;                                                   /*----------------------------------------------------------*/
    return node;
}




                                                                        /*---------------------------------------------------------------------------*/
stack_int * new_blocked_stack_int(int blocksize)  /*------->            /*This creates a stack of block size, if the block size is equal to zero the */
{                                                                       /*program returns an error and terminates. The stack int allocates memory to */
    if (blocksize == 0)                                                 /*the stack. The stack size is set to 0, the block size is set to the        */
{                                                                       /*whatever the parameter represents. The stack node creates a new node with  */
        printf("Error!!!");                                             /*an array of size(block size), then it returns the stack                    */
        return 0;                                                       /*---------------------------------------------------------------------------*/
}
    stack_int * s = malloc(sizeof(stack_int));
    s -> stacksize = 0;
    s -> blocksize = blocksize;
    struct stack_node * node = new_node(blocksize);
    s -> node = node;
    node -> a = NULL;
    return s;
}




int stack_int_isempty(stack_int * s) /*------->           /*------------------------------------------------*/
{                                                         /* This function simply tests to see if the stack */
    assert(s!=NULL);                                      /* is empty or not and it returns the integer 0   */
    return (s -> stacksize == 0);                         /*------------------------------------------------*/
}






int  stack_int_size(stack_int * s) /*------->   /*------------------------------------------------*/
{                                               /*This function returns an integer for the size   */
    assert(s!=NULL);                            /*of the stack as long as the size is not NULL.   */
    return s -> stacksize;                      /*------------------------------------------------*/
}




                                                                             /*---------------------------------------------------------------------*/
void stack_int_push(stack_int * s, int b) /*------->                         /* This function basically pushes an integer on the stack              */
{                                                                            /* if the block size of the stack is equal to the position of the node */
    if (s -> blocksize == s -> node -> position)                             /* in the stack, then a new node is created with the block size        */
{                                                                            /* then it points to the new node. The current node equals the new node*/
        struct stack_node * node = new_node (s -> blocksize);                /* then you add the value to the position in the array and increment   */
        node -> a = s -> node;                                               /* the position by one, and also increment the stack size.             */
        s -> node = node;                                                    /* (Adds an item to the top of the stack)                              */
}                                                                            /*---------------------------------------------------------------------*/
    * (s -> node -> block + s -> node -> position++) = b;
    ++s -> stacksize;
}




                                                        /*--------------------------------------------------------------------------------*/
void stack_int_pop(stack_int * s)  /*------->           /* This function checks to see if the stack is empty, if it is it gives           */
{                                                       /* an error and the program terminates whereas if its not it checks to see if     */
    if (stack_int_isempty(s))                           /* the position in the node is equal to 0 and then functions similarly to the push*/
{                                                       /* function however instead of incrementing the position and stack size it        */
        printf("Error!");                               /* decrements it by one. (removes the top item of the stack)                      */
        return 0;                                       /*--------------------------------------------------------------------------------*/
}
    else if (s -> node -> position == 0)
{
        struct stack_node * node = s->node;
        s -> node = node -> a;
        free (node -> block);
        free (node);
}
    --s -> stacksize;
    --s -> node -> position;
}





int  stack_int_top(stack_int * s) /*------->           /*-----------------------------------------------------------------------------------------*/
{                                                      /* This function also checks to see if the stack is empty(calls the is empty function)     */
    if (stack_int_isempty(s))                          /* if it is empty it prints an error and the program terminates, else if the position      */
{                                                      /* in the node of the stack is equal to 0 then it returns the position of the current      */
        printf("Error!");                              /* top of the previous node else it returns the last pushed item if the block is not empty */
        return 0;                                      /*-----------------------------------------------------------------------------------------*/
}
    else if (s -> node -> position == 0)
{
            return *(s -> node -> a -> block + s -> blocksize - 1);
}
    else
{
            return *(s -> node -> block + (s -> node -> position - 1));
}

}




void stack_int_display(stack_int * s)    /*------->                /*---------------------------------------------------------------*/
{                                                                  /*     The display chosen, shows each stack being created        */
    int stack_current = s->stacksize;                              /*     horizontally, the stack current gets the stack size       */
    int loop_count = 0;                                            /*     the loop count is set to 0, if the stack current is 0     */
                                                                   /*     it prints the empty stack(pipe symbols). The top is       */
    if (stack_current == 0)                                        /*     printed to highlight the top of each stack. Throughout    */
{                                                                  /* the program each conversion specifier prints the stack current*/
    printf("\n || \n \n");                                         /*---------------------------------------------------------------*/
}
    else if (stack_current % 10 == 0)
{
}
    else
{
     printf("\n TOP");
     printf("\n |");
}
     if (stack_current > 0)
{
     while (stack_current > 1)
{
     if (stack_current % 10 == 0 && loop_count == 0)
{
     printf("\n TOP");
     printf("\n |");
}
    else if (stack_current % 10 == 0)
{
     printf("|");
     printf("\n \n |");
}
    if ((stack_current % 10) == 1)
{
     printf("%i", stack_current);
}
    else
{
    printf("%i,", stack_current);
}
    --stack_current;
    loop_count++;
}
    printf("%i", stack_current);
    printf("| \n");
}
    system("COLOR 0A");
}


void stack_int_release(stack_int * s)  /*------->   /*----------------------------------------------------*/
{                                                   /* This function simply free's the memory allocated   */
    assert(s != NULL);                              /* to the stack as long the stack is not equal to null*/
    free(s);                                        /*----------------------------------------------------*/
}

