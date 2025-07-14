#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>

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
    int getDecimalValue(ListNode* head) {
        std::stack<bool> stack;
        ListNode* p = head;
        int res = 0;
        int power = 0;
        while(p){
            stack.push(p->val);
            p = p->next;
        }
        while(!stack.empty()){
            int add = 0;
            if(stack.top() == 1) add = static_cast<int>(pow(2, power));
            res += add;
            stack.pop();
            ++power;
        }
        return res;
    }
};

/*
O(n) time and O(n) space complexity. 
Used stacks to solve the problem. 
*/

int main() {
    Solution sol;
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(0, new ListNode(1))); // Represents binary 101
    int result = sol.getDecimalValue(head);
    
    cout << "Decimal value: " << result << endl; // Should print "5"
    
    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}