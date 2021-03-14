#include <iostream>

struct Stack
{
    int length;
    int* data; //= new int[];
};

Stack* init()
{
    Stack* new_stack = new Stack;
    new_stack->length = 0;
    new_stack->data = new int[0];
    return new_stack;
}

void push(Stack* st, int value)
{
    int *arr_new = new int[st->length + 1];
    int *arr_copy = st->data;
    if (st->length == 0)
    {
        arr_new[0] = value;
    }
    else
    {


        for (int i = 0; i < st->length; i++)
        {
            arr_new[i] = st->data[i];

        }
        arr_new[st->length] = value;
    }
    st->data = arr_new;
    delete [] arr_copy;
    st->length++;
}

void pop(Stack* st)
{
    int *arr_new = new int[st->length-1];
    int *arr_copy = st->data;
    for(int i = 0; i < st->length - 1; i++)
    {
        arr_new[i] = st->data[i];
    }
    st->data = arr_new;
    delete [] arr_copy;
    st->length--;
}

void show(Stack* st)
{
    for(int i = 0; i < st->length; i++)
    {
       std::cout << st->data[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{

    Stack* stack1 = new Stack;
    stack1 = init();
    push(stack1, 5);
    show(stack1);
    push(stack1, 4);
    show(stack1);
    push(stack1, 3);
    show(stack1);
    push(stack1, 2);
    show(stack1);
    push(stack1, 1);
    show(stack1);
    pop(stack1);
    show(stack1);
    pop(stack1);
    show(stack1);
    return 0;

}
