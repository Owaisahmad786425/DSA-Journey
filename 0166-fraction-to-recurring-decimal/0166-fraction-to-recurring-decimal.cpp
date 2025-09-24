class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int,int> mp;
        if(numerator==0) return "0";
        long long nume=numerator;
        long long den=denominator;
         bool check1=0;
         bool check2=0;
        if(numerator<0){
            check1=1;
            nume=abs(nume);
        }
        if(denominator<0){
            den=abs(den);
            check2=1;
        }
        if(nume%den==0){
            string store=to_string((nume/den));
            if((check2 && check1) ||(!check1 &&!check2)) return store;
         
             reverse(store.begin(),store.end());
            store.push_back('-');
            reverse(store.begin(),store.end());
            return store;
        
        }
        long long digit=nume;
        bool flag=0;
        int idx=-1;
        long long rem;
        string store="";
        int index=-1;
        while(true){
            rem=(digit%den);
            int val=digit/den;
            store+=to_string(val);
            if(rem==0) break;
            else if(mp.find(rem)!=mp.end()){
                idx=mp[rem];
                break;
            }

            if(!flag && rem>0){
                store=store+".";
                index++;
                flag=1;
            }
            mp[rem]=store.size();
            digit=(rem*10);
        }
        if(idx==-1){
            if((check2 && check1)||  (!check1 &&!check2)) return store;
        
            reverse(store.begin(),store.end());
            store.push_back('-');
            reverse(store.begin(),store.end());
            return store;
        }
        string res="";
        for(int i=0;i<store.size();i++){
            if(i==idx){
                res+="(";
                res+=store[i];
                continue;
            }
               res+=store[i];
        } 
        res+=")";
      if((check2 && check1)||  (!check1 &&!check2)) return res;
   
     reverse(res.begin(),res.end());
            res.push_back('-');
            reverse(res.begin(),res.end());
            return res;


    }
};