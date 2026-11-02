class Solution {
public:
    int arrangeCoins(int n) {
        int level=0;
        while(n>level){
            level+=1;
            n-=level;
            
        }
        return level;
    }
};
