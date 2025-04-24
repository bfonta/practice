#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// commented out solution is a viable but more cumbersome alternative
// based on a different sorting comparator
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	  // std::sort(people.begin(), people.end(), [](auto &left, auto &right) {
	  // 	return left[1] < right[1];
	  // });
	  std::sort(people.begin(), people.end(), [](auto &left, auto &right) {
		if (left[0] == right[0]) return left[1] < right[1];
		else return left[0] > right[0];
	  });

	  vector<vector<int>> out;
	  for (const auto& x : people) {
		// insertInQueue(x, out);
		out.insert(out.begin()+x[1], x);
	  }

	  return out;
    }

  void insertInQueue(const vector<int>& elem, vector<vector<int>>& que) {
	unsigned gt = 0;
	for (int i=0; i<elem[1]; ++i) {
	  if (que[i][0] >= elem[0]) ++gt;
	}

	unsigned idx = elem[1];
	for (int i=elem[1]; i<que.size(); ++i) {
	  if (que[i][0] > elem[0] and elem[1] == gt) {
		idx = i;
		break;
	  }
	  if (que[i][0] >= elem[0]) ++gt;

	  if (i == que.size()-1) {
		idx = que.size();
		break;
	  }
	}
	que.insert(que.begin() + idx, elem);
  }
};

void printVector(vector<vector<int>>& vec) {
  for (auto x : vec) {
	  for (auto y : x) {
		cout << y << " ";
	  }
	  if (x != vec[vec.size()-1])
		cout << ", ";
  }
  cout << endl;
}

int main(int argc, char** argv)
{
  Solution sol;

  vector<vector<int>> in1 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  vector<vector<int>> out1 = sol.reconstructQueue(in1);
  printVector(out1);
  
  vector<vector<int>> in2 = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
  vector<vector<int>> out2 = sol.reconstructQueue(in2);
  printVector(out2);
  
  return 0;
}
