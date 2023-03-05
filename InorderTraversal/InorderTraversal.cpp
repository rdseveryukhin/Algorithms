#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//Given the root of a binary tree, return the inorder traversal of its nodes' values.
class InorderTraversal {
public:
    vector<int> MorrisTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> vec;
        while (curr) {
            if (!curr->left) {
                vec.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    vec.push_back(curr->val);
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return vec;
    }

    vector<int> RecursionTraversal(TreeNode* root) {
        vector<int> nums;
        if (root != nullptr) {
            recursion(root, nums);
        }
        return nums;
    }

    void recursion(TreeNode* root, vector<int>& nums) {
        if (root != nullptr) {
            recursion(root->left, nums);
            nums.push_back(root->val);
            recursion(root->right, nums);
        }
    }
};

int main() {
    auto four = new TreeNode(4);
    auto five = new TreeNode(5);
    auto six = new TreeNode(6);
    auto seven = new TreeNode(7);
    auto two = new TreeNode(2, four, five);
    auto three = new TreeNode(3, six, seven);
    auto one = new TreeNode(1, two, three);

    InorderTraversal ob;

    for (auto x : ob.MorrisTraversal(one)) {
        cout << x << ' ';
    }
}
