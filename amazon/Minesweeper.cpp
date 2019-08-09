//
// Created by Tong Xue on 7/16/19.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q({{click[0], click[1]}});
        // vector<vector<int>> dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,1}};
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second, cnt = 0; q.pop();
            vector<pair<int, int>> neighbors;
            if (board[row][col] == 'M') board[row][col] = 'X';
            else {
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) { //8个方向
                        int x = row + i, y = col + j;
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        if (board[x][y] == 'M') ++cnt;
                        else if (cnt == 0 && board[x][y] == 'E') neighbors.push_back({x, y});
                    }
                }
            }
            if (cnt > 0) board[row][col] = cnt + '0';
            else {
                for (auto a : neighbors) {
                    board[a.first][a.second] = 'B';
                    q.push(a);
                }
            }
        }
        return board;
    }
};
int main() {
    vector<vector<char>> board{{'E', 'E', 'E', 'E', 'E'},
                               {'E', 'E', 'M', 'E', 'E'},
                               {'E', 'E', 'E', 'E', 'E'},
                               {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {{3,0}};
    vector<vector<char>> res;
    Solution S;
    res = S.updateBoard(board, click);
    for(auto r : res){
       for(auto a : r){
           cout << a << " ";
       }
       cout << endl;
   }
};

