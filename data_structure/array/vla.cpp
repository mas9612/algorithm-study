#include <iostream>

using namespace std;

// variable length array class
class vla
{
    int capacity;
    int size;
    int* array;

public:
    vla(int size) : capacity(size) {
        this->size = 0;
        array = new int[capacity];
    }
    int get_size() { return this->size; }
    int get_capacity() { return this->capacity; }

    void add(int num) {
        if ((size + 1) > capacity) {
            this->capacity *= 2;
            int* new_array = new int[this->capacity];
            for (int i = 0; i < this->size; ++i)
                new_array[i] = this->array[i];
            delete this->array;
            this->array = new_array;
        }
        this->array[this->size] = num;
        ++this->size;
    }

    void print() {
        cout << "size: " << get_size() << '\n';
        cout << "capacity: " << get_capacity() << '\n';
        cout << "[ ";
        for (int i = 0; i < this->size; ++i)
            cout << this->array[i] << " ";
        cout << "]\n\n";
    }
};

int main()
{
    int size;
    cin >> size;
    vla* array = new vla(size);

    array->print();

    array->add(1);
    array->print();

    array->add(2);
    array->print();

    array->add(3);
    array->print();

    array->add(4);
    array->print();

    array->add(1);
    array->print();

    array->add(2);
    array->print();

    array->add(3);
    array->print();

    array->add(4);
    array->print();
}

