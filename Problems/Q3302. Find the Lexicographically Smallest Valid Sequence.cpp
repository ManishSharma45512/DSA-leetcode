class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<int> last(m,-1);

        int j=m-1;
        for(int i=n-1;i>=0;i--){ //Tracking backward for the sequence
            if(j>=0 && word1[i]==word2[j]){
                last[j--]=i;
            }
        }

        vector<int> res;

        //checking for our free skip
        int skip=0;
        j=0;
        for(int i=0;i<n;i++){
            if(j==m) break;

            if(word1[i]==word2[j] || (skip==0 && (j==m-1 || i<last[j+1]))){
                if(word1[i]!=word2[j]) skip++;
                res.push_back(i);
                j++;
            }

        }

        return j == m ? res : vector<int>(); //if j==m then we don't use our skip so our result should be empty

    }
};
