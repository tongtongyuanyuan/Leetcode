//
// Created by Tong Xue on 7/18/19.
//
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
//class Solution {
//public:
//    vector<int> topKElements(vector<int> nums,int k) {
//      unordered_map<int,int> m;
//      priority_queue<pair<int,int>> q;
//      vector<int> res;
//        for(int i = 0; i < nums.size(); i++) {
//            ++m[nums[i]];
//        }
//        for(auto a : m) {
//            q.push({a.second, a.first}); //按第一个排序,second对应的value次数，再按key数字排序
//        }
//        for(int i = 0; i < k;i++) {
//            res.push_back({q.top().second}); //q.second对应的是数字
//            q.pop();
//        }
//        return res;
//    }
//};
struct cmp{
    bool operator() (pair<int,int> &n1, pair<int,int> &n2) {
        return n1.second > n2.second;
    }
};

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(auto n : nums) {
            counts[n]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> freq;
        for(auto c : counts) {
            freq.push(c);
            if(freq.size() > k)
                freq.pop();  //一直维持k个,priority_queue先按first，key数字排序，再按个数
        }
        vector<int> res;
        while(!freq.empty()) {
            res.push_back(freq.top().first); //数字 c: counts,key对应queue的first，就是数字
            freq.pop();
        }
        return res;
    }
};

int main() {
    //vector<int> nums = {1,1,1,2,3,3};
    vector<int> nums = {2,2,1,3,3,3};
    Solution S;
    vector<int> res;
    //res = S.topKElements(nums,2);
    res = S.topKFrequent(nums,2);
    cout << '[';
    for(int r : res) {
        cout << r << "";
    }
    cout << ']';
}