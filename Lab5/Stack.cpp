#include <iostream>

struct Node
{
    int value;
    Node * next;
};

struct Stack
{
    int length;
    Node* head;
};

Stack* init()
{
    Stack* st_new = new Stack;
    st_new->head = nullptr;
    st_new->length =0;
    return st_new;
}

void push(int val, Stack* st)
{
    Node* res = new Node;
    res->value = val;
    res->next = st->head;
    st->head = res;
    st->length++;
}

void pop(Stack* st)
{
    Node* res;
    if(st->length == 0)
    {
        return;
    }
    else
    {
        int tmp = st->head->value;
        res = st->head;
        st->head = st->head->next;
        delete res;
        std::cout << tmp << std::endl;
    }
    st->length--;
}

void show(Stack* st)
{
    Node* res;
    res = st->head;
    while(res != nullptr)
    {
        std::cout << res->value << ' ';
        res = res->next;
    }
    std::cout << std::endl;
}
int main()
{
    Stack* stack1 = new Stack();
    stack1 = init();
    push(1, stack1);
    push(2, stack1);
    push(3, stack1);
    push(4, stack1);
    push(5, stack1);
    show(stack1);
    pop(stack1);
    show(stack1);
    pop(stack1);
    show(stack1);
    return 0;
}
