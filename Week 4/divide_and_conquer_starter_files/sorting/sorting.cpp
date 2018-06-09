#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  
  vector<int> points(2);
  int j= l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
 
  
  int m = j;
    for(int i =j;i>=0;i--){
      if(a[i]==x)
          m--;
      else
          break;
    }
  /*for(int i=0;i<a.size();i++)
      std::cout<<a[i]<<' ';
  std::cout<<'\n';*/
  points[0] = m+1;
  points[1] =j;
    
  return points;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  //int k = l + rand() % (r - l + 1);
  
  int mid = (l+r)/2;
  int k;
  if(a[l]<a[r]){
	if(a[mid]<=a[l])
		k = l;
	else{
		if(a[mid]<=a[r])
			k=mid;
		else
			k=r;
	}
  }
  else{
	if(a[mid]<=a[r])
		k = r;
	else{
		if(a[mid]<=a[l])
			k=mid;
		else
			k=l;
	}  
  } 
  
  //std::cout<<k<<' '<<a[k]<<'\n';
  swap(a[l], a[k]);
  vector<int> m = partition2(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
