//
// Created by Tong Xue on 7/23/19.
//

#include <iostream>
#include <queue>

using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; //存index
        for(int i = 0; i < nums.size();i++) {
            if(!dq.empty() && dq.front() == i - k) dq.pop_front(); //移出窗口
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i + 1 >= k) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6};
    int k = 3;
    Solution S;
    vector<int> res;
    res = S.maxSlidingWindow(nums, k);
    for(auto r : res) {
        cout << r << " " <<  "";
    }
}