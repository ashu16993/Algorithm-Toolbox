#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void optimal_value(vector<int> &calc,int n){
	if(n==1)
		calc[n]= 0;
	else{
		int min = 0;
		int min1 = 2147483647;
		int min2 = 2147483647;
		int min3 = 2147483647;
		if(n%3==0){
			min1 = calc[n/3];
		}
		if(n%2==0){
			min2 = calc[n/2];
		}
		min3 = calc[n-1];
		min = std::min(min1,std::min(min2,min3));
		calc[n] = min+1;
	}
	
}

vector<int> optimal_sequence(int n) {
	vector<int> calc(n+1);
    vector<int> sequence;
	calc[0]=0;
	for(int i =1;i<=n;i++){
		optimal_value(calc,i);
		//std::cout<<calc[i]<<'\n';
	}
	//std::cout<<calc[n]<<'\n';
    sequence.push_back(n);
    for(int i = n ;i>1;){
        if(i%3 ==0){
            if(calc[i] -1 == calc[i/3]){
                sequence.push_back(i/3);
                i=i/3;
                continue;
            }
        }
        if(i%2 ==0){
            if(calc[i]-1 == calc[i/2]){
               sequence.push_back(i/2);
               i=i/2;
               continue;
            }
        }
        sequence.push_back(i-1);
        i-=1;   
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
               
}



int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
   for (size_t i = 1; i < sequence.size(); ++i) {
     std::cout << sequence[i] << " ";
   }
  
  //optimal_sequence(n);
}
