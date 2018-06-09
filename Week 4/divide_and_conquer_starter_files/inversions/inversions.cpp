#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a,vector<int> &b, size_t left,size_t mid, size_t right){
	
	long long inversion_count = 0;
	size_t i = left;
	size_t j = mid;
	size_t pos = left;
	while(i<mid && j<right){
		if(a[i]<=a[j]){
			b[pos] = a[i];
			i++;
		}
		else{
			b[pos]=a[j];
			j++;
			inversion_count+= (mid - i );
            //inversion_count++;
		}
		pos++;
	}
	for(;pos<right;pos++){
		if(i<mid){
			b[pos]=a[i];
			i++;
		}
		else{
			b[pos]=a[j];
			j++;
		}
	}
	for(size_t k = left; k<right;k++){
		a[k]=b[k];
	}
	return inversion_count;
}


long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  number_of_inversions += merge(a,b,left, ave , right);
  
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  
  /*for (size_t i = 0; i < a.size(); i++) {
    std::cout<< a[i];
  }*/
    
  
}
