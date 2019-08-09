//
// Created by Tong Xue on 2019-08-08.
//
#include <iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<char>> solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size();
        //vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> dirs{{0,1}, {0,-1},{-1,0},{1, 0}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                //if(board[i][j] == 'X' || visited) continue;
                if(i != 0 && i != m - 1 && j != 0 && j != n - 1) continue; //找到边界线上的坐标， 不是边界线继续
                if(board[i][j] != '0') continue;
                board[i][j] = '#';//找到边界上是0的标为#，通过BFS的方法，然后找到与其相连的所有0，标记为#，最后改为0
                queue<pair<int,int>> q;
                q.push({i,j});//在边界上找，只要上下左右
                while(!q.empty()){
                    auto t = q.front(); q.pop();
                    for(auto d : dirs){
                        int row = i + d[0];
                        int col = j + d[1];
                        if(row >= 0 && row < m && col >= 0 && col < n && board[row][col] == '0') {
                            board[row][col] = '#';
                            q.push({row, col});
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                if(board[i][j] == '0') board[i][j] = 'X';//注意⚠️这两句的执行顺序
                if(board[i][j] == '#') board[i][j] = '0';//再把边界的#改为0
                //if(board[i][j] == '0') board[i][j] = 'X';//剩下的0都是中间的
            }
        }
        return board;
    }
};
int main(){
    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','0','0','X'},
                                  {'X','X','0','X'},
                                  {'X','0','X','X'}};
    vector<vector<char>> res;
    Solution S;
    res = S.solve(board);
    for(auto r : res){
        for(auto t : r){
            cout  << t << " ";
        }
        cout << endl;
    }
};
