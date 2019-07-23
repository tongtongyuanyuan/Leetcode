//
// Created by Tong Xue on 7/22/19.
//
#include <iostream>

using namespace std;

class Solution{
public:
    string countAndSay(int n) {
        if(n <=0) return "";
        string res = "1";
        while(--n) {
            string cur = "";
            //int cnt = 1;
            for(int i = 0; i < res.size(); ++i) {
                int cnt = 1;//res很大的时候，比如111221，此时i = 3,一直在for里面，cnt要从新统计了
                while(i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
int main() {
    int n = 6;
    Solution S;
    cout << S.countAndSay(n) << "";
}