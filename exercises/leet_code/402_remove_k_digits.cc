#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
	  unsigned l = num.size();
	  if (l==k or num=="0") return "0";

	  stack<char> out;
	  
	  // O(n) complexity
	  for (unsigned i=0; i<l; ++i)
		{
		  while (!out.empty()
				 and out.size() + l - i > l - k
				 and num[i]<out.top()) {
			out.pop();
		  }

		  if (out.size() < l - k) {
			out.push(num[i]);
		  }

		}

	  // Get output in std::string format
	  return convertToString(out);
    }

  string convertToString(stack<char> out) {
	std::string result;
	while (!out.empty()) {
	  result += out.top();
	  out.pop();
	}
	std::reverse(result.begin(), result.end());
	result.erase(0, result.find_first_not_of('0')); //remove leading zeros
	if (result=="") result = "0";
	return result;
  }

};

int main(int argc, char** argv)
{

  Solution sol;
  
  vector<string> num = {"1432219", "10200", "10", "112", "12345610", "234352111111"};
  vector<int> k = {{3, 1, 2, 1, 6, 6}};
  assert(num.size() == k.size());
  
  for (unsigned i=0; i<k.size(); ++i) {
	cout << sol.removeKdigits(num[i], k[i]) << endl;
  }

  return 0;
}

