//
// Created by Tong Xue on 2019-08-11.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            int i, j, n = num.size();
            for (i = n - 2; i >= 0; --i) {
                if (num[i + 1] > num[i]) {
                    for (j = n - 1; j > i; --j) {
                        if (num[j] > num[i]) break;
                    }
                    swap(num[i], num[j]);
                    reverse(num.begin() + i + 1, num.end());
                    return;
                }
            }
            reverse(num.begin(), num.end());
        }
    void print(vector<int>& num){
            int n = num.size();
            for(int i = 0; i < n; ++i){
                cout << num[i] << " ";
                //cout << "\n';
;            }
        }
    };
int main(){
    //vector<int> num = {1,2,7,4,3,1};
    vector<int> num = {1,1,2,3,4,7};
    Solution S;
    S.nextPermutation(num);
    S.print(num);
}

