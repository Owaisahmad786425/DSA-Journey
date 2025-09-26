class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> initial,unlocked;
        int n=s.size();
        if(n%2!=0) return false;
        for(int i=0;i<n;i++){
            if(locked[i]=='1'){
                if(s[i]==')' && initial.empty() && unlocked.empty()) return false;
                else if(s[i]==')' && !initial.empty()) initial.pop();
                else if(s[i]==')' && initial.empty() && !unlocked.empty()) unlocked.pop();

                if(s[i]=='(') initial.push(i);
            }
            else if(locked[i]=='0') unlocked.push(i);
        }

        while(!initial.empty() && !unlocked.empty()){
            if(initial.top()> unlocked.top()) return false;

            initial.pop();
            unlocked.pop();
        }

        if(initial.empty() && !unlocked.empty()) return unlocked.size()%2==0;
        
        else if(!initial.empty() && unlocked.empty()) return false;

        return true;
    }
};