// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// we traverse to the left subtree and right subtree of a node in tree and search for both nodes for which we want to find the ancestor.
// when we find the node then we return the node to the parent.
// so now it is possible that root node gets two values from both left sub tree and right subtree, it means root is the ancestor.
//if we get value only from one side of the tree it means one of the two nodes will be the ancestor of other.
// base condition is when we go to left or right node and node not exists then we return the NULL.
// another condition we can check if one of the element is root then it means the root will definitly be the ancestor.

#include<iostream>
using namespace std;

// here p and q are the nodes for which we want to find the ancestor
// root is the root of the tree

TreeNode* LCS(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root == nullptr) {
        return nullptr;
    }

    if(root == p || root == q) { // one of the node is root
        return root;
    }

    TreeNode *left_ans = LCS(root -> left, p, q);
    TreeNode *right_ans = LCS(root -> right, p, q);

    if(left_ans != nullptr && right_ans != nullptr) { // one node present on left and other on right side of the tree.
        return root;
    }

    if(left_ans != nullptr) {
        return left_ans;
    }

    if(right_ans != nullptr) {
        return right_ans;
    }
}

int main() {

}