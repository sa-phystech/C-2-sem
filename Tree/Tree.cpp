#include <iostream>

struct node
{
    int value;
    node* right;
    node* left;
    unsigned char height;
    node(int val) { value=val; height=1; left=right=nullptr; }
};

unsigned char h(node* tree)
{
    return tree?tree->height:0;
}

int bfactor(node* tree)
{
    return h(tree->right)-h(tree->left);
}

void fixheight(node* tree)
{
    unsigned char hl = h(tree->left);
    unsigned char hr = h(tree->right);
    tree->height = (hl>hr?hl:hr) + 1;
}

node* rotateright(node* tree)
{
    node* tmp =tree->left;
    tree->left = tmp->right;
    tmp->right = tree;
    fixheight(tree);
    fixheight(tmp);
    return tmp;
}

node* rotateleft(node* tree)
{
    node* tmp =tree->right;
    tree->right = tmp->left;
    tmp->left = tree;
    fixheight(tree);
    fixheight(tmp);
    return tmp;
}

node* balance(node* tree)
{
    fixheight(tree);
    if(bfactor(tree)==2)
    {
        if( bfactor(tree->right)<0)
            tree->right = rotateright(tree->right);
        return rotateleft(tree);
    }
    if (bfactor(tree)==-2)
    {
        if (bfactor(tree->left)>0)
            tree->left = rotateleft(tree->left);
        return rotateright(tree);
    }
    return tree;
}

node* add(node* tree, int val)
{
    if (!tree) return new node(val);
    if(val < tree->value)
    {
        tree->left = add(tree->left, val);
    }
    else
    {
        tree->right = add(tree->right, val);
    }
    return balance(tree);
}

node* findmin(node* tree)
{
    return tree->left?findmin(tree->left):tree;
}

node* removemin(node* tree)
{
    if(tree->left == nullptr)
        return tree->right;
    tree->left = removemin(tree->left);
    return balance (tree);
}

node* removenode(node* tree, int val)
{
    if (!tree) return nullptr;
    if(val < tree->value)
        tree->left = removenode(tree->left, val);
    else if (val > tree->value)
        tree->right = removenode(tree->right, val);
    else
    {
        node* l = tree->left;
        node* r = tree->right;
        delete tree;
        if (!r) return l;
        node* minimum = findmin(r);
        minimum->right = removemin(r);
        minimum->left = l;
        return balance(minimum);
    }
    return balance(tree);
}

node* find_value(node* tree, int val)
{
    if ((tree == nullptr)||(tree->value == val))
        return tree;
    if (val < tree->value)
    {
        return find_value(tree->left, val);
    }
    else
    {
        return find_value(tree->right, val);
    }
}

void find_all_leaves(node* tree)
{
    if (tree)
    {
        find_all_leaves(tree->left);
        if ((!tree->left) && (!tree->right))
            std::cout << tree->value << std::endl;
        find_all_leaves(tree->right);
    }
}

void inf_order(node* tree)
{
    if (tree!= nullptr)
    {
        inf_order(tree->left);
        std::cout << tree->value << std::endl;
        inf_order(tree->right);
    }
}

void post_order(node* tree)
{
    if (tree!= nullptr)
    {
        post_order(tree->left);
        post_order(tree->right);
        std::cout << tree->value << std::endl;
    }
}

void pre_order(node* tree)
{
    if (tree!= nullptr)
    {
        std::cout << tree->value << std::endl;
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

int main()
{
    node* root = new node(3);
    std::cout << root->value << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 12; i++)
    {
        int a = rand() % 76 + 34;
        root = add(root, a);
        std::cout << a << ' ';
    }
    std::cout << std::endl;
    inf_order(root);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << find_value(root, 37) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << root->value << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    find_all_leaves(root);
    return 0;
}
