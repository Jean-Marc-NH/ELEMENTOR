#include <iostream>

using namespace std;

struct Nodo {
    int* data;
    Nodo* next;
    int index;

    Nodo() {
        data = new int[10];
        next = nullptr;
        index = 0;
    }
};

struct Elementor {
    Nodo* head;

    Elementor() {
        head = nullptr;
    }

    void add(int value) {
        Nodo* curr = head;
        Nodo* prev = nullptr;
        while (curr != nullptr && curr->index == 10) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            curr = new Nodo;
            curr->next = head;
            head = curr;
        }
        int* ptr = curr->data;
        while (ptr < curr->data + curr->index && *ptr < value) {
            ptr++;
        }
        for (int* i = curr->data + curr->index; i > ptr; i--) {
            *i = *(i - 1);
        }
        *ptr = value;
        curr->index++;
    }

    void del(int value) {
        Nodo* prev = nullptr;
        Nodo* curr = head;
        while (curr != nullptr) {
            int* ptr = curr->data;
            while (ptr < curr->data + curr->index && *ptr != value) {
                ptr++;
            }
            if (ptr < curr->data + curr->index) {
                for (int* i = ptr; i < curr->data + curr->index - 1; i++) {
                    *i = *(i + 1);
                }
                curr->index--;
                if (curr->index == 0) {
                    if (prev == nullptr) {
                        head = curr->next;
                    }
                    else {
                        prev->next = curr->next;
                    }
                    Nodo* temp = curr;
                    curr = curr->next;
                    delete[] temp->data;
                    delete temp;
                }
                else {
                    curr = curr->next;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool find(int value, Nodo** result) {
        Nodo* curr = head;
        while (curr != nullptr) {
            int* ptr = curr->data;
            while (ptr < curr->data + curr->index && *ptr != value) {
                ptr++;
            }
            if (ptr < curr->data + curr->index) {
                *result = curr;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void print() {
        Nodo* curr = head;
        while (curr != nullptr) {
            int* ptr = curr->data;
            while (ptr < curr->data + curr->index) {
                cout << *ptr << " ";
                ptr++;
            }
            cout << "->";
            curr = curr->next;
        }
    }
};

int main() {
    Elementor list;
    list.add(5);
    list.add(3);
    list.add(8);
    list.add(1);
    list.add(12);
    list.add(13);
    list.add(14);
    list.add(15);
    list.add(18);
    list.add(19);
    list.add(-1);
    list.add(-5);
    list.print(); 
    cout << "\n";
    list.del(3);
    list.print();
    cout << "\n";
    Nodo* found = nullptr;
    if (list.find(100, &found)) {
        cout << "Found: " << *(found->data + 1) << endl; 
    }
    else {
        cout << "Element not found" << endl;
    }
    return 0;
}
