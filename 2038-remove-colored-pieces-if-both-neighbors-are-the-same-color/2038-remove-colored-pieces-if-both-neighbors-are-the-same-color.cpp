class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int alice_turn=0;
        int bob_turn=0;
        int i=0;
        while(i<n){
            int cnt1=0;
            int cnt2=0;
            while(i<n && colors[i]=='A'){
                cnt1++;
                i++;
            }
            alice_turn+=max(0,cnt1-2);
            while(i<n && colors[i]=='B'){
                cnt2++;
                i++;
            }
            bob_turn+=max(0,cnt2-2);
        }
        return alice_turn>bob_turn;
    }
};