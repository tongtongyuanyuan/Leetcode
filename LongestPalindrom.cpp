//
// Created by Tong Xue on 7/23/19.
//
#include <iostream>


using namespace std;

class Solution{
public:
    string LongestPanlidrome(string s) {
        int n = s.size(), len = 0, start = 0;
        if(n < 2) return s;
        for(int i = 0; i < n;) {
            int left = i, right = i;
            if(n - i < len/2) break;
            while(right < n - 1 && s[right] == s[right + 1]) right++;
            i = right + 1;
            while(left > 0 && right < n - 1 && s[left - 1] == s[right + 1])
                left--;right++;
            if(len < right - left + 1) {
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};

int main() {
    string s = "babad";
    Solution S;
    cout << S.LongestPanlidrome(s) << "";
}