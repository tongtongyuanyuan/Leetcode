//
// Created by Tong Xue on 7/20/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S) {
        vector<vector<int> > res(1);
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); ++i) {
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};
int main() {
    vector<int> nums = {1,2,3};
    Solution S;
    vector<vector<int>> res;
    res = S.subsets(nums);
    for(auto r : res) {
        cout << endl;
        for(auto it : r) {
            cout << it << " ";
        }
    }
}