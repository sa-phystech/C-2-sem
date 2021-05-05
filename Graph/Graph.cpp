#include <iostream>
#include <queue>
#include <stack>
using std::stack;
using std::queue;

struct Graph
{
    int* a;
    int length;
    int** matrix;
};

Graph* create()
{
    Graph* res = new Graph();
    res->length = 1;
    res->a = new int[1];
    res->a[0] = 1;
    res->matrix = new int *[res->length];
    for (int i = 0; i < res->length; i++)
    {
        res->matrix[i] = new int[res->length];
    }
    res->matrix[0][0] = 0;
    return res;
}

void add_element(Graph* res)
{
    int* new_res = new int[res->length+1];
    for(int i = 0; i < res->length; i++)
    {
        new_res[i] = res->a[i];
    }
    new_res[res->length] = res->length;
    res->a = new_res;

    int** A = new int* [res->length+1];
    for ( int i = 0; i < res->length+1; i++)
    {
        A[i] = new int[res->length+1];
    }
    for (int i = 0; i < res->length; i++)
    {
        for (int j = 0; j < res->length; j ++)
        {
            A[i][j] = res->matrix[i][j];
            A[i][res->length] = 0;
        }
    }
    for (int i = 0; i < res->length+1; i++)
    {
        A[res->length][i] = 0;
    }
    res->matrix = A;
    res->length += 1;
}

void add_rebro(Graph* res, int a, int b)
{
    res->matrix[a-1][b-1] = 1;
    res->matrix[b-1][a-1] = 1;
}

 void remove_rebro(Graph* res, int a, int b)
{
     res->matrix[a-1][b-1] = 0;
     res->matrix[b-1][a-1] = 0;
}

void BFS (Graph* res)
{
    int nodes[res->length];
    for (int i = 0; i < res->length; i++)
    {
        nodes[i] = 0;
    }
    queue<int> Queue;
    Queue.push(0);
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (int i = 0; i < res->length; i++)
        {
            if ((res->matrix[node][i] == 1) && (nodes[i] == 0))
            {
                Queue.push(i);
                nodes[i] = 1;

            }
        }
        std::cout << node + 1 << std::endl;
    }

}

void DFS(Graph* res)
{
    int nodes[res->length];
    for (int i = 0; i < res->length; i++)
    {
        nodes[i] = 0;
    }
    stack<int> Stack;
    Stack.push(0);
    while (!Stack.empty())
    {
        int node = Stack.top();
        Stack.pop();
        if (nodes[node] == 2)
            continue;
        nodes[node] = 2;
        for (int i = res->length - 1; i >= 0; i--)
        {
            if ((res->matrix[node][i] == 1) && (nodes[i] != 2))
            {
                Stack.push(i);
                nodes[i] = 1;
            }
        }
        std::cout << node + 1 << std::endl;
    }
}

void print_matrix(Graph* res)
{
    for (int i = 0; i < res->length; i++)
    {
        for (int j = 0; j < res->length; j++)
        {
            std::cout << res->matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    Graph* graph = new Graph();
    graph = create();
    for (int i = 0; i < 6; i++)
    {
        add_element(graph);
    }
    add_rebro(graph, 1, 2);
    add_rebro(graph, 1, 3);
    add_rebro(graph, 1, 7);
    add_rebro(graph, 2, 3);
    add_rebro(graph, 6, 7);
    add_rebro(graph, 5, 6);
    add_rebro(graph, 4, 5);
    add_rebro(graph, 2, 4);
    std::cout << graph->length << std::endl;
    std::cout << std::endl;
    BFS(graph);
    std::cout << std::endl;
    std::cout << std::endl;
    print_matrix(graph);
    std::cout << std::endl;
    std::cout << std::endl;
    DFS(graph);
    return 0;
}
