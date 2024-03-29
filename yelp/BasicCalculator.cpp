//
// Created by Tong Xue on 7/13/19.
//

#include <iostream>
#include <stack>


using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0') {
                num = 10 * num + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;    //res更新为0
                sign = 1;  //每次更新为1
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += sign * num; //如果碰到 ），则num = 0;
        return res;
    }
}; //2-(5-6)
int main() {
    //string s = "2-(5-6)";
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution S;
    cout << S.calculate(s) << "";
}
// class Solution{
// public:
//      int calculate(string s) {
//      int num = 0, sign = 1, res = 0;
//      stack<int>st;
//     for(int i = 0; i < s.size(); i++) {
//         char c = s[i];
//         if(c >= '0') {
//            num = 10 * num + c - '0';
//         }
//         else if(c == '+' || c== '-') {
//             res += sign * num;
//             num = 0; //每次初始化为0，以免改变结果，更新下一次结果
//             sign = (c == '+') ? 1 : -1;
//         } else if(c == '(') {
//             st.push(num);
//             num = 0;
//         }else if(c == ')') {
//             res += sign * num;
//             st.push(res);
//             num = 0;
//         }
//     }
//     res += sign * num;
//     return res;
//  }
// }; //runtime error