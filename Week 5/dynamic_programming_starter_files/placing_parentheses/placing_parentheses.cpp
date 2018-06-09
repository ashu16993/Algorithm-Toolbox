#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void min_max(int i,int j,vector<std::vector<long long>> &M,vector<std::vector<long long>> &m,char* op){
	
	long long min = 2147483647;
	long long max =-2147483648;
	for(int k=i;k<j;k++){
        
        //std::cout<<M[i][k]<<" "<<op[k]<<'\n';
    
        
		long long a = eval(M[i][k],M[k+1][j],op[k]);
		long long b = eval(M[i][k],m[k+1][j],op[k]);
		long long c = eval(m[i][k],M[k+1][j],op[k]);
		long long d = eval(m[i][k],m[k+1][j],op[k]);
		min = std::min(min,std::min(a,std::min(b,std::min(c,d))));
        
        //std::cout<<"min "<<min<<"\n";
		max = std::max(max,std::max(a,std::max(b,std::max(c,d))));
        //std::cout<<"max "<<max<<"\n";
    }
	m[i][j] = min;
	M[i][j]=max;
  	
}

long long get_maximum_value(char* operand, char* op,int size) {
  //write your code here
	vector<std::vector<long long>> M;
	vector<std::vector<long long>> m;
    //std::cout<<sizeof(operand)<<"\n";
    //std::cout<<std::strlen(operand)<<"\n";
    
	M.resize(size, std::vector<long long>(size, 0));  
	m.resize(size, std::vector<long long>(size, 0));    
    /*for(int i=0;i<sizeof(operand);i++)
	  std::cout<<operand[i]<<" ";
     std::cout<<"\n"; 
    */
    for(int i=0;i<size;i++){
		M[i][i]= (int)operand[i] - 48;
		m[i][i]=(int)operand[i] - 48;
       // std::cout<<operand[i]<<" "<<M[i][i]<<"\n";
	}
	
	for(int s =1;s<size;s++){
		for(int i=0;i<(size-s);i++)
		{
            
			int j = i+s;
         //   std::cout<<"i "<<i<<" j "<<j<<'\n';
            /*
            std::cout<<"size "<<sizeof(operand)<<"\n";
            std::cout<<"i "<<i<<" j "<<j<<'\n';
            */
			min_max(i,j,M,m,op);
		}
	}
    
    /*
    for(int i =0;i<size;i++){
        for(int j=0;j<size;j++)
            std::cout<<M[i][j]<<" ";
        std::cout<<"\n";
    }
      */  
	return M[0][size-1];
}

int main() {
  string s;
  std::cin >> s;
  const char *cstr1 = s.c_str();
//  std::cout<<"length "<<s.length();
  char operand[(s.length()/2)+1];
  char op[s.length()/2];
  for(int i=0;i<s.length();i+=2){
	operand[i/2] = cstr1[i];  
  }
  for(int i=1;i<s.length();i+=2){
	op[i/2] = cstr1[i];  
  }
  /*
  for(int i=0;i<sizeof(operand);i++)
	  std::cout<<operand[i]<<" ";
  
  std::cout<<"\n";
  
  
  for(int i=0;i<sizeof(op);i++)
	  std::cout<<op[i]<<" ";
  */
   int size = s.length()/2 + 1;
  //std::cout <<size<<" ";  
  std::cout << get_maximum_value(operand,op,size) << '\n';
}
