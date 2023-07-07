#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
	for(int i=0; i<nums.size(); ++i)
	  {
		int n = target - nums[i];
		for(int j=0; j<nums.size(); ++j)
		  {
			if(i==j) continue;
			if(n == nums[j])
			  return {i, j};
		  }
	  }
	return {0};
  }
};

void printVec(vector<int>& vec) {
  for (auto &x : vec) {
	std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  vector<int> inputs1 = {2,7,11,15};
  int target1 = 9;
  
  vector<int> inputs2 = {3,2,4};
  int target2 = 6;
  
  vector<int> inputs3 = {3,3};
  int target3 = 6;
  
  Solution sol;
  vector<int> res1 = sol.twoSum(inputs1, target1);
  printVec(res1);
  
  vector<int> res2 = sol.twoSum(inputs2, target2);
  printVec(res2);
  
  vector<int> res3 = sol.twoSum(inputs3, target3);
  printVec(res3);
  
  return 0;
}
