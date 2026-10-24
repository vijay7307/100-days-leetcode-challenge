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
    void reorderList(ListNode* head) {
        if(head == nullptr){
            return ;
        }
        
        //find mid
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //reverse the half
        ListNode* prev = nullptr;
        ListNode* curr = slow -> next;
        slow -> next = nullptr;
        while(curr != nullptr){
            ListNode* nextNode = curr -> next;
            
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        //merge
        ListNode* first = head;
        ListNode* second = prev;
        while(second != nullptr){
            ListNode* firstNext = first -> next;
            ListNode* secondNext = second -> next;
            
            first -> next = second;
            second -> next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};