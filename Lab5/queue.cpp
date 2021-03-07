#include <iostream>

struct Node
{
    int value;
    Node* next;
};

struct Queue
{
    int length;
    Node* head;
    Node* tail;
};

Queue* init()
{
    Queue* q_new = new Queue;
    q_new->head = nullptr;
    q_new->tail = nullptr;
    q_new->length = 0;
    return q_new;
}

void enqueue(int val, Queue* q)
{
    Node* res = new Node;
    res->value = val;
    if(q->length == 0)
    {
        res->next = q->head;
        q->head = res;
        if(q->length == 0)
        {
            q->tail = res;
        }
    }
    else
    {

        res->next = nullptr;
        q->tail = res;
        if(q->length == 0)
        {
            q->head = res;
        }
        Node* last;
        last = q->head;
        while(last->next != nullptr)
        {
            last = last->next;
        }
        last->next = res;

    }
    q->length++;
}

void dequeue(Queue* q)
{
    Node* res;
    if(q->length == 0)
    {
        return;
    }
    else
    {
        res = q->head;
        int tmp = res->value;
        q->head = q->head->next;
        delete res;
        std::cout << tmp << std::endl;
    }
}

void show(Queue* q)
{
    Node* res;
    res = q->head;
    while(res != nullptr)
    {
        std::cout << res->value << ' ';
        res = res->next;
    }
    std::cout << std::endl;
}

int main()
{
    Queue* q1 = new Queue();
    q1 = init();
    enqueue(1, q1);
    enqueue(2, q1);
    enqueue(3, q1);
    enqueue(4, q1);
    enqueue(5, q1);
    enqueue(6, q1);
    show(q1);
    dequeue(q1);
    show(q1);
    dequeue(q1);
    show(q1);
    return 0;
}
