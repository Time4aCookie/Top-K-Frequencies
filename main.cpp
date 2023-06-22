// Created by Rohan Tatikonda on 6/4/23.
#include "TopKFrequencies.h"
#include "iostream"

using namespace std;

int main(int argc, char * argv[]){

	TopKFrequencies test;
	vector<int> example{1,1,2,3,3,3,4,5,6};
	vector<int> answer = test.topKFrequentOptimal(example, 2);
	cout << answer << endl;

}