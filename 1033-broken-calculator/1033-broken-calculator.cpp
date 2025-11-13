class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target<=startValue) return startValue-target;
 int store=target;
        stack<int> st;
        while(startValue<target){
          st.push(target);
          target=ceil((double)target/(double)2);
          if(startValue>=target) st.push(target);
        }
        int operations=0;
        while(!st.empty()){
          int top=st.top();
          if(top<=startValue){
            operations+=(startValue-top);
            startValue=top;
            st.pop();
            continue;
          }
          int val=startValue*2;
          operations++;
          operations+=(val-top);
          startValue=top;
          st.pop();
        }
        return operations;
    }
};