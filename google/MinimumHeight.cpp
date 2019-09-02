//
// Created by Tong Xue on 2019-09-01.
//
#include <queue>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

 class Solution {
 public:
     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         if(n == 1) return {0};
         vector<int> res;
         vector<unordered_set<int>> adj(n);
         for(auto e : edges){
             adj[e[0]].insert(e[1]);
             adj[e[1]].insert(e[0]);
         }
         queue<int> q;
         for(int i = 0; i < n;++i){
             if(adj[i].size() == 1)
                 q.push(i);
         }

         while(n > 2){
             int size = q.size();
             n -= size;  //remove leaf node layer by layer;
             for(int i = 0; i < size;++i){
                 int t = q.front(); q.pop();
                 for(auto a : adj[t]){
                     adj[a].erase(t); //remove leave node
                     if(adj[a].size() == 1) q.push(a);
                 }
             }
         }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
               return res;
     }
 };
int main(){
    int n = 4;
    vector<vector<int>> edges = {{1,0}, {1, 2}, {1, 3}};
    vector<int> res;
    Solution S;
    res = S.findMinHeightTrees(n, edges);
    cout << "[";
    for(auto& r : res){
        cout << r ;
    }
    cout << "]";
}