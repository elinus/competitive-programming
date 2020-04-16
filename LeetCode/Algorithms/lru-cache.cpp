#include <bits/stdc++.h>

using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        if (map_.find(key) != map_.end()) {
            // It key exists, update it.
            const auto value = map_[key]->second;
            update(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // If cache is full while inserting, remove the last one.
        if (map_.find(key) == map_.end() && list_.size() == capa_) {
            auto del = list_.back(); list_.pop_back();
            map_.erase(del.first);
        }
         update(key, value);
    }
    
private:
    list<pair<int, int>> list_; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
    int capa_;
    
    // Update (key, iterator of (key, value)) pair
    void update(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }
};

int main (int argc, char *argv[]) {

    LRUCache* obj = new LRUCache(2);
    obj->put(2, 1);
    obj->print();
    obj->put(3, 2);
    obj->print();
    cout << obj->get(3) << "\n";
    obj->print();
    cout << obj->get(2) << "\n";
    obj->print();
    obj->put(4, 3);
    obj->print();
    cout << obj->get(2) << "\n";
    obj->print();
    //cout << "key = " << obj->get(3) << "\n";
    //obj->print();
    return 0;
}
