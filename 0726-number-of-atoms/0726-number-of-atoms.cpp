class Solution {
   bool check_upper(char a){
        return a>='A' && a<='Z';
    }

    bool check_lower(char a){
        return a>='a' && a<='z';
    }
    bool check_digit(char a){
        return a>='0' && a<='9';
    }
   string find_key(string formula,int &i,int n){
    string s="";
    s+=formula[i];
    i++;
    while(i<n && check_lower(formula[i])){
        s+=formula[i];
        i++;
    }

    return s;
   }

   int find_num(string formula,int &i,int n){
    string s="";
    while(i<n && check_digit(formula[i])){
        s+=formula[i];
        i++;
    }
    if(s=="") return 1;

    return stoi(s);
   }


public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>> st;
        unordered_map<string,int> initial;
        st.push(initial);
        int i=0;
        int n=formula.size();
        while(i<n){
            if(check_upper(formula[i])){
                 string key=find_key(formula,i,n);
                 int num=find_num(formula,i,n);
                 st.top()[key]+=num;
            }
            else if(formula[i]=='('){
                st.push(initial);
                i++;
            }
            else if(formula[i]==')'){
                i++;
                if(i<n && check_digit(formula[i])){
                    int num=find_num(formula,i,n);
                    unordered_map<string,int> mp;
                    mp=st.top();
                    st.pop();
                    for(auto it:mp){
                        it.second=it.second*num;
                        st.top()[it.first]+=it.second;
                    }
                }
               else{
                  unordered_map<string,int> mp;
                    mp=st.top();
                    st.pop();
                 for(auto it:mp){
                        st.top()[it.first]+=it.second;
                    }
               }
            }
        }
        map<string,int> mp;
        for(auto it:st.top()){
            mp[it.first]=it.second;
        }

        string res="";
        for(auto it:mp){
            res+=it.first;
            if(it.second>1)
            res+=to_string(it.second);
        }
        return res;
    }
};