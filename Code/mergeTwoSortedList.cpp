/**
 * leetcode.com.
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
    void merge(ListNode*& l1, ListNode*& l2, ListNode*& p) {
        if (l1->val <= l2->val) {
            p = l1;
            l1 = l1->next;
        } else {
            p = l2;
            l2 = l2->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        
        if (l1 == nullptr)
            head = l2;
        else if (l2 == nullptr)
            head = l1;
        else if (l1 != nullptr && l2 != nullptr) {
            ListNode* p = nullptr, *temp;
            
            if (l1->val <= l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }
            
            p = head;
            
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val <= l2->val) {
                    temp = l1;
                    l1 = l1->next;
                } else {
                    temp = l2;
                    l2 = l2->next;
                }
                
                p->next = temp;
                p = p->next;
            }
            
            if (l1 != nullptr)
                p->next = l1;
            else if (l2 != nullptr)
                p->next = l2;
        }
        
        return head;
    }
};