class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
       vector<string> units={
       "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
       };

       vector<string> tens={
        "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
       };
       vector<string> notations={
        "","Thousand","Million","Billion"
       };
       int index=0;
      vector<string> store;
       while(num>0){
        string res="";
        if(num%1000==0){
            num/=1000;
            index++;
            continue;
        }
            int part=num%1000;
            if(part>=100){
                res+=units[part/100]+" "+"Hundred"+" ";
                part%=100;
            }
            if(part>=20){
                res+=tens[part/10]+" ";
                part%=10;
            }
            if(part>0){
                res+=units[part]+" ";
            }
            num/=1000;
            res+=notations[index];
            index++;
            while(res.back()==' ') res.pop_back();
            
            res+=" ";
            store.push_back(res);
        
       }
       string res="";
       for(int i=store.size()-1;i>=0;i--){
        res+=store[i];
       }
       res.pop_back();
       return res;
    }
};