#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
  int max = -1e-10;
  int mult=1, mult_neg=1;
  bool has_zero=false, has_pos=false, is_last_zero;
  if(nums.size()==1)
	return nums[0];
  
  for (int i=0; i<nums.size(); ++i) {
	is_last_zero = false;
	if(nums[i]==0) {
	  has_zero = true;
	  if(has_pos) {
		max = max < mult ? mult : max;
	  }
	  else {
		max = max < mult_neg ? mult_neg : max;
	  }
	  mult = 1;
	  mult_neg = 1;
	  has_pos = false;
	  is_last_zero = true;
	}
	else {
	  if(nums[i]<0 and mult_neg<0) {
		has_pos = true;
		mult = mult_neg * nums[i];
		mult_neg = 1;
	  }
	  else if(nums[i]<0 and mult_neg>0) {
		mult_neg = mult * nums[i];
	  }
	  else if(nums[i]>0 and mult_neg<0) {
		has_pos = true;
		mult_neg *= nums[i];
	  }
	  else if(nums[i]>0 and mult_neg>0) {
		has_pos = true;
		mult *= nums[i];
	  }
	}
  }

  if(has_pos and !is_last_zero) {
	max = max < mult ? mult : max;
  }
  else if(!is_last_zero) {
	max = max < mult_neg ? mult_neg : max;
  }

  if(max < 0 and has_zero) {
	max = 0;
  } 
  return max;
}

int main(int argc, char** argv)
{
  vector<int> prompt1 = {2, 3, -2, 4};
  cout << maxProduct(prompt1) << endl;

  vector<int> prompt2 = {-2, 0, -1};
  cout << maxProduct(prompt2) << endl;

  vector<int> prompt3 = {-2};
  cout << maxProduct(prompt3) << endl;

  vector<int> prompt4 = {-3,-1,-1};
  cout << maxProduct(prompt4) << endl;

  vector<int> prompt5 = {-2,0};
  cout << maxProduct(prompt5) << endl;

  vector<int> prompt6 = {3,-1,4};
  cout << maxProduct(prompt6) << endl;

  return 0;
}
