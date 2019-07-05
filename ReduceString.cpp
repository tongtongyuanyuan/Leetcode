//
// Created by Tong Xue on 7/4/19.
//

//Reduce String aaddc --- adc
//adadc -- adc

//aaddeeccee >> adece


//a  a  d  d  e  e  c  c  e  e
//ij i  ij i  ij    ij    j    ij
//l  l  l     l

#include<iostream>

using namespace std;

string removeDuplicate(string s) {
    if(s.empty()) return "";
    int n = s.length();
    int len = 0;
    int i = 0;
    int j = 0;
    while(i <= n && j < n){
        if(i == n ||  s[j] != s[i]){
            s[len++] = s[j];
            j = i;
        }
        else{
            i++;
        }
    }
    return s.substr(0, len);

}

int main() {
    string s = "adddccaab";
    cout << removeDuplicate(s) << endl;
}


