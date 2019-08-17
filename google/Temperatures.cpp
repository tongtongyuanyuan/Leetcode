//
// Created by Tong Xue on 2019-08-17.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n,0);
        stack<int> s;
        for(int i = 0; i <  nums.size(); ++i){
            while(!s.empty() && nums[i] > nums[s.top()]) {
                auto t = s.top(); s.pop();
                res[t] = i - t;
            }
            s.push(i);//遇到递减的元素进stack比较
        }
        return res;
    }
};

int main(){
    vector<int> nums = {73,74,75,71,69,72,76,73};
    Solution S;
    vector<int> res;
    res = S.dailyTemperatures(nums);
    for(int a : res){
        cout << a << " ";
    }

}