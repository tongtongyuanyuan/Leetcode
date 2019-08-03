//
// Created by Tong Xue on 8/3/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int i = 0; i <= rowIndex; ++i) {
            for(int j = i; j >= 1;--j) {
                res[j] += res[j-1];
            }
        }
        return res;
    }
};
int main()
{
    int rowIndex = 3;
    vector<int> res;
    Solution S;
    res = S.getRow(rowIndex);
    for(auto& r : res) {
        cout << r << " ";
    }
}

