#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Heap{
    T *arr;
    int next_index;
    int capacity;
    string implementation;
    public:
    Heap(): next_index(0), capacity(5), arr(new T[5]), implementation("min_heap"){}
    Heap(int size, string impltn): next_index(0), capacity(size), arr(new T[size]), implementation(impltn){}
    Heap(const Heap& h){
        this -> capacity = h.capacity;
        this -> next_index = h.next_index;
        this -> arr = new T[capacity];
        this -> implementation = h.implementation;
        for(int i = 0; i < next_index; i++){
            this -> arr[i] = h.arr[i];
        }
    }
    Heap& operator=(const Heap& h){
        if(this != &h){
            delete[] arr;
            this -> capacity = h.capacity;
            this -> next_index = h.next_index;
            this -> arr = new T[capacity];
            this -> implementation = h.implementation;
            for(int i = 0; i < next_index; i++){
                this -> arr[i] = h.arr[i];
            }
        }
        return *this;
    }
    void heapifyUp(int insert_index){
        while(insert_index > 0){
            int parent_index = (insert_index - 1) / 2;
            bool comparison = this -> implementation == "min_heap" ? arr[insert_index] < arr[parent_index] : arr[insert_index] > arr[parent_index];
            if(){
                swap(arr[insert_index], arr[parent_index]);
                insert_index = parent_index;
            }else{
                break;
            }
        }
    }

    void heapifyDown(){
        int index = 0;
        while(true){
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int swap_index = index;
            bool left_comparison = this -> implementation == "min_heap" ? arr[left] < arr[swap_index] : arr[left] > arr[swap_index];
            bool right_comparison = this -> implementation == "min_heap" ? arr[right] < arr[swap_index] : arr[right] > arr[swap_index];
            if (left < next_index && left_comparison) {
                swap_index = left;
            }
            if (right < next_index && arr[right] < arr[swap_index]) {
                swap_index = right;
            }
            if (swap_index == index) {
                break;
            }
            swap(arr[index], arr[swap_index]);
            index = swap_index;    
        }
    }

    void insert(T data){
        if(next_index == capacity){
            capacity = 2 * capacity;
            T* temp = new T[capacity];
            for(int i = 0; i < next_index; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        int insert_index = next_index;
        arr[insert_index] = data;
        next_index++;
        heapifyUp(insert_index);
    }
    void remove(){
        if(isEmpty()){
            cout << "Heap is Empty" << endl;
            return;
        }
        swap(arr[0], arr[next_index]);
        next_index--;
        heapifyDown();
    }
    int size(){
        return next_index;
    }
    bool isEmpty(){
        return size() == 0;
    }
    T parentIndex(int curr_index){
        return (curr_index - 1) / 2;
    }
    ~Heap(){
        delete[] arr;
    }
};

int main(){
    return 0;
}