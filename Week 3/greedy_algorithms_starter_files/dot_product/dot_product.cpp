#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//using std::vector;
using namespace std;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  //int size_of_a = sizeof(a)/sizeof(a[0]);
  //int size_of_b = sizeof(b)/sizeof(b[0]);
  //cout<<size_of_a<<" "<<size_of_b<<'\n';
  std::sort(a.begin(),a.end());
  std::sort(b.begin(),b.end());
  
  
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
