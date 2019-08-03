//
// Created by Tong Xue on 7/11/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool findmazebfs(vector<vector<int>> maze){
    if(maze.empty() || maze[0].empty()) return false;
    vector<int> start = {0,0};
    if(maze[start[0]][start[1]] == 9) return true;
    if(maze[start[0]][start[1]] == 0) return false;
    int rows = maze.size();
    int cols = maze.at(0).size();
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};

    queue<pair<int, int>> bfs;
    bfs.push({start[0],start[1]});
    maze[0][0] = -1;
    while(!bfs.empty()){
        pair<int, int> cur = bfs.front();
        bfs.pop();
        for(auto d : dirs){
            int x = cur.first + d[0];
            int y = cur.second + d[1];
            if(x >=0 && x < rows && y >= 0 && y < cols){
                if(maze[x][y] == 9){
                    return true;
                }
                else if(maze[x][y] == 1){
                    bfs.push({x,y});
                    maze[x][y] = -1;
                }
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> maze
            {
                    {1,1,1,1},
                    {1,0,1,1},
                    {1,1,0,0},
                    {1,9,0,1}
            };
    cout << findmazebfs(maze) << endl;
}