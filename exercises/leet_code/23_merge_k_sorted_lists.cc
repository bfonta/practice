#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
	//   if (!lists.size()) return nullptr;
	  
	//   ListNode head;
	//   ListNode* it = &head;
	//   int amin;
	//   int idx = 0;

	//   while (!std::all_of(lists.begin(), lists.end(),
	// 					  [](ListNode* ptr) { return ptr == nullptr; })) {
		
	// 	amin = numeric_limits<int>::max();

	// 	for (int i=0; i<lists.size(); ++i) {
	// 	  if (lists[i] and lists[i]->val < amin) {
	// 		amin = lists[i]->val;
	// 		idx = i;
	// 	  }
	// 	}
	// 	it->next = lists[idx];
	// 	lists[idx] = lists[idx]->next;
	// 	it = it->next;
	//   }
	  
	//   return head.next;
    // }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (!lists.size()) return nullptr;

	// convert to vector
	vector<int> vec;
	for (int i=0; i<lists.size(); ++i) {
	  while (lists[i]) {
		vec.push_back(lists[i]->val);
		lists[i] = lists[i]->next;
	  }
	}

	sort(vec.begin(), vec.end());

	// convert back to linked list
	ListNode head;
	ListNode* aux = &head;
	for (auto x : vec) {
	  aux->next = new ListNode(x);
	  aux = aux->next;
	}
	return head.next;
  }
};

void printList(ListNode* l) {
  if (!l) {
	cout << "empty" << endl;
	return;
  }
  
  while (l->next) {
	std::cout << l->val << " ";
	l = l->next;
  }
  std::cout << l->val << std::endl;
}

int main(int argc, char** argv)
{
  Solution sol;

  ListNode* tmp1_1 = new ListNode(5);
  ListNode* tmp1_2 = new ListNode(4, tmp1_1);
  ListNode* tmp1_3 = new ListNode(1, tmp1_2);

  ListNode* tmp2_1 = new ListNode(4);
  ListNode* tmp2_2 = new ListNode(3, tmp2_1);
  ListNode* tmp2_3 = new ListNode(1, tmp2_2);

  ListNode* tmp3_1 = new ListNode(6);
  ListNode* tmp3_2 = new ListNode(2, tmp3_1);

  vector<ListNode*> in1 = {tmp1_3, tmp2_3, tmp3_2};
  ListNode* out1 = sol.mergeKLists(in1);
  printList(out1);

  vector<ListNode*> in2 = {};
  ListNode* out2 = sol.mergeKLists(in2);
  printList(out2);

  vector<ListNode*> in3 = {{}};
  ListNode* out3 = sol.mergeKLists(in3);
  printList(out3);

  vector<ListNode*> in4 = {{}, {}, {}, {}};
  ListNode* out4 = sol.mergeKLists(in4);
  printList(out4);

  return 0;
}
