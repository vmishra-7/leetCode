class LRUCache {
private:
    unordered_map<int, int> cache;
    int capacity;
    list<int> l;
    unordered_map<int, list<int>::iterator> lPosition;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key) > 0) {
            l.erase(lPosition[key]);
            l.push_front(key);
            lPosition[key] = l.begin();
            return cache[key];
        } return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key) > 0) {
            l.erase(lPosition[key]);
        } else if(l.size() >= capacity) {
            int temp = l.back();
            l.pop_back();
            cache.erase(temp);
            lPosition.erase(temp);
        }
        cache[key] = value;
        l.push_front(key);
        lPosition[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */