class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0, u=0;
        for(int i=0; i<moves.length(); i++) {
            if(moves[i]=='U') 
                ++u;
            else if (moves[i]=='D')
                --u;
            else if (moves[i]=='L')
                ++l;
            else
                --l;
        }
        return l==0 && u==0;
    }
};
