class Solution {
string find_base(long long num, int base) {
    string res = "";
    while (num > 0) {
        res += (char)('0' + (num % base));
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}
    bool check_palindrome(string s){
    int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    long long kMirror(int k, int n) {
          
     int num=1;
     long long count=0;
     long long res=0;
    while(n>0){
        int half_len=(num+1)/2;
        long long min_num=pow(10,half_len-1);
        long long max_num=pow(10,half_len)-1;
        for(int i=min_num;i<=max_num;i++){
            string first_half=to_string(i);
            string second_half=first_half;
            reverse(second_half.begin(),second_half.end());
            string pal="";
            if(num%2==0){
                pal=first_half+second_half;
            }
            else{
                pal=first_half+second_half.substr(1);
            
            }
            long long check_num=stoll(pal);
            string check=find_base(check_num,k);
            if(check_palindrome(check)){
                res+=check_num;
                n--;
                if(n==0){
                    break;
                }
            }
        }
        num++;
    }
return res;

    }
};