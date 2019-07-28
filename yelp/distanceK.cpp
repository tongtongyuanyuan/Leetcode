//
// Created by Tong Xue on 7/11/19.
//


#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct TreeNode{
    TreeNode* right;
    TreeNode* left;
    int val;

    TreeNode(int x) : val(x), right(nullptr),left(nullptr) {}
};

class Solution{
public:
    unordered_map<TreeNode*,TreeNode*> parents;
    void findparent(TreeNode* root, TreeNode* parent) {
        parents[root] = parent;
        if(root->left) findparent(root->left, parent);
        if(root->right) findparent(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
          findparent(root, nullptr);
          vector<int> res;
          deque<TreeNode*> q;
          unordered_set<TreeNode*> exist;
          q.push_back(target);
          exist.insert(target);
          int level = 0;
          if(level == K) res.push_back(target->val);
          while(!q.empty()) {
              int loops = q.size();
              level++;
              while(loops--) {
                  TreeNode *cur = q.front();
                  q.pop_front();
                  if (!exist.count(cur->left)) {
                      q.push_back(cur->left);
                      exist.insert(cur->left);
                  }
                  if (exist.find(cur->right) == exist.end()) {
                      q.push_back(cur->right);
                      exist.insert(cur->right);
                  }
                  if (exist.find(parents[cur]) == exist.end()) {
                      q.push_back(parents[cur]);
                      exist.insert(parents[cur]);
                  }
              }
                  if(level == K) {
                      for(auto &a : q) {
                          res.push_back(a->val);
                      }
                      return res;
                  }
              }
        return res;
    }
};
int main() {
    TreeNode* root = {3,5,1,6,2,0,8,nullptr,nullptr,7,4};
    int K = 2;
    TreeNode* target = 5;

}