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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
/*
O(1) time and space complexity.
Once I knew the key idea, it was simple.
*/
int main()
{
    Solution sol;
    // Example usage:
    ListNode* head = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
    ListNode* nodeToDelete = head->next; // Node with value 5

    sol.deleteNode(nodeToDelete);

    // Print the modified list
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    
    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}