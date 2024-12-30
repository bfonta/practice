#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printStack(stack<int> st) {
  for (std::stack<int> dump = st; !dump.empty(); dump.pop()) {
	std::cout << dump.top() << " ";
  }
  std::cout << std::endl;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
	  vector<int> answer(temperatures.size(), 0);
	  stack<int> stack;

	  for (int i = 0; i < temperatures.size(); i++) {
		while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
		  answer[stack.top()] = i - stack.top();
		  stack.pop();
		}
		stack.push(i);
		printStack(stack);
	  }
	  
	  return answer;
    }

  vector<int> naive(vector<int>& temperatures) {
	vector<int> answer(temperatures.size(), 0);

	for (int i = 0; i < temperatures.size(); i++) {
	  int val = temperatures[i];
	  int j = i+1;
	  while (j < temperatures.size() and temperatures[j] <= val) {
		j++;
	  }
	  if (j < temperatures.size())
		answer[i] = j-i;
	}
	  
	return answer;
  }
};

void printVec(vector<int>& vec) {
  for (auto &x : vec) {
	std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  vector<int> temps1 = {73,74,75,71,69,72,76,73}; //daily temperatures
  vector<int> temps2 = {30,40,50,60}; 
  vector<int> temps3 = {30,60,90}; 
  
  Solution sol;

  vector<int> res1 = sol.naive(temps1);
  vector<int> res2 = sol.naive(temps2);
  vector<int> res3 = sol.naive(temps3);

  vector<int> res4 = sol.dailyTemperatures(temps1);
  vector<int> res5 = sol.dailyTemperatures(temps2);
  vector<int> res6 = sol.dailyTemperatures(temps3);

  std::cout << std::endl;
  std::cout << "answers:" << std::endl;
  printVec(res1);
  printVec(res2);
  printVec(res3);
  std::cout << std::endl;
  printVec(res4);
  printVec(res5);
  printVec(res6);
  
  return 0;
}

