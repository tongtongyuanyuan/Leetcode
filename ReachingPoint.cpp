//
// Created by Tong Xue on 7/25/19.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy)
                return true;
        if (tx == sx) {
            return (ty - sy) % tx == 0;
        }
        if (ty == sy) {
            return (tx - sx) % ty == 0;
        }
        if (tx > ty) {
            tx -= ty;
        } else {
            ty -= tx;
        }
    }
         return false;
    }
};

int main() {
    int sx = 1, sy = 4, tx = 5, ty = 9;
    Solution s;
    cout << s.reachingPoints(sx, sy, tx, ty) << " ";
}