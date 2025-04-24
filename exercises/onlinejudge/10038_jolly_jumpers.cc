#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> vec) {
  for(auto x : vec) cout << x << " ";
  cout << endl;
}

bool is_jj(const vector<int>& in)
{
  int n = in.size();
  vector<int> hash(n-1, 0);

  for(int i=0; i<n-1; ++i) {
	int diff = abs(in[i+1]-in[i]);
	if (diff > n-1) return false;
    hash[diff-1]++; //hash diffs between 1 and n
  }

  for(auto x : hash) {
	if (x != 1) return false;
  }
  return true;
}

std::string jj(const vector<int>& in)
{
  return is_jj(in) ? "Jolly" : "Not jolly";
}

int main(int argc, char** argv)
{
  vector<int> in1 = {1, 4, 2, 3};
  vector<int> in2 = {1, 4, 2, -1, 6};
  vector<int> in3 = {-1};
  vector<int> in4 = {2, -1, 0, 2};
  vector<int> in5 = {19, 22, 24, 25};
  vector<int> in6 = {19, 22, 24, 21};

  cout << jj(in1) << endl;
  cout << jj(in2) << endl;
  cout << jj(in3) << endl;
  cout << jj(in4) << endl;
  cout << jj(in5) << endl;
  cout << jj(in6) << endl;

  return 0;
}

// int main() {
//   int n;

//   while( scanf("%d", &n) != EOF )
// 	{
// 	  vector<int> in(n);
// 	  std::cout << n << std::endl;
// 	  for(int i=0; i<n; ++i) {
// 		scanf("%d", &in[i]);
// 	  }
  
// 	  cout << jj(in) << endl;
// 	}
   
//   return 0;
// }
