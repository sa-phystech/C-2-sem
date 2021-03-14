#include <iostream>
#include <string>

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

int pop(Stack* st)
{
    int res = st->data[st->length-1];
    int *arr_new = new int[st->length-1];
    int *arr_copy = st->data;
    for(int i = 0; i < st->length - 1; i++)
    {
        arr_new[i] = st->data[i];
    }
    st->data = arr_new;
    delete [] arr_copy;
    st->length--;
    return res;
}

void show(Stack* st)
{
    for(int i = 0; i < st->length; i++)
    {
       std::cout << st->data[i] << ' ';
    }
    std::cout << std::endl;
}

bool is_operation(std::string c)
{
    bool result = false;
    if( c == "+")
    {
        result = true;
    }
    if( c == "-")
    {
        result = true;
    }
    if( c == "*")
    {
        result = true;
    }
    if( c == "/")
    {
        result = true;
    }
    return result;
}

int main()
{
    Stack* stack1 = new Stack;
    stack1 = init();
    std::string symbol;
    std::cin >> symbol;
    while(symbol != "="){
        if (is_operation(symbol) == false )
        {
            int a = atoi(symbol.c_str());
            push(stack1, a);
        }
        else
        {
           if(symbol == "+")
           {
               int s1 = pop(stack1);
               int s2 = pop(stack1);
               int res = s1 + s2;
               push(stack1, res);
           }
           if(symbol == "*")
           {
               int s1 = pop(stack1);
               int s2 = pop(stack1);
               int res = s1*s2;
               push(stack1, res);
           }
           if(symbol == "-")
           {
               int s1 = pop(stack1);
               int s2 = pop(stack1);
               int res = s2 - s1;
               push(stack1, res);
           }
           if(symbol == "/")
           {
               int s1 = pop(stack1);
               int s2 = pop(stack1);
               int res = s2/s1;
               push(stack1, res);
           }
        }
        std::cin >> symbol;
    }
    std::cout << stack1->data[0] << std::endl;
    return 0;
}
