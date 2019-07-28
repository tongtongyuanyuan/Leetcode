//
// Created by Tong Xue on 7/4/19.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//class BusinessInfo{
//public:
//
//    int id;
//    int rating;
//    BusinessInfo(int id, int rating) : id(id), rating(rating) {}
//
//    friend bool operator < (const BusinessInfo& b1, const BusinessInfo& b2){
//        return b1.rating > b2.rating;
//    }
//};

struct BusinessInfo{
    int id;
    int rating;
    BusinessInfo(int id, int rating) : id(id), rating(rating){}
};


class Solution {
public:
    vector<BusinessInfo> sortBusinessByRating (vector<BusinessInfo>& input) {
        auto cmp = [](BusinessInfo& b1, BusinessInfo& b2){
            return b1.rating > b2.rating;
        };
        sort(input.begin(), input.end());
        return input;
    }



};

int main() {
//    BusinessInfo b1("id" : 101, ratring : 5];
//    BusinessInfo b1["id" : 102, ratring : 2];
//    BusinessInfo b1["id" : 103, ratring : 3];
//    BusinessInfo b1["id" : 104, ratring : 5];
//    BusinessInfo b1["id" : 105, ratring : 5];
    vector<BusinessInfo> input;
    input.emplace_back(BusinessInfo(101, 5));
    input.emplace_back(BusinessInfo(102, 2));
    input.emplace_back(BusinessInfo(103, 3));
    input.emplace_back(BusinessInfo(104, 5));
    input.emplace_back(BusinessInfo(105, 5));

    Solution s;
    vector<BusinessInfo> output = s.sortBusinessByRating(input);

    for(auto& o : output){
        cout << o.id << ' ' << o.rating << endl;
    }

}











