#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maximumToys(vector<int> prices, int k) {
  int sum = 0, n;
  sort(prices.begin(), prices.end());
  for (int i=0; i<prices.size(); ++i) {
	if (sum > k) {
	  break;
	}
	sum += prices[i];
	n = i;
  }
  return n;
}

int main(int argc, char** argv)
{
  vector<int> prices = {1, 12, 5, 111, 200, 1000, 10};
  int tot = 50;
  cout << maximumToys(prices, tot) << endl;
  return 0;
}
