#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(A.size() > B.size()) std::swap(A, B);

        int total = A.size() + B.size();
        int half = total / 2;

        int l = 0;
        int r = A.size();

        while(l <= r){
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = (i == 0) ? INT_MIN : A[i - 1];
            int Aright = (i == A.size()) ? INT_MAX : A[i];
            int Bleft = (j == 0) ? INT_MIN : B[j - 1];
            int Bright = (j == B.size()) ? INT_MAX : B[j];

            if(Aleft <= Bright && Bleft <= Aright){
                if(total % 2 != 0) return std::min(Aright, Bright);
                else return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;  
            }
            else if(Aleft > Bright) r = i -1;
            else l = i + 1;
        }
        return 0.0;
    }
};
/*
O(log(min(m, n))) time complexity and O(1) space complexity.
Binary search used to solve this hard problem. Had to look it up on yt.
*/
int main() {
    Solution sol;
    vector<int> A = {1, 3};
    vector<int> B = {2};
    double result = sol.findMedianSortedArrays(A, B);
    cout << "The median is: " << result << endl;
    return 0;
}