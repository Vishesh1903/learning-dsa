#include <iostream>
#include <string>

using namespace std;

enum class HeapType{
    MIN,
    MAX
};

enum class SortOrder{
    ASCENDING,
    DESCENDING
};

template <typename T>
class Heap{
    T *arr;
    int next_index;
    int capacity;
    HeapType type;
    public:
    Heap(): next_index(0), capacity(5), arr(new T[5]), type(HeapType::MIN){}
    Heap(int size, HeapType t): next_index(0), capacity(size), arr(new T[size]), type(t){}
    Heap(const Heap& h){
        this -> capacity = h.capacity;
        this -> next_index = h.next_index;
        this -> arr = new T[capacity];
        this -> type = h.type;
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
            this -> type = h.type;
            for(int i = 0; i < next_index; i++){
                this -> arr[i] = h.arr[i];
            }
        }
        return *this;
    }
    void heapifyUp(int insert_index){
        while(insert_index > 0){
            int parent_index = (insert_index - 1) / 2;
            bool comparison = this -> type == HeapType::MIN ? arr[insert_index] < arr[parent_index] : arr[insert_index] > arr[parent_index];
            if(comparison){
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
            if (left < next_index) {
                bool left_comparison = this -> type == HeapType::MIN ? arr[left] < arr[swap_index] : arr[left] > arr[swap_index];
                if(left_comparison) swap_index = left;
            }
            if (right < next_index) {
                bool right_comparison = this -> type == HeapType::MIN ? arr[right] < arr[swap_index] : arr[right] > arr[swap_index];
                if(right_comparison) swap_index = right;
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
    void pop(){
        if(isEmpty()){
            cout << "Heap is Empty" << endl;
            return;
        }
        swap(arr[0], arr[next_index - 1]);
        next_index--;
        heapifyDown();
    }
    int size(){
        return next_index;
    }
    bool isEmpty(){
        return size() == 0;
    }
    T top(){
        if(isEmpty()){
            return -1;
        }
        return arr[0];
    }
    int parentIndex(int curr_index){
        return (curr_index - 1) / 2;
    }
    void print(){
        for(int i = 0; i < next_index; i++){
            cout << arr[i] << ": ";
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left < next_index){
                cout << arr[left] << " ";
            }
            if(right < next_index){
                cout << arr[right];
            }
            cout << endl;
        }
    }
    ~Heap(){
        delete[] arr;
    }
};

void heapSort(vector<int>& p, SortOrder order){
    int n = p.size();
    if(!n){
        cout << "Array is Empty" << endl;
        return;
    }
    for(int i = 0;i < n - 1; i++){
        int j = i + 1;
        while(j > 0){
            int parent_index = (j - 1)/2;
            bool comparison = order == SortOrder::ASCENDING ? p[j] > p[parent_index] : p[j] < p[parent_index];
            if(comparison){
                swap(p[j], p[parent_index]);
                j = parent_index;
            }else{
                break;
            }
        }
    }
    for(int last_index = p.size() - 1; last_index > 0; last_index--){
        swap(p[0], p[last_index]);
        int index = 0;
        while(true){
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int swap_index = index;
            if(left < last_index){
                bool left_comparison = order == SortOrder::ASCENDING ? p[left] > p[swap_index] : p[left] < p[swap_index];
                if(left_comparison) swap_index = left;
            }
            if(right < last_index){
                bool right_comparison = order == SortOrder::ASCENDING ? p[right] > p[swap_index] : p[right] < p[swap_index];
                if(right_comparison) swap_index = right;
            }
            if(swap_index == index){
                break;
            }
            swap(p[index], p[swap_index]);
            index = swap_index;
        }
    }
}
int main(){
    Heap<int> h(10, HeapType::MAX);
    h.insert(12);
    h.insert(6);
    h.insert(5);
    h.insert(100);
    h.insert(1);
    h.insert(9);
    h.insert(0);
    h.insert(14);

    vector<int> p = {10, 5, 8, 1, 4};
    heapSort(p, SortOrder::ASCENDING);
    for(int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    h.print();
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    return 0;
}