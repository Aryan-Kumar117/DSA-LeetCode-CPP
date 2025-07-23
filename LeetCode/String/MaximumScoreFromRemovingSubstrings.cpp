#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        std::string first = "ab";
        std::string second = "ba";

        int firstVal = x;
        int secondVal = y;
        int maxCount = 0;

        if(x < y){
            std::swap(first, second);
            std::swap(firstVal, secondVal);
        }

        std::stack<char> stack1;
        for(char x: s){
            if(!stack1.empty() && stack1.top() == first[0] && x == first[1]){
                stack1.pop();
                maxCount += firstVal;
            }
            else{
                stack1.push(x);
            }
        }

        std::string remaining = "";
        while(!stack1.empty()){
            remaining += stack1.top();
            stack1.pop();
        }
        std::reverse(remaining.begin(), remaining.end());

        std::stack<char> stack2;
        for(char x: remaining){
            if(!stack2.empty() && stack2.top() == second[0] && x == second[1]){
                stack2.pop();
                maxCount += secondVal;
            }
            else{
                stack2.push(x);
            }
        }
        return maxCount; 
    }
};
/*
O(n) time complexity and O(n) space complexity.
Greedy approach utilizing stacks to remove substrings "ab" and "ba" in the optimal order.
Quite a lengthy code, got 63ms of runtime. 
*/
int main() {
    Solution sol;
    string s = "cbaab";
    int x = 4; // Value for "ab"
    int y = 5; // Value for "ba"
    int result = sol.maximumGain(s, x, y);
    cout << "The maximum score from removing substrings is: " << result << endl;
    return 0;
}