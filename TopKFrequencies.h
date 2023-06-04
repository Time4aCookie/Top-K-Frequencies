// Created by Rohan Tatikonda on 6/4/23.
#include"vector"
#include "map"
#include <iostream>

using namespace std;
class TopKFrequencies{
public:
	vector<int> topKFrequent(std::vector<int>& nums, int k);
	vector<int> topKFrequentOptimal(vector<int>& nums, int k);
	friend ostream & operator<<(ostream& os, const vector<int>& k);
};
	ostream & operator<<(ostream& os, const vector<int>& k);
