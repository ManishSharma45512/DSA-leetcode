A Visual Example:::


If word = "heavyweight" and pattern = "wave":

word.find("wave") scans the string.

It can't find "wave" anywhere, so it returns string::npos.

The condition evaluates to: string::npos != string::npos, which is false. The if block is skipped.


::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        if (patterns.empty() || word.empty()) return 0;

        int count = 0;
        for (const string& pattern : patterns) {
            // string::npos is returned when the substring is NOT found
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};



