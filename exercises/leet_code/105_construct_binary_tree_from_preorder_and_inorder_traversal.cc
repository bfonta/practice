#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* builtTree_recursive(unordered_map<int, int>& mp, const vector<int>& preorder,
								int& preIdx, int start, int end) {
	if (start > end) return nullptr;
	
	int val = preorder[++preIdx];
	int inIdx = mp[val];
	
	TreeNode* root = new TreeNode(val);
	root->left = builtTree_recursive(mp, preorder, preIdx, start, inIdx-1);
	root->right = builtTree_recursive(mp, preorder, preIdx, inIdx+1, end);

	return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	unordered_map<int, int> mp;
	for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;

	int start = 0;
	int end = inorder.size()-1;
	int preIdx = -1;
	TreeNode* root = builtTree_recursive(mp, preorder, preIdx, start, end);
	return root;
  }

  void deleteTree(TreeNode* root) {
	if(root == nullptr) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
  }
};

void printInternal(TreeNode*);

void printTree(TreeNode* node)
{
  printInternal(node);
  cout << endl;
}

void printInternal(TreeNode* node)
{
  if(node) cout << node->val << " ";
  
  if (node->left) printInternal(node->left);
  else cout << "null ";
  
  if (node->right) printInternal(node->right);
  else cout << "null ";
}

int main(int argc, char** argv)
{
  Solution sol;
  vector<vector<int>> preorder = {
	{3, 9, 20, 15, 7},
  };
  vector<vector<int>> inorder = {
	{9, 3, 15, 20, 7},
  };
  
  for(int i=0; i<preorder.size(); ++i) {
	TreeNode* out = sol.buildTree(preorder[i], inorder[i]);
	printTree(out);
	sol.deleteTree(out);
  }

  return 0;
}
