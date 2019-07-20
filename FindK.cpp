//
// Created by Tong Xue on 7/15/19.
//
#include <iostream>
#include <vector>

using namespace std;

char findK(string& str, int k){
    int sum = 0; //sum是一个很巧妙的运用
    int left = 0;
    int right = 0;
    int len = str.length();

    while(left < len && right < len){
        while(right < len && isalpha(str[right])) right++;
        string cur = str.substr(left, right - left); //right此时指向数字
        left = right;
        while(right < len && isdigit(str[right])) right++;
        int count = stoi(str.substr(left, right - left));
        if(cur.length() * count + sum - 1 >= k){  //k + 1当前长度
            int index = (k + 1 - sum) % cur.length() - 1; // k - sum
            return cur[index];
        }
        else{
            sum += cur.length() * count;
        }
        left = right;
    }
    return '0';
}
int main() {
     string str = "frog5spring6xyz3";
     int k = 34;
     cout <<findK(str,k) << "";
}
//880. leet2code3-> leetleet->leetleetcode->leetleetcodeleetleetcodeleetleetcode
//      haha22->hahahaha
