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
    int maximum69Number (int num) {
        std::string str = std::to_string(num);
        for(char &x: str){
            if(x == '6'){
                x = '9';
                break;
            }
        }
        return std::stoi(str);
    }
};
/*
O(n) time complexity and O(n) space complexity.
Simple enough, and dare I say, nice problem ¯\_( ͡° ͜ʖ ͡°)_/¯
*/
int main() {
    // Example usage:
    Solution sol;
    int num = 9669;
    int result = sol.maximum69Number(num);
    cout << "Maximum 69 Number: " << result << endl; // Output: 9969
    return 0;
}