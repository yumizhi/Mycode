#include<iostream>
#include<vector>
using namespace std;

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
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int forward = 0;
        ListNode* head = NULL;
        ListNode* result = NULL;
        while(l1 != NULL || l2 != NULL){
            int tmp1,tmp2;
            if(l1 == NULL){tmp1 = 0;tmp2 = l2->val;}
            else if(l2 == NULL){tmp1 = l1->val;tmp2 = 0;}
            else{
                tmp1 = l1->val;
                tmp2 = l2->val;
            }
            int res = tmp1 + tmp2 + forward;
            forward = 0;
            if(res > 9){
                res = res - 10;
                forward = 1;
            }
            
            if(head == NULL){
                head = new ListNode(res);
                result = head;
            }
            else{
                head->next = new ListNode(res);
                head = head->next;
            }
            l1 = l1->next; l2 = l2->next;
        }
        if(l1 == NULL&&l2 == NULL && forward == 1){
            ListNode p(1);
            head->next = &p;
        }
        return result;
    }
};

int main(){
    Solution t;
    ListNode* l1, *l2;

    ListNode p(0);
    l1 = &p;
    ListNode q(1);
    l2 = &q;
    ListNode* res = t.addTwoNumbers(l1,l2);
    while(res){
        // if(res->next == NULL){ cout<<res->val;break;}
       
        // else{cout<<res->val; res = res->next;}
        cout<<res->val; res = res->next;
    }
    return 0;
}