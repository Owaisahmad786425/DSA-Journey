class Solution {
    string fun(long long curr,long long initial,int size){
        string temp1=to_string(initial);
        string temp2=to_string(curr);
        if(size%2==0&& temp1.size()>temp2.size()){
            return temp2+temp2+temp2.back();
        }
        else if(size%2==0 && temp1.size()<temp2.size()){
           string temp3=temp2.substr(0,temp2.size()-1);
           reverse(temp3.begin(),temp3.end());
           return temp2+temp3;
        }
        else if(size%2==0){
            string temp3=temp2;
            reverse(temp3.begin(),temp3.end());
            return temp2+temp3;
        }
        else if(size%2!=0 && temp1.size()>temp2.size()){
             return temp2+temp2;
        }
        else if(size%2!=0 && temp1.size()<temp2.size()){
            string temp3=temp2.substr(0,temp2.size()-1);
            reverse(temp3.begin(),temp3.end());
            return temp2.substr(0,temp2.size()-1)+temp3;
        }
        else{
            string temp3=temp2.substr(0,temp2.size()-1);
               reverse(temp3.begin(),temp3.end());
                  return temp2+temp3;
        }
    }
public:
    string nearestPalindromic(string n) {
    int num=n.size();
    if(num==2 && n[0]=='1'){
        if(n[1]=='0' || n[1]=='1') return "9";
        else if(stoll(n)>16) return "22";
        return "11";
    }
    string res1,res2,res3;
    long long diff1,diff2,diff3;
    if(num%2!=0){
        string s1=n.substr(0,(num/2)+1);
        string s2=s1.substr(0,s1.size()-1);
        reverse(s2.begin(),s2.end());
        res1=s1+s2;
        long long number=stoll(s1);
        long long num1=number+1;
        long long num2=number-1;
        res2=fun(num1,number,num);
        res3=fun(num2,number,num);
    }
    else{
        string s1=n.substr(0,num/2);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        res1=s1+s2;
          long long number=stoll(s1);
        long long num1=number+1;
        long long  num2=number-1;
        res2=fun(num1,number,num);
        res3=fun(num2,number,num);
    }
    if(res1==n){
        diff1=abs(stoll(n)-stoll(res2));
        diff2=abs(stoll(n)-stoll(res3));
        if(diff1==diff2){
            return res3;
        }
        else if(diff1>diff2){
            return res3;
        }
        else if(diff1<diff2){
            return res2;
        }
    }

    diff1=abs(stoll(n)-stoll(res1));
      diff2=abs(stoll(n)-stoll(res2));
        diff3=abs(stoll(n)-stoll(res3));

        if(diff1<diff2 && diff1<diff3){
            return res1;
        }
        else if(diff2<diff1 && diff2<diff3){
            return res2;
        }
        else if(diff3<diff1 && diff3<diff2){
            return res3;
        }
        else if((diff1==diff2 && stoll(res1)<stoll(res2)&& diff1<diff3) || (diff1==diff3 && stoll(res1)<stoll(res3) && diff1<diff2)){
            return res1;
        }
        else if((diff2==diff1 && stoll(res2)<stoll(res1) && diff2<diff3) || (diff2==diff3 && stoll(res2)<stoll(res3) && diff2<diff1)){
            return res2;
        }
        else if((diff3==diff1 && stoll(res3)<stoll(res1)&& diff3<diff2) || (diff3==diff2 && stoll(res3)<stoll(res2) && diff3<diff1)){
            return res3;
        }
        else if(diff1==diff2&& diff1==diff3){
            if(stoll(res1)<stoll(res2) && stoll(res1)<stoll(res3)) return res1;
            else if(stoll(res2)<stoll(res1) && stoll(res2)<stoll(res3)) return res2;
            else{
                return res3;
            }
        }
        return "";

     }
};