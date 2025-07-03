#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        std::string word = "a";
        while(word.size() < k){
            std::string next = "";
            for(char c: word){
                next += (c == 'z') ? 'a' : c+1;
            }
            word += next;
        }
        return word[k-1];
    }
};

int main() {
    Solution sol;
    int k = 5; // Example input
    char result = sol.kthCharacter(k);
    cout << "The " << k << "th character in the string game is: " << result << endl;
    return 0;
}