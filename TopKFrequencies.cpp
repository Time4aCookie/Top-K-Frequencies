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
bool cmp(pair<int, int>&a, pair<int, int> &b ){
	return a.second>b.second;
}

/*Option 1:
make map, then make vector based on frequency from highest to lowest then resize to k
Option 2:
iterate through keeping track of smallest frequency in ans vector replace number if its frequency exceeds n reset smallest
 */
vector<int> TopKFrequencies::topKFrequentOptimal(vector<int> &nums, int k) {
	map<int, int> mp;
	vector<int> answer(k);
	for(int i = 0; i < nums.size(); ++i) {
		auto it = mp.insert({nums[i], 1});
		if (it.second == false) {
			it.first->second++;
		}
	}
	vector<pair<int,int>> ans(mp.begin(), mp.end());
	sort(ans.begin(), ans.end(), cmp);
	for(int i = 0; i < k; ++i) {
		answer[i] = ans[i].first;
	}
	return answer;
}


