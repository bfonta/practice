#include<iostream>
#include<vector>
using namespace std;

// 1. Must run in O(n)
// 2. Cannot use the division operation

// O(n) time, O(n) space
vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> res(nums.size());
  vector<int> left(nums.size(), 1.);
  vector<int> right(nums.size(), 1.);
  for(int i=1; i<nums.size(); ++i) {
	left[i] = left[i-1] * nums[i-1];
  }
  for (int i=nums.size()-2; i>=0; --i) {
	right[i] = right[i+1] * nums[i+1];
  }
  for(int i=0; i<nums.size(); ++i) {
	res[i] = left[i] * right[i];
  }
  return res;
}

// O(n) time, O(1) space
vector<int> productExceptSelf2(vector<int>& nums) {
  vector<int> res(nums.size(), 1);
  for(int i=1; i<nums.size(); ++i) {
	res[i] = res[i-1] * nums[i-1];
  }
  int right = 1;
  for (int i=nums.size()-1; i>=0; --i) {
	res[i] *= right;
	right *= nums[i];
  }
  return res;
}

void printArray(vector<int>& v) {
  for(int i=0; i<v.size(); ++i) {
    cout << v[i] << " ";
  }
  std::cout << std::endl;
}
  
int main(int argc, char** argv)
{
  vector<int> prompt1 = {1,2,3,4};
  vector<int> prompt2 = {-1,1,0,-3,3};
  vector<int> res1 = productExceptSelf(prompt1);
  vector<int> res2 = productExceptSelf(prompt2);
  printArray(res1);
  printArray(res2);

  vector<int> res3 = productExceptSelf2(prompt1);
  vector<int> res4 = productExceptSelf2(prompt2);
  printArray(res3);
  printArray(res4);

  return 0;
}
