#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                if (t == "+") st.push(y + x);
                else if (t == "-") st.push(y - x);
                else if (t == "*") st.push(y * x);
                else st.push(y / x);
            } else {
                st.push(std::stoi(t));
            }
        }
        return st.top();
    }
};
/*
O(n) time and O(n) space complexity.
We use a stack to evaluate RPN, or postfix expressions.
*/
int main(){
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = sol.evalRPN(tokens);
    cout << "Result of Reverse Polish Notation: " << result << endl;
    return 0;
}