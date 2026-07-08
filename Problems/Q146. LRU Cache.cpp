class LRUCache {
private:
    int cap; // Store the maximum allowed capacity
    
    // The list stores pairs of {key, value}
    // front=most used and back=least used
    list<pair<int, int>> orderList;
    
    // The map stores the key, and its value is an iterator pointing to the list node
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        cap = capacity; // Initialize the capacity boundary
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {//If key doesn't exist, return -1
            return -1;
        }
        
        // If it exists, we must mark it as "Most Recently Used"
        // Move its corresponding node to the front of the list
        auto listIt = cacheMap[key];
        int value = listIt->second;
        
        orderList.erase(listIt);               // Remove from current position
        orderList.push_front({key, value});    // Push to the front
        cacheMap[key] = orderList.begin();     // Update the map pointer
        
        return value;
    }
    
    void put(int key, int value) {
        // if Key already exists -> Update value and move it to the front
        if (cacheMap.find(key) != cacheMap.end()) {
            orderList.erase(cacheMap[key]);
            orderList.push_front({key, value});
            cacheMap[key] = orderList.begin();
            return;
        }
        
        //else Key is brand new -> Check if we are out of space
        if (cacheMap.size() == cap) {
            // Evict the Least Recently Used item (from the back of the list)
            int lruKey = orderList.back().first;
            cacheMap.erase(lruKey); // Erase from map
            orderList.pop_back();   // Erase from list
        }
        
        // Insert the new item at the front of our order tracking
        orderList.push_front({key, value});
        cacheMap[key] = orderList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
