#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void insertionSort(vector<T>& v) {
  for(int i=1; i<v.size(); ++i) {
	T key = v[i];
	int j = i-1;
	while(j>=0 and v[j] > key) {
	  v[j+1] = v[j];
	  --j;
	}
	v[j+1] = key;
  }
}

int main(int argc, char *argv[])
{
  //std::vector<float> vec = {1.4, 6.8, 3.4, 1.0, 7.9, -1.4};
  std::vector<int> vec = {5, 2, 4, 6, 1, 3};
  insertionSort(vec);

  for(auto &v: vec) {
	std::cout << v << " ";
  }
  std::cout << std::endl;

  return 0;
}
