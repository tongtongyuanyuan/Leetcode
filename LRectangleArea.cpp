//
// Created by Tong Xue on 7/19/19.
//


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i);
            } else {
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }
        }
        return res;
    }
};
int main() {
    vector<int> height = {2,1,5,6,2,3};
    Solution S;
    cout << S.largestRectangleArea(height) << "";
}