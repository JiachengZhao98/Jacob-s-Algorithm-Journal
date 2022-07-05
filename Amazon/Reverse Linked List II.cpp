#include "iostream"
#include "vector"
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // recording part

        ListNode* begin = head;
        ListNode* end = head;
        ListNode* pre;
        int count = 1;
        if (left == 1) {
            pre = nullptr;
        }
        else if (left > 1) {
            while (count != left - 1) {
                begin = begin->next;
                count++;
            }
            pre = begin;               // get the previous node of node indexed "left"
            begin = begin->next;       // get the node indexed "left"
        }
        count = 1;
        if (right == 1) {
            return head;
        }
        else if (right > 1) {
            while (count != right) {
                end = end->next;        // get the node indexed "right"
                count++;
            }
        }
        ListNode* cur = begin->next;
        ListNode* temp;
        ListNode* prev = begin;

        while (prev != end) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }                             // after the loop we can see that cur is the node after the node "end" in the original order
        if(pre) pre->next = end;
        begin->next = cur;
        if (left == 1) {
            return end;
        }
        else return head;
    }
};