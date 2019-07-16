//
// Created by Tong Xue on 7/15/19.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


int findString(string &s,int k) {
    unordered_map<char, int> exist;
    unordered_set<string> res;
    int left = 0, right = 0;
    int len = s.length();
    while(right < len) {
        char cur = s[right];
        if(exist[cur] == 0) {   //没有出现过
            exist[cur]++; //该字符出现的个数+1
            k--;
        }else {                //移动完右指针之前出现过
            while(s[left] != cur) {
                exist[left]--;
                left++;
                k++;
            }
            left++;  //left 与right 相等的移走left，移动right,因为不能字母重复
        }
        if(k == 0) {
            res.insert(s.substr(left, right - left + 1));
            exist[s[left]]--;   //k = 0 时，先移动左指针，不满足了，并且移走次数——1
            left++;
            k++;
        }
        right++;    //每次先右指针移动，然后满足条件k == 0以后再移动左指针
    }
    return res.size();
}
int main() {
//    string s = "abcdabcabc";
//    string s = "abcbdabc";
    string s = "aba";
    int k = 2;
    cout << findString(s,k) << "";
}
//没有说at least,刚好k个distinct，并且abc 与bca是一个