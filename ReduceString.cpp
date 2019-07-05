//
// Created by Tong Xue on 7/4/19.
//

//Reduce String aaddc --- adc
#include<iostream>
#include<vector>

using namespace std;

string removeDuplicate(string s) {
    sort(s.begin(), s.end());
    string str = " ";
    int i = 0, j = 0;
    int n = s.size();
    while (i <= n && j < n) {
        if (s[i] == s[j]) {
            i++;
        } else {
            str.push_back(s[j]);
            j = i;
        }
        return str;
    }
}

int main() {
    string s = "adddccaab";
    cout << removeDuplicate(s) << endl;
}


