class MyLinkedList {
private:
    vector<int> LL;

public:
    MyLinkedList() {
        // Constructor
    }
    
    int get(int index) {
        if (index >= LL.size() || index < 0) return -1;

        
        return LL[index];
    }
    
    void addAtHead(int val) {
        LL.insert(LL.begin(), val);
    }
    
    void addAtTail(int val) {
        LL.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > LL.size() || index < 0) return;

        LL.insert(LL.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if (index >= LL.size() || index < 0) return;

        LL.erase(LL.begin() + index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
