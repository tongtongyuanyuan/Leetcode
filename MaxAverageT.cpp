//
// Created by Tong Xue on 7/13/19.
//


#include <iostream>
#include <vector>

using namespace std;
//
//struct Node{
//    int val;
//    vector<Node*> children;
//    Node() = default;
//    explicit Node(int val) : val(val){}
//
//};
//
//
//pair<int, int> dfs(Node* root, Node*& res, double& cur_max){
//    if(root == nullptr) return make_pair(0, 0);
//    if(root->children.empty()) return make_pair(root->val, 1);
//    int sum = root->val;
//    int count = 1;
//    for(auto n : root->children){
//        pair<int, int> next_child = dfs(n, res, cur_max);
//        sum += next_child.first;
//        count += next_child.second;
//    }
//
//    double cur = 1.0 * sum / count;
//    if(cur > cur_max){
//        res = root;
//        cur_max = cur;
//    }
//    return make_pair(sum, count);
//}
//
//
//
//Node* largestAvgSubtree(Node* root){
//    Node* res = nullptr;
//    double cur_max= INT_MIN;
//    dfs(root, res, cur_max);
//    return res;
//
//}
//
//
//int main(){
//    Node* n1 = new Node(7);
//    Node* n2 = new Node(6);
//    Node* n3 = new Node(2);
//    Node* n4 = new Node(4);
//    Node* n5 = new Node(1);
//    Node* n6 = new Node(5);
//    Node* n7 = new Node(9);
//    Node* n8 = new Node(8);
//    Node* n9 = new Node(3);
//    Node* n10 = new Node(8);
//    n1->children.push_back(n2);
//    n1->children.push_back(n3);
//    n1->children.push_back(n4);
//
//    n2->children.push_back(n5);
//    n2->children.push_back(n6);
//
//    n3->children.push_back(n7);
//    n3->children.push_back(n8);
//    n3->children.push_back(n9);
//
//    n4->children.push_back(n10);
//
//    cout << largestAvgSubtree(n1)->val << endl;
//
//}
#include <iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    explicit TreeNode (int val) : val(val), right(nullptr), left(nullptr) {};
};

struct Info{
    int sum;
    int size;
    TreeNode* node;
    explicit Info(int sum = 0, int size = 0, TreeNode* node = nullptr) : sum(sum), size(size), node(node) {}
};
Info dfs(TreeNode* root, TreeNode* res, double cur_max) {
    if (root == nullptr) return Info(0, 0, nullptr);
    if (root->left == nullptr && root->right == nullptr) return Info(1, 1, root);
    int sum1 = 0;
    int count = 0;
    if (root->left) {
        Info left = dfs(root->left, res, cur_max) {
            sum1 += left.sum;
            count += left.size;
        }
        if (root->right) {
            Info right = dfs(root->right, res, cur_max);
            sum1 += right.sum;
            count += right.size;
        }
        double cur = 1.0 * sum1 / count;
        if (cur > cur_max) {
            cur_max = cur;
            res = root;
        }
        return Info(sum1, count, root);
    }
    TreeNode *MaxAverageT(TreeNode *root) {
        TreeNode *res = nullptr;
        double cur_max = INT_MIN;
        dfs(root, res, cur_max);
        return res;
    }
}
int main() {

}
