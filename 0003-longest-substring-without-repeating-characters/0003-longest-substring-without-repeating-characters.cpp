class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int n=s.size();
        if(s.size()==0) return 0;
        int l=0,r=0;
        int res=0;
        
        while(r<n){
            freq[s[r]]++;

            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            res=max(res,(r-l+1));
            r++;
        }
        return res;
    }
};