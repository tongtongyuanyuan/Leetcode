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
    vector<int> findTwoNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int max_res = INT_MIN;
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> res(2, -1);
    int i = 0, j = n2 - 1;
    while (i < n1 && n2 >= 0) {
        if (nums1[i] + nums2[j] <= k) {
            if (nums1[i] + nums2[j] == k) {
                return {i, j};
            }
            if (nums1[i] + nums2[j] > max_res) {
                max_res = nums1[i] + nums2[j];
                res[0] = i;
                res[1] = j;
            }
            ++i;
        } else{
            j--; //注意要是--j就 code11
        }
    }
          return res;
}
int main() {
    vector<int> A = {1,4,6,8};
    vector<int> B = {1,2,3,4};
    int k = 9;
    vector<int> res = findTwoNumber(A, B, k);
    for(auto r : res) {
        cout << r << " ";
    }
}
