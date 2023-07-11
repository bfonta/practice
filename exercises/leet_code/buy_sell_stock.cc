#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
  int maxProfitBruteForce(vector<int>& prices) {
	int maxprof = 0;
	for(int i=0; i<prices.size(); ++i) {
	  for(int j=i+1; j<prices.size(); ++j) {
		if(prices[j] - prices[i] > maxprof) {
		  maxprof = prices[j] - prices[i];
		}
	  }
	}
	return maxprof;
  }

  int maxProfitDivideAndConquer(vector<int>& prices) {
	if(prices.size()<2) {
	  return 0;
	}
	vector<int> diffs(prices.size()-1);
	for(int i=1; i<prices.size(); ++i) {
	  diffs[i-1] = prices[i]-prices[i-1];
	}

	tuple<int,int,int> res = findMaxSubArray(diffs, 0, diffs.size()-1);

	if(get<2>(res) < 0) {
	  return 0.;
	}
	return get<2>(res);
  }

  tuple<int,int,int> findMaxSubArray(vector<int>& arr, int low, int high) {
	if(low==high) {
	  return make_tuple(low, high, arr[low]);
	}
	int mid=(low+high)/2;

	tuple<int,int,int> res_left  = findMaxSubArray(arr, low, mid);
	tuple<int,int,int> res_right = findMaxSubArray(arr, mid+1, high);
	tuple<int,int,int> res_cross = findMaxSubArrayCrossing(arr, low, mid, high);

	if(get<2>(res_left) >= get<2>(res_right) and get<2>(res_left) >= get<2>(res_cross)) {
	  return res_left;
	}
	else if(get<2>(res_right) >= get<2>(res_left) and get<2>(res_right) >= get<2>(res_cross)) {
	  return res_right;
	}
	else {
	  return res_cross;
	}
  }
	
  tuple<int,int,int> findMaxSubArrayCrossing(vector<int>& arr, int low, int mid, int high) {
	int max_left = -1;
	int ref_left = -9e5;
	int sum_left = 0;
	for (int i=mid; i>=low; --i) {
	  sum_left += arr[i];
	  if(sum_left > ref_left) {
		ref_left = sum_left;
		max_left = i;
	  }
	}

	int max_right = 1;
	int ref_right = -9e5;
	int sum_right = 0;
	for (int i=mid+1; i<=high; ++i) {
	  sum_right += arr[i];
	  if(sum_right > ref_right) {
		ref_right = sum_right;
		max_right = i;
	  }
	}
	
	return make_tuple(max_left,max_right,ref_left+ref_right);
  }
};

int main(int argc, char** argv)
{
  // vector<int> prices1 = {7,1,5,3,6,4};
  // vector<int> prices2 = {7,6,4,3,1};
  // vector<int> prices3 = {1};
  // vector<int> prices4 = {-1, -2, -6, -8, -3};

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist100(1,100); // distribution in range [1, 6]

  int nrep = 1000;
  auto dtotal1=0, dtotal2=0;
  ofstream out("buy_sell_stock.csv", std::ios_base::out);
	
  // std::vector<int> sizes = {100, 200, 300, 400, 500, 750, 1000, 2000, 3000, 4000, 5000, 7500, 10000, 15000, 20000, 35000, 50000};
  // for (auto &n : sizes)
  for (int n=1; n<30; ++n)
	{
	  for (int m=1; m<nrep; ++m) {
		vector<int> prices(n);
		for(int i=0; i<n; ++i) {
		  prices[i] = dist100(rng);
		}
		
		Solution sol;
		
		auto begin = std::chrono::high_resolution_clock::now();
		int res1 = sol.maxProfitBruteForce(prices);
		auto mid = std::chrono::high_resolution_clock::now();
		int res2 = sol.maxProfitDivideAndConquer(prices);
		auto end = std::chrono::high_resolution_clock::now();

		dtotal1 += std::chrono::duration_cast<std::chrono::nanoseconds>(mid-begin).count();
		dtotal2 += std::chrono::duration_cast<std::chrono::nanoseconds>(end-mid).count();
	  }

	  double time1 = (dtotal1/nrep)/1E9;
	  double time2 = (dtotal2/nrep)/1E9;
	  cout << time1 << " " << time2 << endl;
	  out << n << ", " << time1 << ", " << time2 << endl;
	}

  out.close();
  
  return 0;
}
