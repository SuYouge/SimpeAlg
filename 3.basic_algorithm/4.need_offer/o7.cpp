#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define null 9999

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层序遍历构造树
TreeNode *vectorToTreeNode(vector<int> input) {
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

    cout << prefix + (isLeft ? "└── " : "┌── ") + char(node->val - 1 + 'A') +
                "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

// 前序是把右保存起来
vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> v;
    TreeNode *rt = root;
    while (s.size() || rt) {
        while (rt) {
            v.push_back(rt->val);
            s.push(rt->right);
            rt = rt->left;
        }
        rt = s.top();
        s.pop();
    }
    return v;
}

vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> v;
    TreeNode *rt = root;
    while (s.size() || rt) {
        while (rt) {
            v.push_back(rt->val);
            s.push(rt->left);
            rt = rt->right;
        }
        rt = s.top();
        s.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> v;
    TreeNode *rt = root;
    while (s.size() || rt) {
        while (rt) {
            s.push(rt);
            rt = rt->left;
        }
        rt = s.top();
        v.push_back(rt->val);
        s.pop();
        rt = rt->right;
    }
    return v;
}

void printv(vector<int> input) {
    for (auto i : input) {
        // cout << i << " ";
        cout << char(i - 1 + 'A') << " ";
    }
    cout << endl;
}
namespace prein {
TreeNode *helper(vector<int> &pre, vector<int> &inorder, int pre_start,
                 int pre_end, int inorder_start, int inorder_end) {
    if (pre_start > pre_end || inorder_start > inorder_end)
        return nullptr;
    TreeNode *root = new TreeNode(pre[pre_start]);
    if (pre_start == pre_end)
        return root;
    int index = inorder_start;
    // pre[pre_start]为根节点
    while (pre[pre_start] != inorder[index]) {
        // 找到中序序列中的分界点
        index++;
    }
    int fix = index - inorder_start;
    root->left = helper(pre, inorder, pre_start + 1,
                        pre_start + fix, // 前序中的左子树和中序中的左子树
                        inorder_start, index - 1);
    root->right = helper(pre, inorder, pre_start + 1 + fix, pre_end, index + 1,
                         inorder_end); // 前序中的右子树和中序中的右子树
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return helper(preorder, inorder, 0, preorder.size() - 1, 0,
                  inorder.size() - 1);
}
} // namespace prein

namespace prepost {
TreeNode *helper(vector<int> &pre, vector<int> &post, int pre_start,
                 int pre_end, int post_start, int post_end) {
    if (pre_start > pre_end || post_start > post_end)
        return nullptr;
    TreeNode *root = new TreeNode(pre[pre_start]);
    if (pre_start == pre_end)
        return root;
    int index = post_start;
    while (pre[pre_start + 1] != post[index]) {
        index++;
    }
    int fix = index - post_start + 1;
    root->left =
        helper(pre, post, pre_start + 1, pre_start + fix, post_start, index);
    root->right = helper(pre, post, pre_start + 1 + fix, pre_end, index + 1,
                         post_end - 1);
    return root;
}
TreeNode *constructFromPrePost(vector<int> &pre, vector<int> post) {
    return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
}
} // namespace prepost

namespace inpost {
TreeNode *helper(vector<int> &inorder, vector<int> &postorder,
                 int inorder_start, int inorder_end, int postorder_start,
                 int postorder_end) {
    if (inorder_start > inorder_end || postorder_start > postorder_end)
        return nullptr;
    TreeNode *root = new TreeNode(postorder[postorder_end]);
    if (postorder_start == postorder_end)
        return root;
    int index = inorder_start;
    while (postorder[postorder_end] != inorder[index]) {
        index++;
    }
    root->left =
        helper(inorder, postorder, inorder_start, index - 1, postorder_start,
               postorder_start + (index - 1 - inorder_start));
    root->right = helper(inorder, postorder, index + 1, inorder_end,
                         postorder_end - 1 - (inorder_end - (index + 1)),
                         postorder_end - 1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return helper(inorder, postorder, 0, inorder.size() - 1, 0,
                  postorder.size() - 1);
}

} // namespace inpost

int main() {
    vector<int> input = {1, 2, 3, 4, 6, 7, 9, null, null, 5, null, null, 8};
    TreeNode *root = vectorToTreeNode(input);
    prettyPrintTree(root);
    vector<int> pre = preorderTraversal(root);
    printv(pre);
    vector<int> post = postorderTraversal(root);
    printv(post);
    vector<int> in = inorderTraversal(root);
    printv(in);
    TreeNode *res = prein::buildTree(pre, in);
    prettyPrintTree(res);
    TreeNode *pres = prepost::constructFromPrePost(pre, post);
    prettyPrintTree(pres);
    TreeNode *inpost = inpost::buildTree(in, post);
    prettyPrintTree(inpost);

    return 0;
}

/*
pre
[1,2,4,6,5,3,7,8,9]

post
[4,5,6,2,8,7,9,3,1]

in
[4,2,5,6,1,7,8,3,9]

prepost = [1,2,3,4,6,7,9,null,null,5,null,8]
prein = [1,2,3,4,6,7,9,null,null,5,null,null,8]
这两个前序都是 [1,2,4,6,5,3,7,8,9]
两个后序都是 [4,5,6,2,8,7,9,3,1]
不同的二叉树可以得到完全相同的前序和后续，此时由前后序列恢复二叉树只能恢复一种情况
inpost = [1,2,3,4,6,7,9,null,null,5,null,null,8]
*/