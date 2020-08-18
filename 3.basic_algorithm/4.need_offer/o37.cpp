#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
using namespace std;

#define null 9999

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *makeTree(vector<int> input) {
    if (input.size() == 0)
        return nullptr;
    if (input[0] == null)
        return nullptr;
    int ind = 1;
    TreeNode *root = new TreeNode(input[0]);
    queue<TreeNode *> q;
    q.push(root);
    while (ind != input.size()) {
        TreeNode *tmp = q.front();
        q.pop();
        if (input[ind] != null) {
            tmp->left = new TreeNode(input[ind]);
            q.push(tmp->left);
        }
        if (++ind == input.size())
            break;
        if (input[ind] != null) {
            tmp->right = new TreeNode(input[ind]);
            q.push(tmp->right);
        }
        if (++ind == input.size())
            break;
    }
    return root;
}

void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if (node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "),
                        false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + char(node->val - 1 + '1') +
                "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp) {
                out<<tmp->val<<" ";
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                out<<"null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val) {
            if (val == "null") {
                vec.push_back(NULL);
            } else {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1;                                          // i每往后移动一位，j移动两位，j始终是当前i的左子下标
        for (int i = 0; j < vec.size(); ++i) {              // 肯定是j先到达边界，所以这里判断j < vec.size()
            if (vec[i] == NULL) continue;                   // vec[i]为null时跳过。
            if (j < vec.size()) vec[i]->left = vec[j++];    // 当前j位置为i的左子树
            if (j < vec.size()) vec[i]->right = vec[j++];   // 当前j位置为i的右子树
        }
        return vec[0];
    }

};

// 作者：yuexiwen
// 链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/solution/c-dui-lie-guan-fang-xu-lie-hua-fang-shi-mian-shi-t/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main() {

    Codec codec;
    vector<int> input = {1,2,3,null,null,4,5,6,7};
    TreeNode* root = makeTree(input);
    prettyPrintTree(root);
    cout<<codec.serialize(root)<<endl;
    prettyPrintTree(codec.deserialize(codec.serialize(root)));
    return 0;
}