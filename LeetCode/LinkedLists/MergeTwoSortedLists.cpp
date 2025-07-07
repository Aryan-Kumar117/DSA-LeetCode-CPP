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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* third = NULL;
        ListNode* last = NULL;
        ListNode* merged = NULL;
        if(!list1){return list2;}
        if(!list2){return list1;}
            if(list1->val < list2->val){
                merged = list1;
                third = list1;
                last = list1;
                list1 = list1->next;
                last->next = NULL;
            }
            else{
                merged = list2;
                third = list2;
                last = list2;
                list2 = list2->next;
                last->next = NULL;
            }
            while(list1 && list2){
                if(list1->val < list2->val){
                    last->next = list1;
                    last = list1;
                    list1 = list1->next;
                    last->next = NULL;
                }
                else{
                    last->next = list2;
                    last = list2;
                    list2 = list2->next;
                    last->next = NULL;
                }
            }
            if (list1) last->next = list1;
            else if (list2) last->next = list2;
            return merged;
        }
};
/*
O(n) time complexity, where n is the total number of nodes in both lists.
O(1) space complexity, as we are not using any additional data structures that grow with input size.
The solution uses two pointers to traverse and merge the lists together. 
This piece of code is a bit lengthy, but efficient.
*/

int main() {
    // Example usage:
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print merged list
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}