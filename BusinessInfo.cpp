//
// Created by Tong Xue on 7/4/19.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct BussinessInfo{
    int id;
    int rating;

    BusinessInfo(int id, int rating) : id(id), rating(rating) {}
};


class Solution {
public:
    map<int, int> sortBusinessByRating (vector<BusinessInfo>& input) {
        map<int,priority_queue<int,vector<int> ,greater<int>>> m;
        for(auto& r : input) {
            m[r.id].push(r.rating);
        }
    }

};

int main() {
    BusinessInfo b1["id" : 101, ratring : 5];
    BusinessInfo b1["id" : 102, ratring : 2];
    BusinessInfo b1["id" : 103, ratring : 3];
    BusinessInfo b1["id" : 104, ratring : 5];
    BusinessInfo b1["id" : 105, ratring : 5];
    cout << sortBusinessByRating
}