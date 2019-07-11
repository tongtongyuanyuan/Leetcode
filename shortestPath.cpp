//
// Created by Tong Xue on 7/11/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row;
    int col;
    Point(int row, int col) : row(row),col(col) {}
    bool operator == (Point p) {
        return row == p.row && col == p.col;
    }
};


int shortestPath(vector<vector<int>> &matrix, Point start, Point end){
    int step = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> directs{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    matrix[start.row][start.col] = -1; //访问过
    queue<Point> q;
    q.push(start);
    while(!q.empty()) {
        int size = q.size();
        step++;
        while (size--) {
            Point cur = q.front();
            q.pop();
            for (auto d : directs) {
                int cur_row = cur.row + d[0];
                int cur_col = cur.col + d[1];
                if (cur_row >= 0 && cur_row < m && cur_col >= 0 && cur_col < n) {
                    //if(matrix[next_x][next_y] == end) return step;
                    Point cur_new(cur_row, cur_col);
                    if (cur_new == end) return step;
                    if (matrix[cur_row][cur_col] == 1) {
                        matrix[cur_row][cur_col] = -1;
                        q.push(cur_new);
                    }
                }
            }
        }
    }
             return -1;
}

int main() {
    vector<vector<int>> matrix =
            {
                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
                    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}
            };
    Point start(0,0);
    Point end(3,4);
    cout << shortestPath(matrix, start, end);
}