//
// Created by Tong Xue on 7/27/19.
//

//1797.lintcode
//1.the sum of the two numbers <= k 2.The sum is the biggest. 3.The first array index is the smallest
//eg. A = [1,4,6,8] B = [1,2,3,4] k = 9;
//return [2,2]

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//    vector<int> maxIndex(vector<int>& A, vector<int>& B, int k) {
//        sort(A.begin(), A.end());
//        sort(B.begin(), B.end());
//        int sum = 0;
//        int idx = INT_MAX;
//        vector<int> res;
//        //unordered_map<int, int> m;
//        for(int i = 0; i < A.size(); i++) {
//           for(int j = 0; j < B.size(); j++) {
//               sum = A[i] + B[j];
//               idx = i + j;
//               sum = max(sum, k);
//               if(sum <= k ) { //不对，最大的最接近的
//                   if(idx > i + j) {
//                       idx = i + j;
//                       res.push_back(i);
//                       res.push_back(j);
//                   }
//               }
//           }
//        }
//        return res;
//    }
int main() {
    vector<int> A = {1,4,6,8};
    vector<int> B = {1,2,3,4};
    int k = 9;
    vector<int> res = maxIndex(A, B, k);
    for(auto r : res) {
        cout << r << " ";
    }
}
