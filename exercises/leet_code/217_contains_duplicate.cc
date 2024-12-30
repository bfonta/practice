#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> s;
  for(int i=0; i<nums.size(); ++i) {
	if(i!=0 and s.count(nums[i])==1) {
	  return true;
	}
	s.insert(nums[i]);
  }
  return false;
}

int main(int argc, char** argv)
{
  std::vector<int> nums1 = {1,2,3,1};
  std::vector<int> nums2 = {1,2,3,4};
  std::vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};  

  std::cout << containsDuplicate(nums1) << std::endl;
  std::cout << containsDuplicate(nums2) << std::endl;
  std::cout << containsDuplicate(nums3) << std::endl;
  return 0;
}
