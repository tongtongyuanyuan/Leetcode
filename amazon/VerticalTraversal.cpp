//
// Created by Tong Xue on 8/6/19.
//

#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
        TreeNode*  left;
        TreeNode* right;
        int val;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {};
};

class Solution{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            TreeNode* node = t.first;
            int x = t.second.first;
            int y = t.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) {
                q.push({node->left,{x - 1,y + 1}});
            }
            if(node->right) {
                q.push({node->right,{x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto a : nodes) {  //nodes存的是按层，并且排序按坐标x再按y
            vector<int> out;
            for(auto b : a.second) {  //a.second对应node->val
                out.insert(out.end(), b.second.begin(), b.second.end());
            }
            ans.push_back(out);
        }
        return ans;
    }
};
int main() {
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution S;
    vector<vector<int>> res;
    res = S.verticalTraversal(n1);
    for(auto r : res) {
        for(auto a : r) {
            cout << a << " ";
        }
        cout << endl;
    }

}
