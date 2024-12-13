#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void bubbleSort(vector<T>& v) {
  bool flip = true;
  while (flip) {
	flip = false;
	for(int i=1; i<v.size(); ++i) {
	  if (v[i] < v[i-1]) {
		flip = true;
		std::swap(v[i], v[i-1]);
	  }
	}
  }
}

template <typename T>
void bubbleSortOptimized(vector<T>& v) {
  bool flip = true;
  int n = v.size();
  while (flip) {
	flip = false;
	for(int i=1; i<n; ++i) {
	  if (v[i] < v[i-1]) {
		flip = true;
		std::swap(v[i], v[i-1]);
	  }
	}
	n -= 1;
  }
}

int main(int argc, char *argv[])
{
  std::vector<int> vec = {5, 2, 4, 6, 1, 3};
  bubbleSortOptimized(vec);

  for(auto &v: vec) {
	std::cout << v << " ";
  }
  std::cout << std::endl;

  return 0;
}
