//
// Created by Tong Xue on 7/4/19.
//

#include<iostream>
#include <vector>

using namespace std;

struct BusinessInfo {
    string id;
    int value;
    BusinessInfo(){}
    BusinessInfo(string&& id, int value) :id(id),value(value) {}

};


vector<BusinessInfo> mergeBusinessInfo(vector<BusinessInfo>& list1, vector<BusinessInfo>& list2) {
    if(list1.empty()) return list2;
    if(list2.empty()) return list1;
    int size1 = list1.size();
    int size2 = list2.size();
    vector<BusinessInfo> res(size1 + size2);
    int i1 = 0;
    int i2 = 0;
    int r = 0;

    while(i1 < size1 && i2 < size2){
        if(list1[i1].value > list2[i2].value){
            res[r++] = list1[i1++];
        }
        else{
            res[r++] = list2[i2++];
        }
    }

    while(i1 < size1){
        res[r++] = list1[i1++];
    }
    while(i2 < size2){
        res[r++] = list2[i2++];
    }


    return res;
}

int main() {
    vector<BusinessInfo> list1;
    list1.emplace_back(BusinessInfo("0000", 900));
    list1.emplace_back(BusinessInfo("0001", 850));
    list1.emplace_back(BusinessInfo("0001", 800));
    vector<BusinessInfo> list2;
    list2.emplace_back(BusinessInfo("0000", 830));
    list2.emplace_back(BusinessInfo("0001", 820));
    list2.emplace_back(BusinessInfo("0001", 790));

    vector<BusinessInfo> res = mergeBusinessInfo(list1, list2);
    for(auto& r : res)
        cout << '{'  << "\'id\':" << '\'' << r.id << '\''<< ',' <<  "\'value\':" << r.value << '}' << endl;

}