//
// Created by Tong Xue on 7/18/19.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> topKfrequent(vector<string>& words, int k) {
        vector<string> res(k);
        unordered_map<string,int> m;

        auto cmp = [] (pair<string, int>& a, pair<string,int> &b) {
            return a.second > b.second || (a.second == b.second && a.first< b.first);
        };

        priority_queue<pair<string,int>, vector<pair<string,int>>,decltype(cmp) > q(cmp);
//        for(int i = 0; i < words.size();i++) {
//            m[words[i]]++;
//        }

        for(auto str : words) {
            m[str]++;
        }

        for(auto f : m) {
            q.push(f);
            if(q.size() > k)
                q.pop();
        }

        for(int i = res.size() - 1; i >= 0;--i) {
            res[i] = q.top().first;q.pop();
        }
        return res;
    }
};
int main() {
    //vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    vector<string> res;
    Solution S;
    res = S.topKfrequent(words, k);
    for (auto r : res) {
        cout << r << " " << "";
    }
}
//output: the is sunny day