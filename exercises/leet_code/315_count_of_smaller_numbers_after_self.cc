#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
	//vector<int> answer = bruteForce(nums);
	//vector<int> answer = dynamicCount(nums);
	vector<int> answer = cumulativeCount(nums);
	return answer;
  }

  vector<int> bruteForce(vector<int>& nums) {
	int s = nums.size();
	vector<int> out(s);
	
	for(int i=0; i<s; ++i) {
	  unsigned count = 0;
	  for(int j=i+1; j<s; ++j) {
		if (nums[j] < nums[i]) ++count;
	  }
	  out[i] = count;
	}

	return out;
  }

  vector<int> dynamicCount(vector<int>& nums) {
	int s = nums.size();
	vector<int> out(s);
	
	vector<int> indices(2*1e4+1, 0);
	for(int i=0; i<s; ++i) {++indices[nums[i]+1e4];} //build hash table

	int old_pos = 0, pos;
	int count = 0;
	for(int k=0; k<s; ++k) {
	  pos = nums[k]+1e4;
	  if (pos > old_pos) {
		for(int w=old_pos; w<pos; ++w) {count+=indices[w];}
	  }
	  else {
		for(int w=old_pos-1; w>=pos; --w) {count-=indices[w];}
	  }

	  out[k] = count;
	  --indices[pos];
	  old_pos = pos;
	}

	return out;
  }

  vector<int> cumulativeCount(vector<int>& nums) {
	vector<int> out(nums.size());

	vector<int> indices(2*1e4+1, 0);
	for(int i=0; i<nums.size(); ++i) {++indices[nums[i]+1e4];} //build hash table

	int acc_count = 0;
	for(int i=0; i<indices.size(); ++i) {  //convert to accumulative
	  acc_count += indices[i];
	  indices[i] = acc_count;
	}

	int pos;
	for(int i=0; i<nums.size(); ++i) {
	  pos = nums[i]+1e4;
	  if (pos==0) out[i] = 0;
	  else out[i] = indices[pos-1];
	  for(int j=pos; j<indices.size(); ++j) --indices[j];
	}

	return out;
  }

  vector<int> cumulativeCount(vector<int>& nums) {
	vector<int> out(nums.size());

	vector<int> indices(2*1e4+1, 0);
	for(int i=0; i<nums.size(); ++i) {++indices[nums[i]+1e4];} //build hash table

	int acc_count = 0;
	for(int i=0; i<indices.size(); ++i) {  //convert to accumulative
	  acc_count += indices[i];
	  indices[i] = acc_count;
	}

	int pos;
	for(int i=0; i<nums.size(); ++i) {
	  pos = nums[i]+1e4;
	  if (pos==0) out[i] = 0;
	  else out[i] = indices[pos-1];
	  for(int j=pos; j<indices.size(); ++j) --indices[j];
	}

	return out;
  }

};

void printVector(vector<int>& vec)
{
  for(auto x : vec) { cout << x << " ";}
  cout << endl;
}

int main(int argc, char** argv)
{
  Solution sol;
  std::vector<int> nums1 = {5, 2, 6, 1};
  std::vector<int> nums2 = {-1};
  std::vector<int> nums3 = {-1, -1};
  std::vector<int> nums4;
  for(int i=-1E4; i<=1E4; ++i) {
	nums4.push_back(i);
  }

  std::vector<int> out1 = sol.countSmaller(nums1);
  printVector(out1);
  
  std::vector<int> out2 = sol.countSmaller(nums2);
  printVector(out2);

  std::vector<int> out3 = sol.countSmaller(nums3);
  printVector(out3);

  std::vector<int> out4 = sol.countSmaller(nums4);
  //printVector(out4);

  return 0;
}
