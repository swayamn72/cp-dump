#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Candidate writes this function only.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q) return nullptr;
    int log = 20;
    int timer = 0;
    map<TreeNode*, int> tin;
    map<TreeNode*, int> tout;
    map<TreeNode*, vector<TreeNode*>> up;
}

TreeNode* buildSampleTree() {
    // [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);
    n3->left = n5; n3->right = n1;
    n5->left = n6; n5->right = n2;
    n1->left = n0; n1->right = n8;
    n2->left = n7; n2->right = n4;
    return n3;
}

TreeNode* findNode(TreeNode* root, int target) {
    if (!root) return nullptr;
    if (root->val == target) return root;
    TreeNode* left = findNode(root->left, target);
    if (left) return left;
    return findNode(root->right, target);
}

int main() {
    {
        TreeNode* root = buildSampleTree();
        TreeNode* p = findNode(root, 5);
        TreeNode* q = findNode(root, 1);
        TreeNode* got = lowestCommonAncestor(root, p, q);
        int expected = 3;
        cout << "Test 1: got=" << (got ? got->val : -1)
             << ", expected=" << expected
             << ", status=" << ((got && got->val == expected) ? "PASS" : "FAIL") << endl;
    }
    {
        TreeNode* root = buildSampleTree();
        TreeNode* p = findNode(root, 5);
        TreeNode* q = findNode(root, 4);
        TreeNode* got = lowestCommonAncestor(root, p, q);
        int expected = 5;
        cout << "Test 2: got=" << (got ? got->val : -1)
             << ", expected=" << expected
             << ", status=" << ((got && got->val == expected) ? "PASS" : "FAIL") << endl;
    }
}