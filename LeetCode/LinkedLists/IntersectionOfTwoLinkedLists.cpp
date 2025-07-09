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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::stack<ListNode*> stackA;
        std::stack<ListNode*> stackB;
        ListNode* p = headA;
        while(p){
            stackA.push(p);
            p = p->next;
        }
        p = headB;
        while(p){
            stackB.push(p);
            p = p->next;
        }
        ListNode* intersec = NULL;
        while(!stackA.empty() && !stackB.empty() && stackA.top() == stackB.top()){
            intersec = stackA.top();
            stackA.pop();
            stackB.pop();
        }
        return intersec;
    }
};
/*
O(n) time and space complexity.
This one was a bit tricky. Learned how to use stacks in  C++.
*/
int main()
{
    Solution sol;
    // Example usage:
    ListNode* common = new ListNode(8, new ListNode(4, new ListNode(5)));
    ListNode* headA = new ListNode(4, new ListNode(1, common));
    ListNode* headB = new ListNode(5, new ListNode(0, new ListNode(1, common)));
    
    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl; // Should print 8
    } else {
        cout << "No intersection." << endl;
    }
    
    return 0;
}