//
// Created by Tong Xue on 7/11/19.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestMaze(vector<vector<int>>& maze) {
    if(maze.empty() || maze[0].empty()) return 0;
    int rows = maze.size(), cols = maze[0].size();
    vector<int> start{0,0};
    if(maze[start[0]][start[1]] == 9) return 0;
    if(maze[start[0]][start[1]] == 0) return 0;
    vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int, int>> q;
    q.push({start[0],start[1]});
    maze[0][0] = -1;
    int step = 0;
    while(!q.empty()) {
        int loops = q.size();
        step++;
        for(int i = q.size(); i > 0; i--) {
            pair<int,int> cur = q.front();
            q.pop();
            for(auto d : dirs) {
                int x = cur.first + d[0];
                int y = cur.second + d[1];
                if(x >= 0 && x < rows && y >= 0 && y < cols) {
                    if(maze[x][y] == 9) return step;
                    else if(maze[x][y] == 1) {
                        q.push({x,y});
                        maze[x][y] = -1;
                    }
                }
            }
        }
    }
    return 0;
}


int main(){
    vector<vector<int>> maze
            {
                    {1,0,9,1},
                    {1,0,1,1},
                    {1,1,1,1},
                    {1,1,1,1}
            };
    vector<int> start = {0,0};
    cout << shortestMaze(maze) << endl;
}
