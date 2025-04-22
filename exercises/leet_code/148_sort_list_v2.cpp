#include <iostream>
#include <stdexcept>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
	ListNode* out = mergeSort(head);
	return out;
  }

private:
  ListNode* mergeSort(ListNode* head) {

	if (head == nullptr or head->next == nullptr)
	  return head;

	ListNode* mid = findMid(head);
	ListNode *left = head;
	ListNode *right = mid->next;
	mid->next = nullptr;

	left = mergeSort(left);
	right = mergeSort(right);

	return merge(left, right);
  }

  ListNode* findMid(ListNode* head) {
	// ListNode* aux = head;
	// unsigned counter = 0;

	// // lenght of the list
	// while (head) {
	//   head = head->next;
	//   ++counter;
	// }

	// // find the middle node from the start of the list
	// counter /= 2;
	// while (counter-1) {
	//   aux = aux->next;
	//   --counter;
	// }
	
	// return aux;
	
	ListNode* slow = head;
	ListNode* fast = head->next;
	
	while (fast != nullptr and fast->next != nullptr) {
	  slow = slow->next;
	  fast = fast->next->next;
	}
	return slow;
  }
  
  ListNode* merge(ListNode* left, ListNode* right) {
	if (!left and !right) return nullptr;

	ListNode dummy;
	ListNode* it = &dummy;
	while (left and right) {
	  if (left->val < right->val) {
		it->next = left;
		left = left->next;
	  }
	  else {
		it->next = right;
		right = right->next;
	  }
	  it = it->next;
	}

	it->next = left ? left : right;
	
	return dummy.next; 
  }
  
};

void printList(ListNode* l) {
  while (l->next) {
	std::cout << l->val << " ";
	l = l->next;
  }
  std::cout << l->val << std::endl;
}

int main(int argc, char** argv)
{
  Solution sol;

  ListNode* tmp1_1 = new ListNode(3);
  ListNode* tmp1_2 = new ListNode(1, tmp1_1);
  ListNode* tmp1_3 = new ListNode(2, tmp1_2);
  ListNode* list1 = new ListNode(4, tmp1_3);
  ListNode* out1 = sol.sortList(list1);
  printList(out1);

  delete tmp1_1, tmp1_2, tmp1_3, list1;
  
  return 0;
}
