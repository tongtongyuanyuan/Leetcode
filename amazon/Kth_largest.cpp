//
// Created by Tong Xue on 2019-08-08.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findKthLargets(vector<int>& nums, int k){
        int left = 0, right = nums.size() - 1;
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k - 1) return nums[pos];
            else if(pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution S;
    cout << S.findKthLargets(nums,k) << " ";
}