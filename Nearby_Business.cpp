//
// Created by Tong Xue on 7/4/19.
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    string name;
    unordered_map<string, int> nearby_business;
    Node(string&& name) : name(name){}
};
