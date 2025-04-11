#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
	vector<int> result(n+1);
	
	// O(n)
	for(int i=0; i<=n; ++i) {
	  if(i==0) result[i] = 0;
	  else result[i] = countOnes(i);
	}

	return result;
  }

  int countOnes(int val) {
	unsigned nbits = log2(val)+1;
	int ones=1;
	for(int i=nbits-1; i>=0; --i) {
	  int x = val - pow(2, i);
	  if (x == 0) {
		break;
	  }
	  else if (x > 0) {
		++ones;
		val = x;
	  }
	}
	return ones;
  }

  vector<int> countBitsAdvanced(int n) {
	vector<int> result(n+1);
	result[0] = 0;
	if(n==0) return result;

	vector<unsigned> repr(log2(n)+1, 0); //could be optimized to use actual bits

	int ones = 0;
	
	// O(n)
	for(int i=1; i<=n; ++i) {

	  for(int j=0; j<=repr.size(); ++j) { //loop within the binary representation
		if (repr[j] == 0) {
		  repr[j] = 1;
		  ++ones;
		  for(int k=j-1; k>=0; --k) {
			repr[k] = 0;
			--ones;
		  }
		  break;
		}
	  }
	  result[i] = ones;
	}
	return result;
  }
};

int main(int argc, char** argv)
{
  Solution sol;
  vector<int> n = {2, 5};
  
  for(int i=0; i<n.size(); ++i) {
	vector<int> out = sol.countBits(n[i]);
	cout << i << ": " ;
	for (int i: out) cout << i << ' ';
	cout << endl;
  }

  cout << endl;
  for(int i=0; i<n.size(); ++i) {
	vector<int> out = sol.countBitsAdvanced(n[i]);
	cout << i << ": " ;
	for (int i: out) cout << i << ' ';
	cout << endl;
  }

  return 0;
}
