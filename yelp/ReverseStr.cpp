//
// Created by Tong Xue on 7/15/19.
//
#include <iostream>

using namespace std;

class Solution {
    public:
        string reverseStr(string s, int k) {
            int n = s.size();
    for(int start = 0; start < n; start += 2 * k) {
        int l = start, r = min(start + k - 1, n - 1);
        while(l < r) {
            swap(s[l++],s[r--]);
        }
    }
    return s;
}
};


int main() {
//    string s = "abcbefmnqplsme";
    string s = "abcdefg";
    Solution S;
    cout << S.reverseStr(s,1213);
}

