#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

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
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 || l2){
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int value = val1 + val2 + carry;
        int digit = value%10;
        carry = value/10;
        curr->next = new ListNode(digit);
        curr = curr->next;
        if(l1){l1 = l1->next;}
        if(l2){l2 = l2->next;}
        }
        if(carry!=0){curr->next = new ListNode(carry);}
        return dummy->next;
    }
};

/*
O(n) time and O(n) space complexity.
Ok, so this one was a bit rough. First time working with linked lists in C++.
Still feels a bit clunky, but I got it working.
Also learnt about ternary operators.
*/

int main()
{
    Solution sol;
    // Example usage:
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    // Print the result
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}