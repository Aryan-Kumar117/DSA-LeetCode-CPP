#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        string s = to_string(x);
        for(int i = 0; i < s.length(); i++){
            if(s[i] != s[s.length()-i-1]){return false;}
        }
        return true;
    }
};

/*My method certainly works, however reversing the integer is also very viable. For my notes:
int rev = 0;
int num = x;
while (num != 0) {
    rev = rev * 10 + num % 10; // Add last digit
    num = num / 10;            // Remove last digit
}
then we just check! 
*/

int main() {
    Solution sol;
    int number = 121; // Example input
    bool result = sol.isPalindrome(number);
    cout << "Is the number " << number << " a palindrome? " << (result ? "Yes" : "No") << endl;
    return 0;
}