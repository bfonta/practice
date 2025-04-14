#include <iostream>
#include <stack>
#include <limits>

struct TreeNode {
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
};

using myType = long int;

class Solution {
public:

  // iterative
  // bool isValidBST(TreeNode* root) {
  // 	std::stack<std::tuple<TreeNode*, myType, myType>> astack;
  // 	astack.push(std::make_tuple(root, std::numeric_limits<myType>::min(), std::numeric_limits<myType>::max()));

  // 	while (not astack.empty())
  // 	  {
  // 		TreeNode* node = std::get<0>(astack.top());
  // 		myType min = std::get<1>(astack.top());
  // 		myType max = std::get<2>(astack.top());
  // 		astack.pop();

  // 		if (min >= node->val or max <= node->val) return false;

  // 		if (node->right != nullptr) astack.push(std::make_tuple(node->right, node->val, max));
  // 		if (node->left != nullptr) astack.push(std::make_tuple(node->left, min, node->val));
  // 	  }

  // 	return true;
  // }

  //recursive
  bool isValidBST(TreeNode* root) {
	return isValidBST_internal(root, std::numeric_limits<myType>::min(), std::numeric_limits<myType>::max());
  }

  bool isValidBST_internal(TreeNode* root, myType min, myType max) {
	if (root == nullptr) return true;
	if (root->val <= min or root->val >= max) return false;
	return isValidBST_internal(root->left, min, root->val) and isValidBST_internal(root->right, root->val, max);
  }

};

int main(int argc, char** argv)
{
  Solution sol;

  //first case
  TreeNode *root1 = new TreeNode();
  root1->val = 2;
  root1->left = new TreeNode();
  root1->left->val = 1;
  root1->right = new TreeNode();
  root1->right->val = 3;

  std::string out1 = sol.isValidBST(root1) ? "true" : "false";
  std::cout << out1 << std::endl;

  delete root1->left;
  delete root1->right;
  delete root1;

  //second case
  TreeNode *root2 = new TreeNode();
  root2->val = 5;
  root2->left = new TreeNode();
  root2->left->val = 1;
  root2->right = new TreeNode();
  root2->right->val = 4;
  root2->right->left = new TreeNode();
  root2->right->left->val = 3;
  root2->right->right = new TreeNode();
  root2->right->right->val = 6;

  std::string out2 = sol.isValidBST(root2) ? "true" : "false";
  std::cout << out2 << std::endl;

  delete root2->right->left;
  delete root2->right->right;
  delete root2->left;
  delete root2->right;
  delete root2;

  //third case
  TreeNode *root3 = new TreeNode();
  root3->val = 5;
  root3->left = new TreeNode();
  root3->left->val = 4;
  root3->right = new TreeNode();
  root3->right->val = 6;
  root3->right->left = new TreeNode();
  root3->right->left->val = 3;
  root3->right->right = new TreeNode();
  root3->right->right->val = 7;

  std::string out3 = sol.isValidBST(root3) ? "true" : "false";
  std::cout << out3 << std::endl; 

  delete root3->right->left;
  delete root3->right->right;
  delete root3->left;
  delete root3->right;
  delete root3;

  //fourth case
  TreeNode *root4 = new TreeNode();
  root4->val = 45;
  root4->left = new TreeNode();
  root4->left->val = 42;
  root4->left->right = new TreeNode();
  root4->left->right->val = 44;
  root4->left->right->left = new TreeNode();
  root4->left->right->left->val = 43;
  root4->left->right->left->left = new TreeNode();
  root4->left->right->left->left->val = 41;
  
  std::string out4 = sol.isValidBST(root4) ? "true" : "false";
  std::cout << out4 << std::endl; 

  delete root4->left->right->left->left;
  delete root4->left->right->left;
  delete root4->left->right;
  delete root4->left;
  delete root4;
  
  //fifth case
  TreeNode *root5 = new TreeNode();
  root5->val = 3;
  root5->left = new TreeNode();
  root5->left->val = 1;
  root5->right = new TreeNode();
  root5->right->val = 5;
  root5->left->left = new TreeNode();
  root5->left->left->val = 0;
  root5->left->right = new TreeNode();
  root5->left->right->val = 2;
  root5->left->right->right = new TreeNode();
  root5->left->right->right->val = 3;
  root5->right->left = new TreeNode();
  root5->right->left->val = 4;
  root5->right->right = new TreeNode();
  root5->right->right->val = 6;

  std::string out5 = sol.isValidBST(root5) ? "true" : "false";
  std::cout << out5 << std::endl;

  delete root5->left->right->right;
  delete root5->right->right;
  delete root5->right->left;
  delete root5->left->right;
  delete root5->left->left;
  delete root5->right;
  delete root5->left;
  delete root5;

  return 0;
}
