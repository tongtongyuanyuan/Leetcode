//
// Created by Tong Xue on 7/4/19.
//

//input:
//[
// [ 'red', 'black','green' ]
// ['white', 'red', 'black',]
// ['red','yellow','yellow']
// ]
//return ['red','black']

//if the frequence is same, then return all of them
//[
// ['red', 'green','green']
// [ 'black', 'blue', 'black']
// [ 'red', 'yellow', 'yellow']
// ]
// ouput:
//['black','green','red','yellow']

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> TopColor(vector<vector<string>>& input) {
    unordered_map<string, int> color;
    vector<string> res;
    int max_count = 0;
    for(int i = 0; i < input.size();i++) {
        for (int j = 0; j < input[i].size(); ++j) {
            max_count = max(max_count, ++color[input[i][j]]);
        }
    }
    for(auto& a : color) {
        if(a.second == max_count)
            res.push_back(a.first);
    }
    return res;
}

int main() {
    vector<vector<string>> input{
            {"red", "black","green"},
            {"white","red", "yellow"},
            {"red","yellow","yellow","yellow"},
    };
    vector<string> res = TopColor(input);
    for(auto& r : res)
        cout << r << ' ';
}