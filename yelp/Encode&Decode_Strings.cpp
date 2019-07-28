//
// Created by Tong Xue on 7/9/19.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Codec{
public:
    //Encode a list of strings to a single string
    string encode(vector<string>& strs) {
        string res = "";
        for(auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
          return res;
    }
    //Decode a single string to a list of strings
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()) {
            auto f = s.find("/",i);
            //cout << s.substr(i, f - i) << ""; 1,2,3只把i到f-i直接的数字输出
            int len = stoi(s.substr(i, f - i));
            res.push_back(s.substr(f + 1, len));
            i = f + len + 1; //每次i 在"/"之前一位
        }
        return res;
    }
};
int main() {
    vector<string> s = {"a","ab","abc"};
    Codec C;
    cout << C.encode(s) << "";
    cout << endl;
    string res = "";
    res = C.encode(s);
    vector<string> ans;
    for(auto a : C.decode(res)) {
        cout << a << " ";
    }
}