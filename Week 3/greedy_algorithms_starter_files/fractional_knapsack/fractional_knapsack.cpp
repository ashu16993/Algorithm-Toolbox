#include <algorithm>
#include <iostream>	
#include <vector>
#include <bits/stdc++.h>

//using std::vector;
//using std::min;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values,vector<std::pair<double,int>> value_by_weight) {
	double value = 0.0;
	int size = weights.size();
	std::sort(value_by_weight.begin(),value_by_weight.end(),greater<pair<double,int>>());
	// write your code here
	for(int i =0;i<size;i++){
		if(capacity==0)
			return value;
		/*double max_value_per_kg = 0;
		int max_index=-1;
		for(unsigned int i=0;i<weights.size();i++){
			if(max_value_per_kg<(double(values[i])/weights[i])){
				max_value_per_kg = double(values[i])/weights[i];
				max_index =i;
			}
		}*/
        
		// int weight_input = weights[max_index];
		// if(weights.size()!=1)
            // weights.erase(weights.begin()+ (max_index));
		// int value_input = values[max_index];
		// if(weights.size()!=1)
			// values.erase(values.begin()+ (max_index));
		int weight = weights[value_by_weight[i].second];
		
		
		int input_weight = std::min(weight, capacity);
        //std::cout<<weights.size()<<" "<<values.size()<<'\n';
		//std::cout<<input_weight<<" "<<value_input<<" "<<max_value_per_kg<<'\n';
        value = value + input_weight*value_by_weight[i].first;
		capacity = capacity-input_weight;
		
	}
  

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  
  //n = std::rand()%1000;
  //capacity = std::rand()%10000;
  vector<int> values(n);
  vector<int> weights(n);
  vector<std::pair<double,int>> value_by_weight(n);
    double temp =0.00;
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
	temp = double(values[i])/weights[i];
	value_by_weight.push_back(std::make_pair(temp,i));
   //values[i] = std::rand()%10000;
   //weights[i] = std::rand()%10000;
  }

  double optimal_value = get_optimal_value(capacity, weights, values,value_by_weight);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
