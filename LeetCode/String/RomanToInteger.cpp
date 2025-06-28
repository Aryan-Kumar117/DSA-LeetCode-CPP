#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            if(i+1 < s.length()){
            if(s[i] == 'I' && s[i+1] == 'V'){total += 4;i++; continue;}
            if(s[i] == 'I' && s[i+1] == 'X'){total += 9;i++; continue;}
            if(s[i] == 'X' && s[i+1] == 'L'){total += 40;i++; continue;}
            if(s[i] == 'X' && s[i+1] == 'C'){total += 90;i++; continue;}
            if(s[i] == 'C' && s[i+1] == 'D'){total += 400;i++; continue;} 
            if(s[i] == 'C' && s[i+1] == 'M'){total += 900;i++; continue;}
            }
            if(s[i] == 'I'){total += 1;}
            if(s[i] == 'V'){total += 5;}
            if(s[i] == 'X'){total += 10;}
            if(s[i] == 'L'){total += 50;}
            if(s[i] == 'C'){total += 100;}
            if(s[i] == 'D'){total += 500;}
            if(s[i] == 'M'){total += 1000;}
        }
        return total;
    }
};
//Solved this myself. People on Leetcode used an unordered_map to store values, it might be cleaner, but this also works superb.

int main() {
    Solution sol;
    string roman = "MCMXCIV"; // Example input
    int result = sol.romanToInt(roman);
    cout << "The integer value of the Roman numeral " << roman << " is: " << result << endl;
    return 0;
}