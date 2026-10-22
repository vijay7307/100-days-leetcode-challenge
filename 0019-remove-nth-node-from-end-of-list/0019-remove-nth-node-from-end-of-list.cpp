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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }
        if(n == count){
            return head -> next;
        }
        int num = count - n;
        temp = head;
        while(num > 1){
            temp = temp -> next;
            num--;
        }
        temp -> next = temp -> next -> next;
        return head;
    }
};