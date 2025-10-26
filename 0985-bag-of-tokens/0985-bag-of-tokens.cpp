class Solution {
    bool possible(int a,int b){
        return b>=a;
    }
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        int n=tokens.size();
        int idx1=0;
        int idx2=n-1;
        int score=0;
        while(idx1<=idx2){
            if(idx1==idx2 &&!possible(tokens[idx1],power)){
                break;
            }
            else if(possible(tokens[idx1],power)){
                power-=tokens[idx1];
                idx1++;
                score++;
            }
            else if(score>=1){
                power+=tokens[idx2];
                idx2--;
                score--;
            }
            else break;
        }
        return score;
    }
};