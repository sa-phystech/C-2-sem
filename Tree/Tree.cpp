#include <iostream>

struct node
{
    int value;
    node *left;
    node *right;
};
struct tree
{
    node* root;
};

tree* create_empty()
{
    tree* tr = new tree();
    tr->root = nullptr;
    return tr;
}

node* add_value(node* res, int val)
{
    if (res == nullptr)
    {
    res = new node;
    res->value = val;
    res->left = nullptr;
    res->right = nullptr;
    }
    else if(val < res->value)
    {
        res->left = add_value(res->left, val);
    }
    else
    {
        res->right = add_value(res->right, val);
    }
    return res;
}

node* find_value(tree* tr, int val)
{
    node* tmp;
    tmp = tr->root;
    while ((tmp->left != nullptr)&&(tmp->right != nullptr)){
    if(tmp->value != val)
    {
        if(val < tmp->value)
        {
            tmp = tmp->left;
        }
        else if (tmp->value == val)
        {
            return tmp;
        }
        else
        {
            tmp = tmp->right;
        }

    }}
}

void pre_order(node* element)
{
    if (element!= nullptr)
    {
        std::cout << element->value << ' ' << std::endl;
        pre_order(element->left);
        pre_order(element->right);
    }

}

void inf_order(node* element)
{
    if (element!= nullptr)
    {
        inf_order(element->left);
        std::cout << element->value << ' ' << std::endl;
        inf_order(element->right);
    }
}

void post_order(node* element)
{
    if (element!= nullptr)
    {
        post_order(element->left);
        post_order(element->right);
        std::cout << element->value << ' ' << std::endl;
    }
}

void find_all_leaves(node* element)
{

    if (element != nullptr)
    {
        if ((element->right == nullptr)&&(element->left == nullptr))
        {
            std::cout << element->value << ' ' << std::endl;
        }
       find_all_leaves(element->left);
       find_all_leaves(element->right);
    }
}

bool find_value(node* element, int val)
{
    bool result;
    if (element != nullptr)
    {
        result = false;
        if (element->value == val)
        {
            result = true;
        }
        if (result == false)
        {
            result = find_value(element->left, val);
        }
        if (result == false)
        {
            result = find_value(element->right, val);
        }
    }
    return result;
}

int rightmost(node* element)
{
    while (element->right != nullptr)
    {
        element = element->right;
    }
    return element->value;
}

node* remove_by_value(node* element, int val)
{
   if (element == nullptr)
   {
       return element;
   }
   if (element->value == val)
   {
       if ((element->left == nullptr)&&(element->right == nullptr))
       {
           delete element;
           return nullptr;
       }
       if ((element->right == nullptr)&&(element->left != nullptr))
       {
           node* temp = element->left;
           delete element;
           return temp;
       }
       if ((element->right != nullptr)&&(element->left == nullptr))
       {
           node* temp = element->right;
           delete element;
           return temp;
       }
       element->value = rightmost(element->left);
       element->left = remove_by_value(element->left, element->value);
       return element;
   }
   if (val < element->value)
   {
       element->left = remove_by_value(element->left, val);
       return element;
   }
   if ( val > element->value)
   {
       element->right = remove_by_value(element->right, val);
       return element;
   }
   return element;
}


int main()
{
    tree* tree1 = new tree();
    tree1 = create_empty();
    for (int i = 0; i < 10; i++)
    {
        tree1->root = add_value(tree1->root, 1 + rand() % 35);
    }
    pre_order(tree1->root);
    std::cout << std::endl;
    find_all_leaves(tree1->root);
    std::cout << std::endl;
    std::cout << find_value(tree1->root, 13) << std::endl;
    return 0;
}
