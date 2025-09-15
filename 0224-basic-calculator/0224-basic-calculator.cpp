class Solution {
    int check(char a){
        if(a=='+') return 1;

        return -1;
    }
public:
    int calculate(string s) {
        //initial value
        int num=0;
        int res=0;
        int sign=1;
        stack<int> st;
        for(auto ch:s){
            if(ch==' ') continue;
            if(ch=='('){
            st.push(res);
            st.push(sign);
            res=0;
            num=0;
            sign=1;
            }
            else if(ch==')'){
                res=(res+(num*sign));
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                 res=(res*a)+b;
                 num=0;
                 sign=1;
            }
            else if(ch!='+' && ch!='-'){
                num=((num*10)+(ch-'0'));
            }
            else{
                res=(res+(num*sign));
                num=0;
                sign=check(ch);
            }
        }
        res=(res+(sign*num));
        return res;
    }
};