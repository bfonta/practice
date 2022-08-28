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

  auto insert(Node node) -> bool
  {
	if (!mHeadNode) {
	  mHeadNode = std::make_shared<Node>(node);
	  return true;
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

  auto mInsert(NodePtr& curr_node, Node& new_node) -> bool
  {
	if (new_node.data < curr_node->data) {
	  if (curr_node->left)
		return mInsert(curr_node->left, new_node);
	  else {
		curr_node->left = std::make_shared<Node>(new_node);
		new_node.parent = curr_node;
		return true;
	  }
	}
	else {
	  if (curr_node->right)
		return mInsert(curr_node->right, new_node);
	  else {
		curr_node->right = std::make_shared<Node>(new_node);
		new_node.parent = curr_node;
		return true;
	  }
	}
	return false;
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
