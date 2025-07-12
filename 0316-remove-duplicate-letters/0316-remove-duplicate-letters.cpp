class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> decision(26,0);
        //hash it 
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        //hash done now main logic
        string res="";
        for(int i=0;i<n;i++){
            if(decision[s[i]-'a']){
                freq[s[i]-'a']--;
                continue;
            }

            while(res.size()>0 && res.back()>s[i] && freq[res.back()-'a'] >0){
                decision[res.back()-'a']=false;
                res.pop_back();
            }

            res.push_back(s[i]);
            decision[s[i]-'a']=true;
            freq[s[i]-'a']--;
        }
        return res;

    }
};