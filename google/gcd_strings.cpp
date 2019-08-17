//
// Created by Tong Xue on 2019-08-16.
//
#include <iostream>

using namespace std;


class Solution{
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int s1 = 0;
        int s2 = 0;
        while (true) {
            int i = s1;
            int j = s2;
            for (; i < n1; i++) {
                if (j == n2) {
                    s1 = i;
                    j = s2;
                }
                if (str1[i] != str2[j++]) return "";
            }
            if (i == n1 && j == n2) return str1.substr(s1);

            i = s1;
            j = s2; //s2 = 0
            for (; j < n2; j++) {
                if (i == n1) {
                    s2 = j;
                    i = s1;
                }
                if (str1[i++] != str2[j]) return "";
            }
            if (i == n1 && j == n2) return str2.substr(s2); //都到结尾了
        }
        return "";
    }
};
int main(){
    string str1 = "ABABAB";
    string str2 = "AB";
    Solution S;
    cout << S.gcdOfStrings(str1, str2) << "";
}