//
// Created by Tong Xue on 7/24/19.
//

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<string>> findladders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{{beginWord}};
        queue<vector<string>> path{{p}}; //q里面存一个vector
        int level = 1, minlevel = INT_MAX; //
        unordered_set<string> out;
        while(!path.empty()) {
            auto t = path.front(); path.pop();
            if(t.size() > level) {
                for(string w : out) dict.erase(w);
                out.clear(); level = t.size();
                if(level > minlevel) break;
                }
            string word = t.back();
            for(int i = 0; i < word.size();i++) {
                string newWord = word;
                for(char ch = 'a'; ch <= 'z';ch++) {
                    newWord[i] = ch;
                    if(!dict.count(newWord)) continue;
                    out.insert(newWord);
                    vector<string> nextPath = t;
                    nextPath.push_back(newWord);
                    if(newWord == endWord) {
                        res.push_back(nextPath);
                        minlevel = level;
                    }else path.push(nextPath);
                }
            }
        }
        return res;
    }
};
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution S;
    vector<vector<string>> res = S.findladders(beginWord, endWord, wordList);
    for(auto r : res) {
        for(auto a : r) {
            cout << a << " ";
        }
        cout << endl;
    }
}