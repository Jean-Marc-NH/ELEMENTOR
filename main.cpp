#include <iostream>

struct node 
{
    int A[10];
    node* next;
    int* it;

    node(int v, node* n = NULL) 
    {
        next = n;
        it = A;
        *it = v;
    }
};

struct elementor 
{
    node* inicio;
    node* fin;
    node* nodeit;
    int* p;
    int* top;

    elementor()
    {
        inicio = NULL;
        fin = NULL;
        nodeit = NULL;
        p = NULL;
        top = NULL;
    }

    bool find(int v)
    {
        if (!inicio)return false;
        nodeit = inicio;
        p = nodeit->it;
        while (p) {
            if (v > *top)return false;

            if (v < *p)return false;

            if (*p == v)return true;

            if (p == ((nodeit->it) + 10)) {
                nodeit = nodeit->next;
                p = nodeit->it;
            }
            else {
                p++;
            }
        }
        return false;
    }

    void add(int v) 
    {
        if (!inicio)
        {
            inicio = new node(v, inicio);
            top = inicio->it;
            fin = inicio;
        }

        if (!find(v))
        {
            if (v > *p)
            {
                if
            }
        }
    }

    void print()
    {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
