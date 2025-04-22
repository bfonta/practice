// tried to implement quickSort, which is NOT efficietn for single linked lists
// there is some memory segmentation fault I did not fix

#include <iostream>

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
	ListNode* out = quickSort(head);
	return out;
  }

private:
  ListNode* quickSort(ListNode* head, ListNode* tail=nullptr) {

	ListNode* mid = partition(head, tail);

	// if (head != mid) quickSort(head, mid);
	// if (mid->next != tail) quickSort(mid->next, tail);

	return mid;
  }

  ListNode* partition(ListNode* head, ListNode* end) {
	ListNode* pivot = head;
	ListNode* firsthigh = head;

	int counter = 0;
	ListNode* elem = head;
	while (elem != end) {
	  if (elem->val < pivot->val) {
		swap(elem, firsthigh, head);
		elem = firsthigh->next;

		++counter;
		firsthigh = defineFirstHigh(counter, head);
	  }
	  else {
		elem = elem->next;
	  }
	}

	swap(pivot, firsthigh, head);
	
	return pivot;
  }

  ListNode* defineFirstHigh(int counter, ListNode* head) {
	while (counter-->0) {
	  head = head->next;
	}
	return head;
  }
  
  // first always comes before second (or they are identical)
  void swap(ListNode* first, ListNode* second, ListNode* head) {
	ListNode* before_first;
	ListNode* before_second;

	if (head == first) before_first = nullptr;
	if (head == second) before_second = nullptr;
	
	while (head) {
	  if (head->next == first) before_first = head;
	  if (head->next == second) before_second = head;
	  head = head->next;
	}

	if (before_first) {
	  before_first->next = second;
	}
	if (before_second) {
	  before_second->next = first;
	}
	first->next = second->next;
	second->next = first->next;
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
