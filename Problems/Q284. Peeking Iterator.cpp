/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int nextVal;      // stores the cached upcoming value
    bool has_next;    // tracks if there is a next element available

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has_next = Iterator::hasNext();
        if (has_next) {
            nextVal = Iterator::next();
        }
    }
    
    int peek() {
        return nextVal; //return value
    }
    
    int next() {
        int temp = nextVal; 
        has_next = Iterator::hasNext();
        if (has_next) {
            nextVal = Iterator::next();
        }
        
        return temp;
    }
    
    bool hasNext() const {
        return has_next;
    }
};
