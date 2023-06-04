// Created by Rohan Tatikonda on 6/4/23.
#include"TopKFrequencies.h"
#pragma once
using namespace std;

vector<int> TopKFrequencies::topKFrequent(std::vector<int> &nums, int k) {
	map<int, int> mp;
	vector<int> ans(k, 0);
	for(int i = 0; i < nums.size(); ++i) {
		auto it = mp.insert({nums[i], 1});
		if(it.second == false){
			it.first->second++;
		}
		for(int j = 0; j < k; ++j){
			auto find = mp.find(ans[j]);
			if(find != mp.end()){
				if(it.first->second > find->second && std::find(ans.begin(), ans.end(),it.first->first) == ans.end()){ // if our key's frequency greater than one of the vector position's frequency and our key isn't already in the vector
					ans[j] = it.first->first;
					break;
				}
			}
			else if(find == mp.end() && std::find(ans.begin(), ans.end(),it.first->first) == ans.end()){
				ans[j] = it.first->first;
				break;
			}
		}
	}
	return ans;
}

ostream & operator<<(ostream& os, const vector<int>& k){
	cout << "[";
	for(int i = 0; i < k.size(); ++i){
		cout << " "<< k[i];
	}
	cout <<" ]";
	return os;
}

vector<int> TopKFrequencies::topKFrequentOptimal(vector<int> &nums, int k) {
	map<int, int> mp;
	vector<int> ans(k, 0);
	for(int i = 0; i < nums.size(); ++i) {
		auto it = mp.insert({nums[i], 1});
		if(it.second == false){
			it.first->second++;
		}

}

