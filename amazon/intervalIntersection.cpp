//
// Created by Tong Xue on 8/5/19.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        //vector<int> out;
        vector<vector<int>> res;
        int m = A.size(), n = B.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if(lo <= hi) {
                //vector<int> out(lo,hi);
                res.push_back({lo,hi});
                //out.clear();
            }
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};
int main() {
    vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> res;
    Solution S;
    res = S.intervalIntersection(A, B);
    for(auto r : res) {
        for(auto a : r) {
            cout << a << " ";
        }
        cout << endl;
    }
}