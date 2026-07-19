class Solution {
public:
    string smallestSubsequence(string s) {
        //finding the last index of the character appeared
        int lastIdx[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i;//store last occured valued in its alpabet order 'b'-'a'=1 lastIdx[1]=i last occured index
        }

        string ans = ""; // monotonic stack
        bool visited[26] = {false}; //tracking if the char is visited or not

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];

            if (visited[curr - 'a']) continue;//if visited then continue

//now maintaining monotonic property
//if ans is not empty AND ans's back is  more then current value for eg. b>a AND back is visited eg. b is visited
//then back is marked as not visited and poped -> current vallue is added to the back and marked as visited
            while (!ans.empty() && ans.back() > curr && lastIdx[ans.back() - 'a'] > i) {
                visited[ans.back() - 'a'] = false; // Mark it as removed
                ans.pop_back(); // Pop from stack
            }

            // Add the current character to our stack and mark it as picked
            ans.push_back(curr);
            visited[curr - 'a'] = true;
        }

        return ans;
    }
};
