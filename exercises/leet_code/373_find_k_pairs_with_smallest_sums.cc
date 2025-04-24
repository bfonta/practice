// this version is bugged, since it skips some pairs whenever the right combination lies to the left of the last selected pair
// the solution lies in a min-heap, pushing all [i+1,j], [i,j+1] combinations to avoid ignoring some pairs

#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	  vector<vector<int>> out;
	  method1(out, nums1, nums2, k);
	  return out;
    }

  void method1(vector<vector<int>>& out, const vector<int>& nums1, const vector<int>& nums2, int k) {
	if (nums1.size() == 0 or nums2.size() == 0) return;
	
	unsigned it1=0, it2=0;
	out.push_back(vector<int>{nums1[it1], nums2[it2]});

	int opt1, opt2;
	while (out.size() < k) {
	  if (it2+1 >= nums2.size()) {
		out.push_back(vector<int>{nums1[it1+1], nums2[it2]});
		++it1;
	  }
	  else if (it1+1 >= nums1.size()) {
		out.push_back(vector<int>{nums1[it1], nums2[it2+1]});
		++it2;
	  }
	  else {
		opt1 = nums1[it1] + nums2[it2+1];
		opt2 = nums1[it1+1] + nums2[it2];
		if (opt1 > opt2) {
		  out.push_back(vector<int>{nums1[it1+1], nums2[it2]});
		  ++it1;
		}
		else {
		  out.push_back(vector<int>{nums1[it1], nums2[it2+1]});
		  ++it2;
		}
	  }
	}
  }
};

void printVector(vector<vector<int>>& vec) {
  for (auto x : vec) {
	  for (auto y : x) {
		cout << y << " ";
	  }
	  cout << ", ";
  }
  cout << endl;
}

int main(int argc, char** argv)
{
  Solution sol;

  std::array<vector<int>, 2> in1 = {{{1,7,11}, {2,4,6}}};
  vector<vector<int>> out1 = sol.kSmallestPairs(in1[0], in1[1], 3);
  printVector(out1);

  std::array<vector<int>, 2> in2 = {{{1,1,2}, {1,2,3}}};
  vector<vector<int>> out2 = sol.kSmallestPairs(in2[0], in2[1], 2);
  printVector(out2);

  std::array<vector<int>, 2> in3 = {{{1,2,4,5,6}, {3,5,7,9}}};
  vector<vector<int>> out3 = sol.kSmallestPairs(in3[0], in3[1], 3);
  printVector(out3);
  
  return 0;
}
