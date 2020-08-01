#include <iostream>
#include<vector>
#include<queue>
#include <climits>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    二叉树的构造
*/

TreeNode* initree(TreeNode* root, vector<int>& in) {//root进行了初始化
	vector<int>::iterator ptr = in.begin() + 1;
	queue<TreeNode*> s;
	s.push(root);
	int cnt = 1;
	while (ptr != in.end()) {
		TreeNode* temp = s.front();
		s.pop();
		vector<TreeNode**> node_list = {&temp->left, &temp->right};
		for(auto node : node_list){
			if (*ptr != INT_MAX) {
				*node = new TreeNode(*ptr++);
				s.push(*node);
			} else {
				ptr++;
			}
		}
	}
	return root;
}

/*
    二叉树的输出,leetcode-655
*/

class printt {

public:

	/* 递归求树的高度 */
    int treeHeight(TreeNode* root){
        if(root==NULL) return 0;
	    else if(root->left == NULL && root->right==NULL)
        return 1;
	    return max(treeHeight(root->left)+1,treeHeight(root->right)+1) ;
    }

	/*  */
    vector<vector<string>> printTree(TreeNode* root){
		int m = treeHeight(root);
		int n = pow(2, m) - 1;
		vector<vector<string>> res(m, vector<string>(n, "")); // 二维向量的构造方式
		insertPrint(root, res, 0, 0, n - 1);
		return res;
    }
 
	/*  */
    void insertPrint(TreeNode* root, vector<vector<string>>& res, int row,int left, int right){
	    if (root == NULL || (left > right)) return;
	    int mid = (left + right) /2;
	    res[row][mid] = to_string(root->val);
	    insertPrint(root->left, res, row + 1, left, mid);
	    insertPrint(root->right, res, row + 1, mid + 1, right);
    }

};


int main()
{
	vector<int> a;
	a = { 1,2,3,4,5,6,7,8,9 };
	TreeNode* t = new TreeNode(a[0]); // 构造根节点
	TreeNode* tree = initree(t, a);
    printt print_fun;
    auto res = print_fun.printTree(tree);
    for(vector<string> w: res){
        for(auto vi = w.begin();vi!=w.end();vi++)
            cout<<*vi<<" ";
        cout<<endl;
    }
    return 0;
}

// ————————————————
// 版权声明：本文为CSDN博主「rikochet」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/cgl1552188038/article/details/97614963