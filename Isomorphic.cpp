//
// Created by Tong Xue on 7/12/19.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
      bool isIsomorphic(string s, string t) {
          int m1[256] = {0}, m2[256] = {0}, n = s.size();
          for (int i = 0; i < n; i++) {
              if (m1[s[i]] != m2[t[i]]) return false;
              m1[s[i]] = i + 1;
              m2[t[i]] = i + 1;
          }
          return true;
      }
};

int main() {
//    string s = "egg";
//    string t = "add";
     string s = "foo";
     string t = "bar";
    Solution S;
    cout << S.isIsomorphic(s,t) << "";
}
