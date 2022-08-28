#include <iostream>
#include <memory>
#include <vector>

/*
Using shared pointers since the same resource (a node)
can be pointed at by multiple nodes.
*/

class Node {
public:
  Node(float data_): data(data_) {}
  float data;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  std::shared_ptr<Node> parent;
};

class SimpleTree
{
  using NodePtr = std::shared_ptr<Node>;
  
public:
  SimpleTree() {}

  auto contains(Node node) -> bool {return false;}

  auto insert(Node node) -> NodePtr
  {
	if (!mHeadNode) {
	  mHeadNode = std::make_shared<Node>(node);
	  return mHeadNode;
	}
	return mInsert(mHeadNode, node);
  }

  //multiple insertions done in order
  auto insert(const std::vector<Node>& nodes) -> bool {
	for (const auto& x : nodes) {
	  insert(x);
	}
	return true;
  }
  
  auto print_tree() -> void {
	if (mHeadNode)
	  mPrintTree(mHeadNode);
	std::cout << std::endl;
  }
  
  auto remove(Node node) -> bool {return false;}

private:
  NodePtr mHeadNode;

  auto mInsert(NodePtr& root, Node& add) -> NodePtr
  {
	//recursion termination condition
	if (!root)
	  return std::make_shared<Node>(add);

	NodePtr cur;
	if (add.data < root->data) {
	  cur = mInsert(root->left, add);
	  root->left = cur;
	}
	else {
	  cur = mInsert(root->right, add);
	  root->right = cur;
	}
	cur->parent = root;
	return root;
  }

  auto mPrintTree(const NodePtr& node) -> void {
	if (node->left)
	  mPrintTree(node->left);
	std::cout << node->data << " ";
	if (node->right)
	  mPrintTree(node->right);
  }
};


int main()
{
  SimpleTree t;

  const int num_nodes = 15;
  std::vector<Node> vec;
  for (int i=num_nodes; i>0; --i)
	vec.emplace_back( static_cast<float>(i) );
  t.insert(vec);

  std::vector<Node> vec2;
  for (int i=num_nodes; i>0; --i)
	if(i%5==0) 
	  vec2.emplace_back( static_cast<float>(i) );
  t.insert(vec2);

  t.print_tree();
  return 0;
}
