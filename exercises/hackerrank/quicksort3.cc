#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void printVector(const std::vector<int>& vec) {
  for (auto x : vec) {
	std::cout << x << " ";
  }
  std::cout << std::endl;
  return;
}

int partition(std::vector<int>& vec, int beg, int end) {
  int pivot = end;
  int it = beg;
  for (int i=beg; i<end; ++i) {
	if (vec[i] < vec[pivot]) {
	  std::swap(vec[i], vec[it]);
	  ++it;
	}
  }
  std::swap(vec[it], vec[pivot]);
  return it;
}

void quickSort(std::vector<int>& vec, int beg, int end) {
  int pivot;
  if (beg < end) {
	pivot = partition(vec, beg, end);
	printVector(vec);
	quickSort(vec, beg, pivot-1);
	quickSort(vec, pivot+1, end);
  }
  return;
}

void custom() {
  int n = 7;
  std::vector<int> arr = {1, 3, 9, 8, 2, 7, 5};
  quickSort(arr, 0, n-1);
  return;
}

void hackerRank() {
  int n; std::cin >> n;

  std::vector<int> arr(n);
  for(int i = 0; i<n; ++i) {
	std::cin >> arr[i];
  }

  quickSort(arr, 0, n-1);

  return;
}

int main() {
  //custom();
  hackerRank();
  return 0;
}
