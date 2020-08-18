#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define null 9999

// 层序遍历构造二叉树

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x):left(nullptr),right(nullptr),val(x){}
};


// 层序遍历构造一棵树

TreeNode* makestree(vector<int> input){
    if(input.size() ==0 ) return nullptr;
    if(input[0] == null) return nullptr;
    TreeNode* root = new TreeNode(input[0]);
    int ind  = 1;
    queue<TreeNode* >q;
    q.push(root);
    while(ind != input.size()){
        TreeNode* tmp = q.front();
        q.pop();
        cout<<q.size()<<endl;
        if(input[ind]!=null){
            tmp->left = new TreeNode(input[ind]);
            q.push(tmp->left);
        }
        if(++ind == q.size()){
            break;
        }
        if(input[ind]!=null){
            tmp->right = new TreeNode(input[ind]);
            q.push(tmp->right);
        }
        if(++ind == q.size()){
            break;
        }
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

vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode*> s;
    vector<int> v;
    TreeNode* rt = root;
    while(s.size()|| rt){
        while(rt){
            s.push(rt);
            rt=rt->left;
        }
        rt = s.top();
        s.pop();
        v.push_back(rt->val);
        rt= rt->right;
    }
    return v;
}
// D B E F A G H C I
// D B E F A G H C I
void printv(vector<int> input) {
    for (auto i : input) {
        // cout << i << " ";
        cout << char(i - 1 + 'A') << " ";
    }
    cout << endl;
}

int main(){

    vector<int> input = {1, 2, 3, 4, 6, 7, 9, null, null, 5, null, null, 8};
    TreeNode *root = makestree(input);
    prettyPrintTree(root);
    auto res = inorderTraversal(root);
    printv(res);
    return 0;
}