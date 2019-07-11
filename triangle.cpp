//
// Created by Tong Xue on 7/11/19.
//

#include <iostream>
#include <vector>

using namespace std;
 class Solution{
 public:
//      int minimumTotal(vector<vector<int>>& triangle){
//          int m = triangle.size(), n = triangle[m-1].size();
//          if(triangle.empty() || triangle[m-1].empty()) return 0;
//          vector<vector<int>> dp(m, vector<int>(n,0));
//          dp[0][0] = triangle[0][0];
//          for(int i = 1; i < triangle.size();i++) {
//              for(int j = 1; j < triangle[i].size();j++) {
//                  if(j == 0) dp[i][0] = dp[i-1][0] + triangle[i][0];  //第一列
//                  else if(j == triangle[i].size() - 1)    //最后一列
//                      dp[i][j] = dp[i-1][j-1] + triangle[i][j];
//                  else dp[i][j] = triangle[i][j] + min(triangle[i-1][j],triangle[i-1][j-1]);
//              }
//          }
//             return *min_element(dp.back().begin(), dp.back().end());
//      }  程序不对

         int minimumTotal(vector<vector<int>>& triangle) {
             vector<int> dp(triangle.back());
             for (int i = (int)triangle.size() - 2; i >= 0; --i) {
                 for (int j = 0; j <= i; ++j) {
                     dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
                 }
             }
             return dp[0];
         }
     };
int main() {
    vector<vector<int>> triangle {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3},
    };
    Solution S;
    cout << S.minimumTotal(triangle) << " ";
}