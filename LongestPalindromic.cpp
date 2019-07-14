//
// Created by Tong Xue on 7/13/19.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int left = 0, right = 0, len = 0;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};
int main() {
    string s = "babad";
    Solution S;
    cout << S.longestPalindrome(s) << "";
}