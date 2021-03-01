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
};

List* create_empty()
{
    List * list = new List();
    list->length = 0;
    list->head = NULL;
    return list;
};

void add_to_begin(int val, List * list)
{
    element *tmp = (element*)malloc(sizeof(element));
    tmp->value = val;
    tmp->next = list->head;
    list->head = tmp;
    list->length += 1;
}

void add_to_end(int val, List * list)
{   element * last;
    element *tmp = (element*)malloc(sizeof(element));
    last = list->head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    tmp->value = val;
    tmp->next = NULL;
    last->next = tmp;
    list->length += 1;
}

List* reverse(List * list)
{
    element * last;
    last = list->head;
    while(last->next != NULL)
    {
        last = last->next;
    }

}

void print_list(List * list)
{   element *tmp = (element*)malloc(sizeof(element));
    tmp = list->head;
    while(tmp != NULL)
    {
        std::cout<< tmp->value << ' ';
        tmp = tmp->next;
    }
    std::cout << std::endl;

}

List* copy_list(List * list)
{
    List * list_new = new List();
    element *tmp = (element*)malloc(sizeof(element));
    tmp = list->head;
    while(tmp != NULL)
    {
        add_to_begin(tmp->value, list_new);
        tmp = tmp->next;
    }
    return list_new;
}

void Clear(List * list)
{
   if(list->length == 0) return;
   element *tmp = (element*)malloc(sizeof(element));
   element *tmp1 = (element*)malloc(sizeof(element));
   while(tmp != NULL)
   {
      tmp1 = tmp;
      tmp = tmp->next;
      delete tmp1;
   }

}

void add_i(int n, int val, List * list)
{
    element * tmp1;
    element *tmp = (element*)malloc(sizeof(element));
    tmp->value = val;
    tmp1->next = list->head;
    for(int i = 0; i < n-1; i++)
    {
        tmp1 = tmp1->next;
    }
    if (tmp1->next != NULL)
    {
        tmp->next=tmp1->next;
    }
    else
    {
        tmp->next = NULL;
    }
    tmp1->next = tmp;
    list->length += 1;
}

List* merge(List * list1, List * list2)
{
    element * tmp;
    tmp = list1->head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = list2->head;
    return list1;
}

int main() {

    List * list1 = new List();
    list1 = create_empty();
    add_to_begin(2, list1);
    add_to_begin(3, list1);
    add_to_end(1, list1);
    add_to_end(22, list1);
    print_list(list1);
    List * list2 = new List();
    list2 = copy_list(list1);
    print_list(list2);
    List * list3 = new List();
    list3 = merge(list1, list2);
    print_list(list3);
    return 0;
}
