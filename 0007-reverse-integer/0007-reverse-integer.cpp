class Solution {
    string reverse(string s){
        int low=0;
        int high=s.size()-1;
        while(low<=high){
            swap(s[low],s[high]);
            low++;
            high--;
        }
        return s;
    }
public:
    int reverse(int x) {
        bool flag=0;
        long long temp=x;
        if(temp<0) {temp=-temp; 
        flag=1;
        }
        string s=to_string(x);
        if((s.size()==10 && s[9]>'2')|| (s.size()==11 && s[10]>'2')){
            return 0;
        }
        else{
             s=reverse(s);
        }
        long long res=stoll(s);
        if(res>INT_MAX) return 0;
        if(flag==1) res=-res;
        return (int)res;
    }
};