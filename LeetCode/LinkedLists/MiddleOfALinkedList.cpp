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
    ListNode* middleNode(ListNode* head) {
        ListNode* OneNodeTraveller = head;
        ListNode* TwoNodeTraveller = head;
        while(TwoNodeTraveller && OneNodeTraveller){
            TwoNodeTraveller = TwoNodeTraveller->next;
            if(TwoNodeTraveller){OneNodeTraveller = OneNodeTraveller->next;}
            if(TwoNodeTraveller){TwoNodeTraveller = TwoNodeTraveller->next;}
        }
        return OneNodeTraveller;
    }
};

/*
O(n) time complexity and O(1) space complexity. Easy problem.
*/

int main()
{
    Solution sol;
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* middle = sol.middleNode(head);
    
    // Print the middle node value
    cout << "Middle node value: " << middle->val << endl; // Should print 3 for this example
    
    return 0;
}