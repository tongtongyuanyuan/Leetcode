//
// Created by Tong Xue on 7/12/19.
//
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<int> out;
//        vector<vector<int>> res;
//        sort(candidates.begin(),candidates.end());
//        combinationSumDFS(candidates, target, 0, out, res);
//                return res;
//    }
//    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
//        if(target < 0) return;
//        else if(target == 0) res.push_back(out);
//        else{
//            for(int i = 0; i < candidates.size();i++) {  //i = start
//                out.push_back(candidates[i]);
//                combinationSumDFS(candidates, target - candidates[i], i, out, res);
//                out.pop_back();
//            }
//        }
//    }
//};
// wrong : [3,5] [5,3],[3,2,3],[3,3,2] is the same, my code print both of them,why? i = start而不是 i = 0开始，有重复
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(),candidates.end());
        combinationSumDFS(candidates,target,0,out,res);
        return res;
    }
    void combinationSumDFS(vector<int>& candidates,int target,int start,vector<int>& out,vector<vector<int>>& res) {
        if(target < 0) return;
        else if(target == 0) res.push_back(out);
        else{
            for(int i = start;i < candidates.size();i++) {
                out.push_back(candidates[i]);
                combinationSumDFS(candidates,target - candidates[i],i,out,res); //i = i + 1此时
                out.pop_back();
            }
        }
    }
};

int main() {
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> res;
    Solution S;
    res = S.combinationSum(candidates,target);
    cout << "[" << endl;
    for(auto t : res) {
        cout << "[" << "";
        for (auto r : t) {
            cout  << r << " " << "";
        }
        cout << "]" << endl;
    }
    cout << "]" << "";
}

