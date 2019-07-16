//
// Created by Tong Xue on 7/16/19.
//
//allow duplicate eg. aba, k = 2, output = ab,ba,aba

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findKDistinctString(string& s, int k){
    if(s.empty()) return 0;
    int len = s.length();
    int res = 0;
    for(int i = 0; i < len; i++){
        int count = k;
        unordered_set<char> exist;
        for(int j = i; j < len; j++){
            if(exist.find(s[j]) == exist.end()){
                exist.insert(s[j]);
                count--;
            }
            if(count == 0) res++;
            if(count < 0) break;
        }
    }
    return res;
}


int main(){
    string input = "aba";
    int k = 2;
    cout << findKDistinctString(input, k);
}