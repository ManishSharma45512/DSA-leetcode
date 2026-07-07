class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> freq, curr;
        for(string& word : words) freq[word]++;

        int len = s.size();
        int n = words.size();
        int wordsize = words[0].size();
        int winSize = wordsize * n;

        vector<int> ans;
        if (len < winSize) return ans;

        for(int i = 0; i < wordsize; ++i){
            int left = i; 
            int st = i;
            curr.clear(); // Clear the map instead of re-allocating or copying freq
            int count = 0; // Tracks the number of valid words currently inside the window

            do {
                string currword = s.substr(st, wordsize);
                
                if(freq.count(currword)) {
                    curr[currword]++;
                    count++;
                    
                    // If a word's count exceeds its frequency in 'words',
                    // slide the 'left' pointer forward to shrink the window
                    while(curr[currword] > freq[currword]) {
                        string leftword = s.substr(left, wordsize);
                        curr[leftword]--;
                        count--;
                        left += wordsize;
                    }
                    
                    // If the number of valid words matches 'n', record the 'left' index
                    if(count == n) {
                        ans.push_back(left);
                    }
                } else {
                    // Invalid word: reset window counters and jump 'left' past this word
                    curr.clear();
                    count = 0;
                    left = st + wordsize;
                }

                st += wordsize;

            } while(st + wordsize <= len); 
        }

        return ans;
    }
};
