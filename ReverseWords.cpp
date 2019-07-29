//
// Created by Tong Xue on 7/28/19.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string res;
        s = " " + s;
        int n = s.size();
        for(int i = n - 1,j = n;i > 0;--i) {
            if(s[i] != ' ' && s[i-1] == ' ') res += s.substr(i, j - i) + " ";
            if(s[i] == ' ') j = i;
        }
        //cout << res;//blue is sky
        return res.substr(0, res.size() - 1);  //see the note,
    }
};
int main() {
    string s = "a good   example";   //reduce multiple spaces between two words to a single space in the reversed string.
    Solution S;
    cout << S.reverseWords(s) << "";
}

