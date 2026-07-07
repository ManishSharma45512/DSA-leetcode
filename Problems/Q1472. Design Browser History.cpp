class BrowserHistory {
private:
    vector<string> history;
    int curr = 0; // Tracks the current active index in the vector

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0; 
    }
    
    void visit(string url) {
        // Clear any forward history beyond our current position
        history.resize(curr + 1);
        
        history.push_back(url);
        curr++; // Move current index to the newly added page
    }
    
    string back(int steps) {
        //we never go below index 0 (the homepage)
        curr = max(0, curr - steps);
        
        // Return the page at our new position
        return history[curr];
    }
    
    string forward(int steps) {
        int maxIndex = history.size() - 1;
        
        //we never go beyond the maximum available history index
        curr = min(maxIndex, curr + steps);
        
        // Return the page at our new position
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
