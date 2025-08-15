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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;

        for(int i = 0; i <= n; i++){
            q = q->next;
        }
        while(q){
            p = p->next;
            q = q->next;
        }
        ListNode* temp = p->next;
        p->next = temp->next;
        delete temp;

        head = dummy->next;
        delete dummy;
        return head;
    }
};
/*
O(n) time complexity and O(1) space complexity.
Two pointer technique to find the nth node from the end.
*/
int main() {
    Solution sol;
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2; // Remove the 2nd node from the end
    ListNode* result = sol.removeNthFromEnd(head, n);
    
    // Print the result
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}