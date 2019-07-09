//
// Created by Tong Xue on 7/7/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//class Solution {
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        vector<vector<int>> graph(numCourses,vector<int>());
//        vector<int> in(numCourses);
//        for(auto a : prerequisites) {
//            graph[a[1]].push_back(a[0]);
//            ++in[a[0]];
//       }
//        queue<int> q;
//        for(int i = 0; i < numCourses;i++) {
//            if(in[i] == 0) q.push(i);
//        }
//        while(!q.empty()) {
//            int t = q.front(); q.pop();
//            for(auto a : graph[t]) {
//                --in[a];
//                if(in[a] == 0) q.push(a);
//            }
//        }
//        for(int i = 0; i < numCourses;++i) {
//            if(in[i] != 0) return false;
//        }
//        return true;
//    }
//};
//DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prequisite) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visit(numCourses); //记录课程有没有访问过
        for (auto a : prequisite) {
            graph[a[1]].push_back(a[0]);  //从第一门课开始找可以构成哪门课
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false; //对课程进行递归调用，直到出现的新课都访问过
        }
        return true;
    }

    bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) return false; //有冲突
        if (visit[i] == 1) return true; //表示已经访问过
        visit[i] = -1; //访问过设为-1，下次如果再遇到则有环，返回false
        for (auto a : graph[i]) {
        if (!canFinishDFS(graph, visit, a)) return false;
    }
        visit[i] = i; //把标记为已访问的改为未访问
        return true;
  }
};
int main() {
      vector<vector<int>> prerequisites = {{0,1},{1,0}};
//    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}};
    Solution s;
    cout << s.canFinish(2,prerequisites) << " ";
}