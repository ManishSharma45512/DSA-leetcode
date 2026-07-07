class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.length()==0) return 0;
        unordered_map<char,int> freq;
        freq.insert({'b',0});
        freq.insert({'a',0});
        freq.insert({'l',0});
        freq.insert({'o',0});
        freq.insert({'n',0});


        for(char c: text){
            if(c=='b' || c=='B') freq['b']++;
            else if(c=='a' || c=='A') freq['a']++;
            else if(c=='l' || c=='L') freq['l']++;
            else if(c=='o' || c=='O') freq['o']++;
            else if(c=='n' || c=='N') freq['n']++;
            
        }

        int c=0;
        
        while(freq['b']>=1 && freq['a']>=1 && freq['l']>=2 && freq['o']>=2 && freq['n']>=1){ 
            c++;
            freq['b']--;
            freq['a']--;
            freq['l']-=2;
            freq['o']-=2;
            freq['n']--;
        }

        return c;
        
    }
};
