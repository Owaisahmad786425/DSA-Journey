/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        bool flag=0;
            if(list1==NULL) return list2;
         else if(list2==NULL) return list1;
        ListNode* temp1;
        ListNode* temp2;
          if(list1->val<=list2->val){
             flag=1;
            temp1=list1;
            temp2=list2;
          }
          else if(list1->val>list2->val){
            temp1=list2;
      temp2=list1;
          }
         while(temp1->next!=nullptr && temp2){
            if(temp1->next!=NULL && temp1->next->val>=temp2->val){
                ListNode* temp3=temp1->next;
                temp1->next=temp2;
                temp2=temp2->next;
                temp1->next->next=temp3;
                temp1=temp1->next;
            }

            else{
                temp1=temp1->next;
            }
         }
            if(temp2!=NULL) temp1->next=temp2;

         if(flag==1) return list1;
         return list2;
    }
};