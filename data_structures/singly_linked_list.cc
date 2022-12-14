#include <iostream>
#include <memory>
#include <iomanip>

/*
Reference:
https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/
*/

struct Node
{
  float data;
  std::unique_ptr<Node> next;
  Node(float _data): data(_data) {}
  Node(Node* _ptr): data(_ptr->data), next(_ptr) {}
  // ~Node() {
  // 	std::cout << "Node " + std::to_string(data).substr(0, 4) << + " deleted." << std::endl;
  // }
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
	if (!head)
	  return;

	Node *cur = head.get();
	while (cur->next != nullptr) {
	  print();
	  cur = head.get();
	  head = std::move(cur->next);
	  cur->next = std::move(head->next);
	  head->next = std::make_unique<Node>(cur);
	  std::cout << "end iteration" << std::endl;
	}
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
  for(int i=0; i<4; ++i)
	l.push(i);
  l.print();
  l.reverse();
  l.print();
  return 0;
}
