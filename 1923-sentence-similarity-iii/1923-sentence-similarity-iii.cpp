class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> word1,word2;
        string word;
        while(getline(ss1,word,' ')){
           word1.push_back(word);
        }
        while(getline(ss2,word,' ')){
            word2.push_back(word);
        }
        if(word1.size()==word2.size()){
            return word1==word2;
        }
     
        if(word1.size()<word2.size()){
            vector<string> temp=word1;
            word1=word2;
            word2=temp;
        }
        
        int first_index=0;
        int last_index=word2.size()-1;
        if(first_index==last_index){
            //this means only single element is there
            return word2[first_index]==word1[word1.size()-1] || word2[first_index]==word1[0];
        }

int i=0;
int j=0;
 while(j<word2.size() && i<word1.size()){
      if(word1[i]==word2[j]){
        j++;
      }
      i++;
 }
 if(j<word2.size()) return 0;

//write genrelize way that works on all testcases
//you are still away from main logic 
//i think i got the genrelize logic that works on all the test cases
//if both the sides are not equal means there is a glich to handle this case
int low1=0;
int high1=word2.size()-1;
int low2=0;
int high2=word1.size()-1;
while(low2<=high2){
    if(low1>high1){
        return true;
    }
    if(word1[low2]==word2[low1] && word1[high2]==word2[high1]){
         low2++;
         high2--;
         low1++;
         high1--;
    }
    else if(word1[low2]!=word2[low1] && word1[high2]!=word2[high1]){
        return false;
    }
    else if(word1[low2]==word2[low1] && word1[high2]!=word2[high1]){
        low2++;
        low1++;
    }
    else if(word1[low2]!=word2[low1] && word1[high2]==word2[high1]){
        high1--;
        high2--;
    }

}
return 1;
   }
};