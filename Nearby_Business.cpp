//
// Created by Tong Xue on 7/4/19.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

//struct Node{
//    string name;
//    unordered_map<string, int> nearby_business;
//    Node(string&& name) : name(name){}
class Business {
public:
    Business(string name) {
        this ->name = name;
    }
      string name;
    map<Business*, int> nearbyBusiness;   //business string name -> distance
};
void dfs(Business* business, vector<string>& res, int cur,int dist, set<Business*>& exist) {
    if(exist.count(business)) return;
    if(cur - dist < 0) return;
    exist.insert(business); //符合条件插入
    res.push_back(business->name);  //返回的是名字
    cur -= dist;
    for(auto& n : business->nearbyBusiness) {
        dfs(n.first, res, cur, n.second, exist);
    }
}

vector<string> findReachableBusiness(Business* startBusiness, int distance) {
    vector<string> res;
    set<Business*> exist{startBusiness}; //标记不能重复访问一个地点
    for(auto &n : startBusiness->nearbyBusiness) {
        dfs(n.first, res, distance, n.second,exist);
        return res;
    }
}
int main() {
    Business* A;
    Business* B;
    Business* C;
    Business* D;
    map<Business*,int> nearbyBusiness;
    nearbyBusiness[B] = 2;
    nearbyBusiness[C] = 4;
    nearbyBusiness[D] = 5;
    vector<string> res;
    res = findReachableBusiness(A,2);
    for(string str : res) {
        cout << str << "";
    }
}