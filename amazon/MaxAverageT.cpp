//
// Created by Tong Xue on 7/13/19.
//


#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    vector<Node*> children;
    Node() = default;
    explicit Node(int val) : val(val){}
};


pair<int, int> dfs(Node* root, Node*& res, double& cur_max){
    if(root == nullptr) return make_pair(0, 0);
    if(root->children.empty()) return make_pair(root->val, 1);
    int sum = root->val;
    int count = 1;
    for(auto n : root->children){
        pair<int, int> next_child = dfs(n, res, cur_max);
        sum += next_child.first;
        count += next_child.second;
    }

    double cur = 1.0 * sum / count;
    if(cur > cur_max){
        res = root;
        cur_max = cur;
    }
    return make_pair(sum, count);
}


Node* largestAvgSubtree(Node* root){
    Node* res = nullptr;
    double cur_max= INT_MIN;
    dfs(root, res, cur_max);
    return res;

}


int main(){
    Node* n1 = new Node(7);
    Node* n2 = new Node(6);
    Node* n3 = new Node(2);
    Node* n4 = new Node(4);
    Node* n5 = new Node(1);
    Node* n6 = new Node(5);
    Node* n7 = new Node(9);
    Node* n8 = new Node(8);
    Node* n9 = new Node(3);
    Node* n10 = new Node(8);
    n1->children.push_back(n2);
    n1->children.push_back(n3);
    n1->children.push_back(n4);

    n2->children.push_back(n5);
    n2->children.push_back(n6);

    n3->children.push_back(n7);
    cout << largestAvgSubtree(n1)->val << endl;

}


//class TreeNode{
//public:
//    int val;
//    TreeNode* right;
//    TreeNode* left;
//    explicit TreeNode (int val) : val(val), right(nullptr), left(nullptr) {};
//};
//
//struct Info{
//    int sum;
//    int size;
//    TreeNode* node;
//    explicit Info(int sum = 0, int size = 0, TreeNode* node = nullptr) : sum(sum), size(size), node(node) {}
//};
//Info dfs(TreeNode* root, TreeNode* res, double cur_max) {
//    if (root == nullptr) return Info(0, 0, nullptr);
//    if (root->left == nullptr && root->right == nullptr) return Info(1, 1, root);
//    int sum1 = 0;
//    int count = 0;
//    if (root->left) {
//        Info left = dfs(root->left, res, cur_max) {
//            sum1 += left.sum;
//            count += left.size;
//        }
//        if (root->right) {
//            Info right = dfs(root->right, res, cur_max);
//            sum1 += right.sum;
//            count += right.size;
//        }
//        double cur = 1.0 * sum1 / count;
//        if (cur > cur_max) {
//            cur_max = cur;
//            res = root;
//        }
//        return Info(sum1, count, root);
//    }
//    TreeNode *MaxAverageT(TreeNode *root) {
//        TreeNode *res = nullptr;
//        double cur_max = INT_MIN;
//        dfs(root, res, cur_max);
//        return res;
//    }
//}
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

struct Info {
    TreeNode *res;
    double max_avg;
    int sum;
    int count;

    Info(int sum, int count, TreeNode *res, double max_avg) : sum(sum), count(count), res(res), max_avg(max_avg) {}
};

Info dfs(TreeNode *node) {
    //This is the corner case for leaf node
    if (node == nullptr) return Info{0, 0, nullptr, 0};

    //Use dfs to get information from left child and right child
    Info left = dfs(node->left);
    Info right = dfs(node->right);

    //Update current information with children information
    int cur_sum = left.sum + right.sum + node->val;
    int cur_count = left.count + right.count + 1;
    double cur_avg = 1.0 * cur_sum / cur_count;
    Info cur{cur_sum, cur_count, node, cur_avg};


    if (cur.max_avg < left.max_avg) {
        cur.res = left.res;
        cur.max_avg = left.max_avg;
    }
    if (cur.max_avg < right.max_avg) {
        cur.res = right.res;
        cur.max_avg = right.max_avg;
    }

    return cur;
}


TreeNode *maximumAverageSum(TreeNode *root) {
    return dfs(root).res;
}


void print(int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << i << ' ' << j << endl;
        }
    }
}


int main() {
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(-5);
    TreeNode *n3 = new TreeNode(11);
    TreeNode *n4 = new TreeNode(1);
    TreeNode *n5 = new TreeNode(2);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(-2);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    cout << maximumAverageSum(n1)->val << endl;
}
