//
// Created by Tong Xue on 7/4/19.
//

//given bussinessInfo 的类，里面有id 和catagory         
//class bussinessInfo{int id, String catagory} .
// input : 101 japanese, sushi, restaurant
//         102 japanese, seafood  
//         103 japanese, restaurant, ramen  
//找出所有的id 即是 japanese 又是resturant.
//output:101,103

//Japanese >> 101 102 103
//restaurant >> 101 103


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct BusinessInfo{
    int id;
    vector<string> catagory;
    BusinessInfo(int id, vector<string>&& catagory) : id(id), catagory(catagory) {}
};
class Solution {
public:

    vector<int> findId(vector<BusinessInfo>& input, string a, string b) {
        unordered_map<string, vector<int>> m;
        vector<int> res;
        unordered_set<int> longer;
        for (auto &i : input) {
            for (auto &str : i.catagory) {
                if (str == a) m[a].push_back(i.id);
                if (str == b) m[b].push_back(i.id);
            }
        }

        for(auto& id : m[a]){
            longer.insert(id);
        }
        for(auto& id: m[b]){
            if(longer.count(id)){
                res.push_back(id);
            }
        }
        return res;
    }
};


int main() {
    string a = "japanese";
    string b = "restaurant";
    vector<BusinessInfo> input;
    input.push_back(BusinessInfo(101,{"japanese","sushi","restaurant"}));
    input.push_back(BusinessInfo(102, {"japanese","seafood"}));
    input.push_back(BusinessInfo(103, {"japanese","restaurant","ramen"}));

    Solution s;
    vector<int> res = s.findId(input, a, b);
    for(int& r: res)
        cout << r << ' ';

}


