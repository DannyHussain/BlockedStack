    #include <stdio.h>
    #include <stdlib.h>
    #include "blocked_stack_int.h"

    char line[] = "****************************************";

    void snapshot(stack_int * s, char * m)
    {
    printf("\n%s\n", line);
    printf("** %s\n", m);

    printf("** Stack size is %4i\n", stack_int_size(s));
    if (!stack_int_isempty(s))
    printf("** Top of stack is %4i\n", stack_int_top(s));
    printf("%s\n", line);
    stack_int_display(s);
    }


    int main() {

    //Should print new empty stack of size 10
    int i,j;
    int bs=10;
    stack_int * s = new_blocked_stack_int(bs);
    snapshot(s, "New stack");
    printf("Pushing and popping. All ok: ");

    //Test to populate stack then empty stack and check if stack returns empty values: (0)
    j = bs*2+2;
    for(i=0; i<j; i++)
    stack_int_push(s, i);

    for(i=j-1; i>=0; i--) {

    if (i != stack_int_top(s)){
    printf("NO!\n");
    exit(1);
    }

    stack_int_pop(s);
    }
    printf("YES\n");
    printf("Stack should be empty: ");

    if (stack_int_isempty(s))
    printf("YES\n");
    else {
    printf("NO!\n");
    exit(1);
    }


    //checks value 1 is pushed in stack values: (1)
    stack_int_push(s, 1);
    snapshot(s, "Pushed an item");

    //fills stack with values 2 - 10 values: (2 - 10)
    for(i=2;i<=bs;i++) stack_int_push(s, i);
    snapshot(s, "Filled first block");

    //Creates new node with stack array starting at 11 values: (1 - 11)
    stack_int_push(s, 11);
    snapshot(s, "Push an item - created new block");

    // Fills up second node and populates some of third node by adding 12 - 29 to the array values(1 - 29)
    for(i=bs+2; i<=3*bs-1; i++) stack_int_push(s, i);
    snapshot(s, "Created two new blocks");

    //Push 30 to fill array in third node values: (1 - 30)
    stack_int_push(s, 3*bs);
    snapshot(s, "Pushed an item filling the block");

    //31 is added to array to create a 4th node values: (1 - 31)
    stack_int_push(s, 3*bs+1);
    snapshot(s, "Pushed an item creating new block");

    //pop value 31 from the array to remove 4th node values: (1 - 30)
    stack_int_pop(s);
    snapshot(s, "Popped an item - lose one block");

    //pop value 30 from the array therefore 3rd node is not full by 1 values: (1 - 29)
    stack_int_pop(s);
    snapshot(s, "Popped an item");

    //remove 9 items from top of array which removes a node and the 2 remainder nodes are both full values : (1 - 20)
    for(i=1; i<bs; i++) stack_int_pop(s);
    snapshot(s, "Popped items - clearing the first block");

    //removes items from array positions (1 - 14) leaves you with half a node  values : (1 - 5)
    for(i=1; i<bs+bs/2; i++) stack_int_pop(s);
    snapshot(s, "Popped items - cleared one and a half blocks");

    //while stack size is greater than 1 remove all elements in the node values : (1)
    while (stack_int_size(s) > 1) stack_int_pop(s);
    snapshot(s, "Emptied the stack bar one element");

    //remove last item from the stack and have an empty stack
    stack_int_pop(s);
    snapshot(s, "Popped the last item");

    return 0;
    }
