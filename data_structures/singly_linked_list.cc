#include <iostream>
#include <memory>

struct Node
{
  float data;
  std::unique_ptr<Node> next;
  Node(float _data): data(_data) {}
  ~Node() { "Node " + std::to_string(data) + "deleted."; }
};
  
class SingleLinkedList_ConstantInsertionTime
{
public:
  void push(float data) {
	auto tmp{std::make_unique<Node>(data)};

	if (!head)
	  head = std::move(tmp);
	else {
	  tmp->next = std::move(head);
	  head = std::move(tmp);
	}
  }

  void pop() {
	if (!head)
	  return;
	std::unique_ptr<Node> tmp = std::move(head);
	head = std::move(tmp->next);
  }

  void print() {
	Node *cur = head.get();
	while(cur) {
	  std::cout << cur->data << ' ';
	  cur = cur->next.get();
	}
	std::cout << std::endl;
  }

  void reverse() {

  }
  
private:
  std::unique_ptr<Node> head;
};

class SingleLinkedList_LinearInsertionTime
{
public:
  void push(float data);
  void pop();
  void print();
  
private:
  std::unique_ptr<Node> head;
};

int main(int argc, char** argv)
{
  SingleLinkedList_ConstantInsertionTime l;
  for(int i=0; i<10; ++i)
	l.push(i);
  l.pop();
  l.push(45);
  l.print();
  return 0;
}
