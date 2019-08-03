//
// Created by Tong Xue on 8/2/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
        vector<string> removeComments(vector<string>& source) {
            vector<string> res;
            string out = "";
            bool inBlock = false; //记录当前是否为块注释状态
            for(string line : source) {
                for(int i = 0; i < line.size(); ++i) {
                    if(!inBlock){  //not in a block "}"
                        if(i == line.size() - 1) out += line[i];
                        else {
                            string t = line.substr(i, 2);
                            if(t == "/*") inBlock = true, ++i;
                            else if(t == "//") break;
                            else out += line[i];
                        }
                    }
                    else{    //in a block
                        if(i < line.size() - 1){  //end a block
                            string t = line.substr(i, 2);
                            if(t == "*/") inBlock = false,++i; //change our state not in a block
                        }
                    }
                }
                if(!out.empty() && !inBlock) {
                    res.push_back(out);
                    out = ""; //遍历完每个line得到一个out,清空以后继续
                }
            }
            return res;
        }
};

int main() {
     vector<string> source = {
             "/*Test program */", "int main()", "{ ",
             "// variable declaration ", "int a, b, c;", "/* This is a test",
             "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"
     };
//    vector<string> source = {"a/*comment", "line", "more_comment*/b"};
    vector<string> res;
    Solution S;
    res = S.removeComments(source);
    for(string& r : res) {
        cout << r << " ";
    }
}