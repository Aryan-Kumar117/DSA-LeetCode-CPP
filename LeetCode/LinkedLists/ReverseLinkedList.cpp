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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;

        while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        } 
        return q;
    }
};

/*
O(n) time complexity and O(1) space complexity.
Learnt about the three pointers technique for reversing a linked list.
*/

int main() {
    Solution sol;
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* result = sol.reverseList(head);
    
    // Print the result
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}