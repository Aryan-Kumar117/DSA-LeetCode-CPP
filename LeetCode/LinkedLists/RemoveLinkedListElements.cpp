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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode* p = head;
        while(p && p->next){
            if(p->next->val == val){
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else{
            p = p->next;
            }
        }
        return head;
    }
};
/*

O(n) time complexity and O(1) space complexity.
A bit tricky, ListNodes always feel that way, but I got it working.

*/
int main() {
    Solution sol;
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int val = 6;
    ListNode* result = sol.removeElements(head, val);
    
    // Print the result
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}