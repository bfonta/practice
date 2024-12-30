#include<iostream>
#include<vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(std::vector<double> v)
{
  ListNode* node = new ListNode(v[v.size()-1], nullptr);

  std::vector<double>::reverse_iterator it;
  for (it = v.rbegin()+1; it != v.rend(); ++it)
	{
	  node = new ListNode(*it, node);
	}
  return node;
}

void printList(ListNode* head)
{
  while(true)
	{
	  if(head==nullptr) break; // empty list
	  
	  std::cout << head->val;
	  if(head->next==nullptr)
		{
		  std::cout << std::endl;
		  break;
		}
	  else
		{
		  std::cout << ", ";
		}
	  head = head->next;
	}
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
	  if(head==nullptr) return nullptr; // empty list
	  if(k==0) return head; // no rotation
	  
	  ListNode* first = head;
	  unsigned length=0;
	  while(true)
		{
		  ++length;
		  if(head->next == nullptr) break;
		  head = head->next;
		}
	  head->next = first;

	  k = k%length; // avoid bugs when k > length
	  for(unsigned i=1; i<=length-k; ++i)
		{
		  if(i==length-k)
			{
			  head = first->next;
			  first->next = nullptr;
			  break;
			}
		  first = first->next;
		}

	  return head;
    }
};

int main(int argc, char** argv)
{
  std::vector<double> input1 = {1,2,3,4,5};
  std::vector<double> input2 = {0,1,2};
  Solution sol;
  
  ListNode* head1 = createList(input1);
  printList(head1);
  ListNode* out1 = sol.rotateRight(head1, 2);
  printList(out1);

  std::cout << std::endl;

  ListNode* head2 = createList(input2);
  printList(head2);
  ListNode* out2 = sol.rotateRight(head2, 4);
  printList(out2);

  return 0;
}
