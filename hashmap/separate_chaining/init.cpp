#include <iostream>
#include <string>

using namespace std;

template <typename V>

class Map;

template <typename V>

class MapNode{

    friend class Map<V>; 
    private:
    string key;
        V data;
        MapNode<V>* next;

    public:
        MapNode(string key, V data): key(key), data(data), next(nullptr) {}
        
        ~MapNode(){
            delete next;
        }
};

template <typename V>

class Map{
    private:
        MapNode<V>** buckets;
        int count;
        int num_buckets;

        int getBucketIndex(string key){
            int hash_code = 0;
            int base = 1;
            int p = 37; 
            for (int i = key.size() - 1; i >= 0; i--){
                hash_code += key[i] * base;
                hash_code %= num_buckets; 
                base = (base * p) % num_buckets;
            }
            return hash_code % num_buckets;
        }
        void rehash(){
            double load_factor = (1.0 * count) / num_buckets;
            if(load_factor > 0.7){
                MapNode<V> ** temp = buckets;
                int old_bucket_size = num_buckets;
                num_buckets *= 2;
                buckets = new MapNode<V>*[num_buckets];
                count = 0;
                for(int i = 0; i < num_buckets; i++){
                    buckets[i] = nullptr;
                }
                for(int i = 0; i < old_bucket_size; i++){
                    MapNode<V> * head = temp[i];
                    while(head){
                        insert(head -> key, head -> data);
                        head = head -> next;
                    }
                }
                for(int i = 0; i < old_bucket_size; i++){
                    delete temp[i];
                }
                delete []temp;
            }
        }

    public:
        Map(){
            count = 0;
            num_buckets = 5;
            buckets = new MapNode<V>* [num_buckets];
            for (int i = 0; i < num_buckets; i++) {
                buckets[i] = nullptr;
            }
        }
        ~Map(){
            for(int i = 0; i < num_buckets; i++){
                delete buckets[i];
            }
            delete[] buckets;
        }

        int size(){
            return count;
        }
        V at(string key){
            int index = getBucketIndex(key);
            MapNode<V>* head = buckets[index];
            while(head){
                if(head -> key == key){
                    return head -> data;
                }
                head = head -> next;
            }
            cout << "Key is not present" << endl;
            return 0;
        }
        void insert(string key, V data){
            int index = getBucketIndex(key);
            MapNode<V> * head = buckets[index];
            while(head){
                if(head -> key == key){
                    head -> data = data;
                    return;
                }
                head = head -> next;
            }
            MapNode<V> * node = new MapNode<V>(key, data);
            node -> next = buckets[index];
            buckets[index] = node;
            count++;
            rehash();
        }

        V remove(string key){
            int index = getBucketIndex(key);
            MapNode<V> * head = buckets[index];
            MapNode<V> * prev = NULL;
            while(head){
                if(head -> key == key){
                    int node_val = head -> data;
                    if(!prev){
                        buckets[index] = head -> next;
                    }else{
                        prev -> next = head -> next;   
                    }
                    head -> next = nullptr;
                    delete head;
                    return node_val;
                }
                prev = head;
                head = head -> next;
            }
            cout << "Key is not Present" << endl;
            return 0;
        }

        double getLoadFactor(){
            return (1.0 * count) / num_buckets;
        }

};

int main(){
    Map<int> mp;
    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        mp.insert(key, value);
        // cout << mp.getLoadFactor() << endl;
        cout << key << " " << mp.at(key) << endl;
    }

    cout << endl;
    cout << "REMOVAL" << endl;
    cout << "Removed" << mp.remove("abc1") << endl;
    cout << "Removed" << mp.remove("abc7") << endl;

    cout << "2nd Traversal" << endl;
    cout << endl;

    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        // cout << mp.getLoadFactor() << endl;
        cout << key << " " << mp.at(key) << endl;
    }
    return 0;
}