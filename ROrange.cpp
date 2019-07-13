//
// Created by Tong Xue on 7/13/19.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
//
//class Solution {
//public:
//    int orangesRotting(vector<vector<int>>& grid) {
//        if(grid.empty() || grid[0].empty()) return -1;
//        int m = grid.size(), n = grid[0].size();
//        //vector<vector<bool>> visited(m, vector<bool>(n,false));
//        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
//        queue<pair<int,int>> q;
//        //q.push({start[0],start[1]}); 与200一样并没有指定从哪里开始
//        //if(grid[start[0]][start[1]] == 0)
//        int time = -1;
//        for(int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 2)  //没有访问过并且为rotten
//                    q.push({i, j});
//            }
//        }
//                //int time = 0;
//                while (!q.empty()) {
//                    time++;
//                    int loops = q.size();
//                    while (loops--) {
//                        auto t = q.front();
//                        q.pop();
//                        for (auto d : dirs) {
//                            int x = t.first + d[0];
//                            int y = t.second + d[1];
//                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
//                                grid[x][y] = 2;
//                                //++time;
//                                q.push({x, y});
//
//                            }
//                        }
//                    }
//                }
//
//
//        for(int i = 0; i < m; i++) {
//            for(int j = 0; j < n; j++) {
//                if(grid[i][j] == 1)
//                    return -1; // check if any fresh orange is left
//            }
//        }
//        return time;
//    }
//};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        queue<pair<int, int>> bfs;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1)
                    count++;
                else if(grid[i][j] == 2){
                    bfs.push({i, j});
                }
            }
        if(!count) return 0;
        int step = -1;
        vector<vector<int>> directs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!bfs.empty()){
            int loops = bfs.size();
            step++;
            while(loops--){
                auto cur = bfs.front(); bfs.pop();
                int cur_i = cur.first;
                int cur_j = cur.second;
                for(auto& d : directs){
                    int next_i = cur_i + d[0];
                    int next_j = cur_j + d[1];
                    if(next_i >= 0 && next_j >= 0 && next_i < row && next_j < col && grid[next_i][next_j] == 1){
                        count--;
                        grid[next_i][next_j] = 2;
                        bfs.push({next_i, next_j});
                    }
                }
            }
        }
        return count == 0 ? step : -1;
    }
};

int main() {
    vector<vector<int>> grid{
            {2,1,1},
            {1,1,0},
            {0,1,1},
    };
    Solution S;
    cout << S.orangesRotting(grid) << "";
}
//other's code
//class Solution {
//public:
//    bool isValid(int x, int y, int m, int n)
//    {
//        return x >= 0 && y >= 0 && x < m && y < n;
//    }
//
//    int orangesRotting(vector<vector<int>> & matrix)
//    {
//        int time = 0; // time to rot all the oranges!
//        int m = int(matrix.size());
//        int n = int(matrix[0].size());
//        queue<pair<int, pair<int, int>>> q; // pair.first -> time, pair.second.first -> x coord, pair.second.second -> y coord
//
//        for(int i = 0; i < m; i++)
//            for(int j = 0; j < n; j++)
//                if(matrix[i][j] == 2)
//                    q.push({0, {i, j}});  // put all the rotten oranges in the queue with time as 0
//
//        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // all the dir
//        while(!q.empty())
//        {
//            pair<int, pair<int, int>> curr = q.front(); q.pop();
//            time = max(time, curr.first); // update the time if required
//            for(auto & it : dir)
//            {
//                int x = it.first + curr.second.first; // current option to explore
//                int y = it.second + curr.second.second; // current option to explore
//                if(isValid(x, y, m, n) && matrix[x][y] == 1) // if the orange is fresh
//                {
//                    matrix[x][y] = 2; // make it rotten
//                    q.push({curr.first + 1, {x, y}}); // increase the time
//                }
//            }
//        }
//
//        for(int i = 0; i < m; i++)
//            for(int j = 0; j < n; j++)
//                if(matrix[i][j] == 1)
//                    return -1; // check if any fresh orange is left
//
//        return time;
//    }
//};
//int main() {
//    vector<vector<int>> grid{
//            {2,1,1},
//            {1,1,0},
//            {0,1,1},
//    };
//    Solution S;
//    cout << S.orangesRotting(grid) << "";
//}