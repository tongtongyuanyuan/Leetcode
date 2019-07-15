//
// Created by Tong Xue on 7/15/19.
//
#include <iostream>
#include <vector>

using namespace std;

char findK(string& str, int k){
    int sum = 0;
    int left = 0;
    int right = 0;
    int len = str.length();

    while(left < len && right < len){
        while(right < len && isalpha(str[right])) right++;
        string cur = str.substr(left, right - left);
        left = right;
        while(right < len && isdigit(str[right])) right++;
        int count = stoi(str.substr(left, right - left));
        if(cur.length() * count + sum - 1 >= k){
            int index = (k - sum) % cur.length();
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