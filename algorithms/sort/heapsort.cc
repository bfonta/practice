#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

// min-heap
template <typename T>
class Heap {
public:
  Heap(const vector<T> vec) {
	data.resize(vec.size());

	for (auto i=0; i<vec.size(); ++i) {
	  data[i] = vec[i];
	  bubble_up(i);
	}

	s = data.size();
  }

  size_t size() const {
	return s;
  }

  auto begin() const {
	return data.begin();
  }

  auto end() const {
	return data.end();
  }

  T extract_min() {
	T min = data[0];

	swap(data[0], data[s-1]); // store in-place
	s--;

	try {
	  bubble_down(0);
	}
	catch (out_of_range) {}

	return min;
  }

  void reverse() {
	std::reverse(data.begin(), data.end());
  }
  
private:
  vector<T> data;
  size_t s;

  void bubble_up(unsigned index) {
	unsigned parent;
	try {  
	  parent = id_parent(index);
	}
	catch (out_of_range) {
	  return;
	}

	if (data[parent] > data[index]) {
	  swap(data[parent], data[index]);
	  bubble_up(parent);
	}

	return;
  }

  void bubble_down(unsigned index) {
	unsigned old, young, minval, minidx;
	try {
	  old = id_old_child(index);
	}
	catch (out_of_range) {
	  try {
		old = 0; // impossible, thus can be used as a flag
		young = id_young_child(index);
	  }
	  catch (out_of_range) { return; } //no leaves
	}

	if (old != 0) { // one leaf only
	  young = id_young_child(index);
	  if (data[old] > data[young]) {
		minval = data[young];
		minidx = young;
	  }
	  else {
		minval = data[old];
		minidx = old;	
	  }
	}
	else { // two leaves
	  minval = data[young];
	  minidx = young;
	}

	swap(data[minidx], data[index]);
	bubble_down(minidx);

	return;
  }

  unsigned id_parent(unsigned index) {
	if (index==0) {
	  throw out_of_range("Requesting the parent of the root node!");	
	}
	return ((index + 1) / 2) - 1;
  }

  unsigned id_old_child(unsigned index) {
	unsigned child = (index + 1) * 2;
	if (child >= s) {
	  throw out_of_range("The child does not exist!");
	}
	return child;
  }

  unsigned id_young_child(unsigned index) {
	unsigned child = (index + 1) * 2 - 1;
	if (child >= s) {
	  throw out_of_range("The child does not exist!");
	}
	return child;
  }

};

template <typename T>
void heapsort(Heap<T>& heap) {
  while (heap.size() > 1) {
	heap.extract_min();
	//print(heap);
  }
  return;
}

template <typename T>
void print(const Heap<T>& heap) {
  for (auto x : heap) cout << x << " ";
  cout << endl;
}

int main(int argc, char** argv)
{
  Heap<int> heap( vector<int>{6, 4, 8, 2, 9, 1, 7, -2, -10, 6, 6, 6, 2, 5} );
  
  print(heap);
  
  heapsort(heap);
  heap.reverse();
  
  print(heap);
  
  return 0;
}
