#include <iostream>

struct element
{
    int value;
    element* next;
};

struct List
{
    int length;
    element* head;
    element* end;
};

List* create_empty()
{
    List* list = new List();
    list->length = 0;
    list->head = nullptr;
    list->end = nullptr;
    return list;
};

void add_to_begin(int val, List* list)
{
    element* res = new element;
    res->value = val;
    res->next = list->head;
    list->head = res;
    if(list->length == 0)
    {
        list->end = res;
    }
    list->length++;
}

void add_to_end(int val, List* list)
{
    element* res = new element;
    res->value = val;
    res->next = nullptr;
    std::cout << list->end->value << std::endl;
    list->end = res;
    if(list->length == 0)
    {
        list->head = res;
    }
    std::cout << list->end->value << std::endl;
    std::cout << list->end << '\n';
    list->length++;
}
/*void add_to_end(int val, List * list)
{
    element * last;
    element *tmp = (element*)malloc(sizeof(element));
    tmp->value = val;
    if (list->length == 0)
    {
        tmp->next = list->head;
        list->head = tmp;
        list->length += 1;
    }
    else
    {
        while (last->next != nullptr)
        {
        last = last->next;
        }
        tmp->value = val;
        tmp->next = NULL;
        last->next = tmp;
        list->length += 1;
    }
}*/

List* reverse(List * list)
{
    element * last;
    last = list->head;
    while(last->next != nullptr)
    {
        last = last->next;
    }

}

void print_list(List * list)
{   element* tmp;
    tmp = list->head;
    std::cout << list->end << '\n';
    while(tmp != nullptr)
    {
        std::cout<< tmp->value << ' ';
        tmp = tmp->next;
    }
    std::cout << std::endl;

}

List* copy_list(List * list)
{
    List * list_new = new List();
    list_new = create_empty();
    element *tmp = new element;
    tmp = list->head;
    while(tmp != nullptr)
    {
        add_to_end(tmp->value, list_new);
        tmp = tmp->next;
    }
    return list_new;
}

void Clear(List * list)
{
   if(list->length == 0) return;
   element *tmp = new element;
   element *tmp1 = new element;
   while(tmp != nullptr)
   {
      tmp1 = tmp;
      tmp = tmp->next;
      delete tmp1;
   }

}

void add_i(int n, int val, List * list)
{
    element * tmp1;
    element *tmp = new element;
    tmp->value = val;
    tmp1->next = list->head;
    for(int i = 0; i < n-1; i++)
    {
        tmp1 = tmp1->next;
    }
    if (tmp1->next != nullptr)
    {
        tmp->next=tmp1->next;
    }
    else
    {
        tmp->next = nullptr;
    }
    tmp1->next = tmp;
    list->length += 1;
}

List* merge(List * list1, List * list2)
{
    element * tmp;
    tmp = list1->head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = list2->head;
    return list1;
}

int main() {

    List * list1 = new List();
    list1 = create_empty();
//    add_to_end(55, list1);
    add_to_begin(1, list1);
    add_to_begin(22, list1);
    add_to_begin(8, list1);
    add_to_end(11, list1);
    add_to_begin(3, list1);
    add_to_end(80, list1);
    print_list(list1);
    return 0;
}
