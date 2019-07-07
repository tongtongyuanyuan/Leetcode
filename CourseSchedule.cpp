//
// Created by Tong Xue on 7/7/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> in(numCourses);
        for(auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }
//        for(auto it : graph) {
//            for(auto g : it) {
//                cout << g << " ";
//            }
//        }
        queue<int> q;
        for(int i = 0; i < numCourses;i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int t = q.front(); q.pop();
            for(auto a : graph[t]) {
                --in[a];
                if(in[a] == 0) q.push(a);
            }
        }
        for(int i = 0; i < numCourses;++i) {
            if(in[i] != 0) return false;
        }
        return true;
    }
};
int main() {
    vector<vector<int>> prerequisites = {{3,2},{2,1},{1,0}};
    Solution s;
    cout << s.canFinish(4,prerequisites) << " ";
}