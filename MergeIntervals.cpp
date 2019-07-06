//
// Created by Tong Xue on 7/6/19.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        int n = intervals.size();
        // int n = intervals[0].size();
        vector<vector<int>> res;
        vector<int> out;
        vector<int> starts, ends;
        for(int i = 0; i < n;i++) {
            starts.push_back(intervals[i][0]);
        }
        for(int i = 0; i < n;i++){
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        for(int i = 0, j = 0; i < n; i++) {
            if(i == n - 1 || starts[i + 1] > ends[i]) {
                out.push_back(starts[j]);
                out.push_back(ends[i]);
                res.push_back(out);
                j = i + 1;
            }
            out.clear();
        }
        return res;
    }
};

int main() {
    vector<vector<int>> m{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res;
    Solution s;
    res = s.merge(m);
    cout << '[';
    for(int i = 0; i < res.size();i++) {
        cout << '[';
        int j = 0;
        while(j < res[i].size() - 1) {
            cout << res[i][j] << ',';
            j++;
        }
        cout << res[i][j] << ']';
    }
    cout << ']';
}

