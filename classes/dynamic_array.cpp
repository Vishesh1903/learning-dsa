#include <iostream>

using namespace std;

class DynamicArray
{
    int *data;
    int next_index;
    int capacity;

public:
    DynamicArray() : data(new int[5]), next_index(0), capacity(5) {};
    DynamicArray(const DynamicArray &d1){
        data = new int[d1.capacity];
        for (int i = 0; i < d1.next_index; i++)
        {
            data[i] = d1.data[i];
        }
        next_index = d1.next_index;
        capacity = d1.capacity;
    }
    ~DynamicArray()
    {
        delete[] data;
    }
    void operator=(const DynamicArray &d1)
    {
        if (this == &d1)
        {
            return;
        }
        delete[] data;
        data = new int[d1.capacity];
        for (int i = 0; i < d1.next_index; i++)
        {
            data[i] = d1.data[i];
        }
        next_index = d1.next_index;
        capacity = d1.capacity;
    }
    void add(int element)
    {
        if (next_index == capacity)
        {
            int *new_data = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity *= 2;
        }
        data[next_index] = element;
        next_index++;
    }

    void add(int element, int i)
    {
        if (i < next_index)
        {
            data[i] = element;
            next_index = i + 1;
        }
        else if(i == next_index)
        {
            add(element);
        }else{
            return;
        }
    }
    int getElement(int index)
    {
        if (index < 0 || index >= next_index)
        {
            return -1;
        }
        else
        {
            return data[index];
        }
    }
    void print()
    {
        for (int i = 0; i < next_index; i++)
        {
            cout << data[i] << " ";
        }
    }
    int getCapacity() const
    {
        return capacity;
    }
};

int main()
{
    DynamicArray d1;
    d1.add(1);
    d1.add(2);
    d1.add(3);
    d1.add(4);
    d1.add(5);
    d1.add(6);
    d1.add(7);
    d1.print();
    cout << d1.getCapacity();
    cout << endl;
    d1.add(8, 10);
    d1.print();
    cout << d1.getCapacity();

    return 0;
}