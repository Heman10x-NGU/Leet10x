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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
          return head;
        }

        int n=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
          n++;
          temp=temp->next;
        }
        n++;
       
        //as we took temp->next

        
        //now check if k is a multiple of n or not
        k=k%n;
        if(k==0){
          return head;
        }

        //now we are sure temp->next will be head

        temp->next=head;
        ListNode* pt=head;
        int i=0;
        while(i<n-k-1){
            pt=pt->next;
            i++;
        }
        //found the breaking point
         //cout<<pt->val<<endl;
        temp=pt->next;
        //as we need to return current pt ka next
        pt->next=NULL;

        return temp;
    }
};