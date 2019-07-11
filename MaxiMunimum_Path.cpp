//
// Created by Tong Xue on 7/10/19.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
//    int MaxMinmumPath(vector<vector<int>> &matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        vector<int> dp(n);
//        dp[0] = matrix[0][0];
//        for (int j = 1; j < n; j++) {
//            dp[j] = min(dp[j - 1], matrix[0][j]);
//        }
//        for (int i = 1; i < m; i++) {
//            dp[0] = min(dp[0], matrix[i][0]); // dp[i]  = min(dp[i -1], matrix[i][0]); 判断每一行的第0个
//            for (int j = 1; j < n; j++) {
//                dp[j] = (dp[j] < matrix[i][j] && dp[j - 1] < matrix[i][j]) ? max(dp[j], dp[j - 1]) : matrix[i][j];
//            }
//        }
//        return dp[n - 1];
//    }
    int MaxMinmumPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,matrix[0][0]));
        for(int i = 1; i < m;i++) {
            for(int j = 1; j < n;j++) {
                dp[i][j] = (dp[i][j-1] < matrix[i][j] && dp[i-1][j] < matrix[i][j]) ? max(dp[i][j-1],dp[i][j-1]) : matrix[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> matrix = {
            {5,1,3,6},
            {5,4,3,6},
            {5,4,5,6},
//            {8,4,7},
//            {6,5,9},
    };
    Solution s;
    cout << s.MaxMinmumPath(matrix) << "";
}

