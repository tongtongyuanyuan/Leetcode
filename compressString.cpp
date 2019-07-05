//
// Created by Tong Xue on 7/4/19.
//
//Compress String   aaaaaadddvv  会变成6a3d2v Leetcode 394(类似)
#include <iostream>
#include <string>
using namespace std;

string compressString(string s) {
    if(s.empty()) return nullptr;
    int n = s.size();
    string res = "";
    int i = 0, j = 0;
    while(i < n) {
        if(s[i] == s[j]){
            i++;
        }else {
            res += s[j];
            string num = to_string(i - j);
            res += num;
            j = i;
        }
    }
    res += s[j];
    string num = to_string(i - j);
    res += num;
    return res;
}


int main(){
    string s = "aaaaaadddvv";
    cout << compressString(s) << endl;
}