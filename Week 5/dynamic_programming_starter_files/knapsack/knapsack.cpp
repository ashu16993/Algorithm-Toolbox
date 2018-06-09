#include <iostream>
#include <vector>

using std::vector;

long long optimal_weight(int W, const vector<int> &w) {
  //write your code here
  long long current_weight = 0;
  std::vector<std::vector<long long>> values;
    
  values.resize((W+1), std::vector<long long>((w.size()+1), 0));  
  //int values[W+1][w.size()+1];
  for (size_t i = 0; i<(W+1);i++)
      for (size_t j = 0; j<(w.size()+1);j++)
	values[i][j]=0;
  
  
  
  for (size_t i = 1; i <= w.size(); ++i) {
	for(size_t j=1;j<=W;++j){
		values[j][i] = values[j][i-1];
		if(w[i-1]<=j){
			long long val = values[j-w[i-1]][i-1]+w[i-1];
           // std::cout<<val<<" "<<values[j][i]<<'\n';
			if(values[j][i]<val)
				values[j][i]=val;
		}
		
	}
  }
    
  // for (size_t i = 0; i <= w.size(); ++i) {
	// for(size_t j=0;j<=W ;++j){
        // std::cout<<values[j][i]<<" ";
    // }
    // std::cout<<'\n';
  // }
  current_weight = values[W][w.size()];
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
