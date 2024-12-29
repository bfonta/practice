#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <utility>
#include <algorithm>
#include <limits>

using crd = std::pair<double,double>;
using vcrd = std::vector<std::pair<double,double>>;

double dist(crd a, crd b)
{
  double d2 = (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
  return std::sqrt(d2);
}

namespace vecutils {
  void pop(vcrd& v, crd elem)
  {
	v.erase(std::find(v.begin(), v.end(), elem));
  }
  
  void print(const vcrd& v)
  {
	for (const crd& elem: v)
	  {
		std::cout << "(" << elem.first << "," << elem.second << ")" << std::endl;
	  }
  }
};
  
vcrd nearestNeighbour(vcrd v) // page 6
{
  vcrd out(v.size()); // result has same length as input
  out[0] = v[0]; // select starting point
  unsigned counter = 1;
  
  crd first = out[0];
  while (v.size() > 0)
	{
	  vecutils::pop(v, first);
	  double d = std::numeric_limits<double>::max();
	  for (crd& i : v)
		{
		  if (dist(first, i) < d)
			{
			  d = dist(first, i);
			  out[counter] = i;
			}
		}
	  first = out[counter];
	  ++counter;
	}
  return out;
}

vcrd closestPair(vcrd v) // page 7
{
  using lcrd = std::list<crd>;
  using vlcrd = std::vector<std::list<crd>>;
  
  vcrd out(v.size()); // result has same length as input
  vlcrd chains(v.size()); // all (dynamic) chains

  for (unsigned i=0; i<chains.size(); ++i)
	{
	  chains[i] = std::list{v[i]}; // list with single element
	}

  bool full = false;
  unsigned final_idx;
  
  bool isfront1, isfront2;
  std::pair<unsigned,unsigned> newp;
  double d;

  while (!full)
	{
	  d = std::numeric_limits<double>::max();
	  
	  // loop over all chain possible matches to find shortest chain element distance
	  for(unsigned i=0; i<chains.size(); ++i) {
		for(unsigned j=0; j<chains.size(); ++j)
		  {
			// points will belong to the same chain
			// or one of the chains is empty (UB behaviour for empty lists)
			if(i == j or chains[i].empty() or chains[j].empty())
			  {
				continue;
			  }
			
			if (dist(chains[i].front(), chains[j].front()) < d)
			  {
				d = dist(chains[i].front(), chains[j].front());
				isfront1 = true;
				isfront2 = true;
			  }
			else if (dist(chains[i].front(), chains[j].back()) < d)
			  {
				d = dist(chains[i].front(), chains[j].back());
				isfront1 = true;
				isfront2 = false;
			  }
			else if (dist(chains[i].back(), chains[j].front()) < d)
			  {
				d = dist(chains[i].back(), chains[j].front());
				isfront1 = false;
				isfront2 = true;
			  }
			else if (dist(chains[i].back(), chains[j].back()) < d)
			  {
				d = dist(chains[i].back(), chains[j].back());
				isfront1 = false;
				isfront2 = false;
			  }
			else
			  {
				continue;
			  }
			newp = std::make_pair(i, j);	
		  }
	  }

	  // copy element in j chain to i chain and delete element in j chain
	  if (isfront1 and isfront2)
		{
		  chains[newp.first].push_front(chains[newp.second].front());
		  chains[newp.second].pop_front();
		}
	  else if(isfront1 and !isfront2)
		{
		  chains[newp.first].push_front(chains[newp.second].back());
		  chains[newp.second].pop_back();
		}
	  else if(!isfront1 and isfront2)
		{
		  chains[newp.first].push_back(chains[newp.second].front());
		  chains[newp.second].pop_front();
		}
	  else if(!isfront1 and !isfront2)
		{
		  chains[newp.first].push_back(chains[newp.second].back());
		  chains[newp.second].pop_back();
		}

	  // termination condition: a single chain with all input elements
	  for(unsigned q=0; q<chains.size(); ++q)
		{
		  if (chains[q].size() == v.size())
			{
			  full = true;
			  final_idx = q;
			  break;
			}
		}
	}

  // store to output format
  out = std::vector(chains[final_idx].begin(), chains[final_idx].end());
  return out;
}

int main(int argc, char *argv[])
{
  vcrd input = {{0,0}, {-5,0}, {-1,0}, {1,0}, {3,0}, {11,0}, {-21,0}};
  vcrd out = nearestNeighbour(input);
  std::cout << "Result neasrestNeighbours" << std::endl;
  vecutils::print(out);

  std::cout << std::endl;
  
  vcrd input2 = {{0,0}, {-5,0}, {-1,0}, {1,0}, {3,0}, {11,0}, {-21,0}};
  vcrd out2 = closestPair(input);
  std::cout << "Result closestPairs" << std::endl;
  vecutils::print(out2);
  return 0;
}
