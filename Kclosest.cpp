//
// Created by Tong Xue on 7/9/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKclosest(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k; //保证从0开始有k个数
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};
int main() {
    vector<int> arr = {-1,0,1,3,4,6,8,10};
    int k = 4, x = 3;
    Solution s;
    for(auto a : s.findKclosest(arr,k,x)) {
        cout << a << "";
    }
}