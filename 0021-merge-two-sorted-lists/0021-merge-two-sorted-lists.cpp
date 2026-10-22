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
        ListNode dummy(0);
        ListNode* result = &dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != nullptr || temp2 != nullptr){
            if(temp1 != nullptr && temp2 != nullptr && temp1 -> val <= temp2 -> val){
                result -> next = temp1;
                result = temp1;
                temp1 = temp1 -> next;
            }
            else if(temp1 == nullptr && temp2 != nullptr){
                if(temp2 != nullptr){
                    result -> next = temp2;
                }
                return dummy.next;
            }
            else if(temp2 == nullptr && temp1 != nullptr){
                if(temp1 != nullptr){
                    result -> next = temp1;
                }
                return dummy.next;
            }
            else{
                result -> next = temp2;
                result = temp2;
                temp2 = temp2 -> next;
            }
        }
        return dummy.next;
    }
};