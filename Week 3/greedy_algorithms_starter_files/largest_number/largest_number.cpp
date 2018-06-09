#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string.h>

using std::vector;
using std::string;

bool IsGreaterOrEqual(string a , string b){
	 const char *n1 = a.c_str();
	 const char *n2 = b.c_str();
	 int length =0;
	 if(n2[0]=='-')
		 return true;
	
	// if(strlen(num2)>strlen(num1))
		// length = strlen(num1);
	// else
		// length = strlen(num2);
    
    // int i;
	// for(i=0;i<length;i++){
		// if(num1[i]>num2[i])
			// return true;
		// else if (num1[i]<num2[i])
			// return false;
		
	// }
	
    // if(num1[i]){
        // if(num1[i]<num2[i-1])
            // return false;
        // else
            // return true;
    // }
    // else if(num2[i]){
        // if(num2[i]<num1[i-1])
            // return true;
        // else
            // return false;
    // }
    // return true;
	
	string a1= a + b;
	string b1 = b + a;
	
	int num1 = stoi(a1);
	int num2 = stoi(b1);
	
    if(num1>num2)
        return true;
    else
        return false;
	return true;
}


string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  while(a.size()!=0){
	  string maxDigit ="-1";
	  int position = -1;
	  for(size_t i = 0; i < a.size(); i++){
		  if(IsGreaterOrEqual(a[i],maxDigit)){
			  maxDigit = a[i];
			  position = i;
		  }
	  }
	  ret << maxDigit;
	  a.erase (a.begin()+position);
  }
  
  
  // for (size_t i = 0; i < a.size(); i++) {
    // ret << a[i];
  // }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}



/* 
100
2 8 2 3 6 4 1 1 10 6 3 3 6 1 3 8 4 6 1 10 8 4 10 4 1 3 2 3 2 6 1 5 2 9 8 5 10 8 7 9 6 4 2 6 3 8 8 9 8 2 9 10 3 10 7 5 7 1 7 5 1 4 7 6 1 10 5 4 8 4 2 7 8 1 1 7 4 1 1 9 8 6 5 9 9 3 7 6 3 10 8 10 7 2 5 1 1 9 9 5


1 1 10 1 1 10 10 1 1 10 10 10 1 1 1 10 1 1 1 1 10 10 1 1
*/