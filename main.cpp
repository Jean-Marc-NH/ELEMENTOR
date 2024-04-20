#include <iostream>
using namespace std;


struct nodo {
    int* valor;
    int* INI = NULL;
    int* FIN = NULL;
    nodo* next = NULL;

    nodo(nodo* nex = NULL) {
        valor = new int[10];
        INI = valor;
        FIN = valor + 10;
        next = nex;
    }
};

struct Elementor {

    int* p = NULL;
    int* q = NULL;
    nodo* s = NULL;
    nodo* t = NULL;
    bool flag = false;
    int size_vector;

    Elementor() {
        size_vector = 10;
        t = new nodo(t);
        s = t;
        p = t->INI;
        q = p;
    }

    ~Elementor()
    {
        for (nodo* tmp = s; tmp;)
        {
            nodo* tmp_2 = tmp;
            tmp = tmp->next;
            delete tmp_2;
        }
    }
    void push(int valor) {



        if (p == t->FIN) {
            t = new nodo(t); t->next->next = t;
            t->next = nullptr;
            p = t->INI;
            *p = valor;
            p++;
            merge(valor);


        }
        else {
            if (!flag) {
                q--; flag = true; *p = valor; p++;
            }
            else {
                *p = valor; p++; merge(valor);
            }
        }
        flag = true;
    }

    void merge(int valor)
    {
        nodo* prev = t;
        nodo* past = t;
        int* m = q + 1;
        nodo* for_m = s;
        bool falg = false;
        for (; m != p && !falg; m++)
        {
            if (m == for_m->FIN)
            {
                m = for_m->next->INI;
                for_m = for_m->next;
            }
            if (*m > valor)
            {
                falg = true;
                for (int* i = p - 1, *j = i - 1; j != m - 1; i--, j--)
                {
                    nodo* j_past = s;
                    nodo* i_prev = s;
                    for (; j_past != NULL && j_past->next != past; j_past = j_past->next);
                    for (; i_prev != NULL && i_prev->next != prev; i_prev = i_prev->next);
                    if (past != s)
                    {
                        if (j == past->INI - 1)
                        {
                            j = j_past->FIN - 1;
                            past = j_past;
                        }
                    }
                    if (i == prev->INI - 1)
                    {
                        i = i_prev->FIN - 1;
                        prev = i_prev;
                    }
                    swap(*i, *j);
                }
            }
        }
    }

    void pop(int valor)
    {
        bool found{ false }; nodo* i_ = s; int* spot = NULL; nodo* spotn = s;

        if (p - 1 == q || p == q)
        {
            cout << "TA VACIO" << endl;
        }


        else
        {
            for (int* i = q + 1; !found && i != p; i++)
            {
                if (i_->FIN == i)
                {
                    i = i_->next->INI;
                    i_ = i_->next;
                    spotn = spotn->next;
                }
                if (*i == valor)
                {
                    found = true;
                    spot = i;
                }

            }
            if (found)
            {


                if (p - 2 == t->INI - 1)
                {
                    nodo* j_spot = spotn;
                    nodo* i_spot = spotn;
                    for (int* j = spot, *i = j + 1; i != p; i++, j++)
                    {
                        if (i_spot != t)
                        {
                            if (i == i_spot->FIN)
                            {
                                i = i_spot->next->INI;
                                i_spot = i_spot->next;
                            }
                        }
                        if (j == j_spot->FIN)
                        {
                            j = j_spot->next->INI;
                            j_spot = j_spot->next;
                        }
                        swap(*i, *j);
                    }

                    nodo* tmp = t;
                    nodo* anterior = NULL;
                    for (nodo* i = s; i != t; i = i->next)
                    {
                        if (i->next == t)
                        {
                            anterior = i;
                        }
                    }
                    t = anterior;
                    anterior->next = NULL;
                    p = t->FIN;
                    delete  tmp;
                }
                else
                {
                    nodo* j_spot = spotn;
                    nodo* i_spot = spotn;
                    for (int* j = spot, *i = j + 1; i != p; i++, j++)
                    {
                        if (i_spot != t)
                        {
                            if (i == i_spot->FIN)
                            {
                                i = i_spot->next->INI;
                                i_spot = i_spot->next;
                            }
                        }
                        if (j == j_spot->FIN)
                        {
                            j = j_spot->next->INI;
                            j_spot = j_spot->next;
                        }
                        swap(*i, *j);
                    }
                    p--;
                }
            }
            else
            {
                cout << "No existe \n";
            }
        }
    }

    void find(nodo* i, int*& begin, int*& end)
    {
        bool comp1 = false;
        bool comp2 = false;
        for (int* k = i->INI; k != i->FIN; k++)
        {
            if (k == q + 1)
            {
                begin = k;
                comp1 = true;
            }
            if (k == p - 1)
            {
                end = k + 1;
                comp2 = true;
            }
        }
        if (!comp1)
        {
            begin = i->INI;
        }
        if (!comp2)
        {
            end = i->FIN;
        }

    }

    void print()
    {
        for (nodo* tmp = s; tmp; tmp = tmp->next)
        {
            int* start = NULL; int* end = NULL;
            find(tmp, start, end);
            for (; start != end; start++)
            {
                cout << *start << ",";
            }
            cout << "  ->  ";
        }
        cout << endl;
    }



};

int main() {
    Elementor A;
    A.push(23); 
    A.push(4); 
    A.push(42); 
    A.push(24); 
    A.push(1); 
    A.push(77); 
    A.push(77); 
    A.push(23); 
    A.pop(77);
    A.print();


    A.pop(77);
    A.print();
    A.pop(77);
    A.print();
    A.pop(77);
    A.print();
    A.pop(77);
    A.print();


    return 0;
}
