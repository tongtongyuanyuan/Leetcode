//
// Created by Tong Xue on 2019-09-01.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g;
        for(auto e : edges){
            unordered_set<int> s{{e[0]}};
            queue<int> q{{e[0]}};
            while(!q.empty()) {
                int t = q.front(); q.pop();
                if(g[t].count(e[1])) return e;
                for(auto a : g[t]){
                    if(s.count(a)) continue;//已经访问过,继续
                    s.insert(a);
                    q.push(a);
                }
            }
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        return {};
    }
};
int main(){
    vector<vector<int>> edges{{1,2},{1,3},{2,3}};
    vector<int> res;
    Solution S;
    res = S.findRedundantConnection(edges);
    cout << "[" ;
    for(auto& r : res){
        cout << r ;
    }
        cout << "]";
    }

