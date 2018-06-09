#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


long long fibonacci_sum_fast(long long n) {

	if (n<=1)
		return n;
	
	long long sequence[60];
	sequence[0]=0;
	sequence[1]=1;
	long long prev =0;
	long long curr = 1;
	//long long val;
    //long long result;
	long long i=2;
    long long fib;
    long long result;
    long long extrasum = 0;
    //long long quotient = n/60;
    long long remainder = n%60;
    //long long sum =0;
    
    //std::cout<<quotient<<" qu\n";
    //std::cout<<remainder<<" remainder\n";
	for(;i<60;i++){
		fib=(curr+prev)%10;
		prev = curr;
		curr = fib;
		sequence[i] = fib;
       	/* if((fib) ==0){
			fib=(curr+prev)%10;
			
			if(fib == 1){
				i--;
				break;
			}
		}*/ 
	}
	//print(sequence);
    
    //std::cout<<i<<" i\n";
    
    /*for(long long j=0;j<i;j++)
       sum = (sum +sequence[j])%10;    
    
    std::cout<<sum<<" sum\n";*/
    
    for(long long j=0;j<=remainder;j++)
       extrasum = (extrasum +sequence[j])%10;
    //std::cout<<extrasum<<" extra\n";
    
   // result = (sum*quotient + extrasum)%10;
    
    result = (extrasum)%10;
	//print(len(sequence))
    //i = i+1;
    //std::cout<<"i "<<i<<'\n';
	//val = n %60 ;
    //std::cout<<"val "<<val<<'\n';
	//result = sequence[val];
	
	
    //int f[n] ;
	
    //f[0] = 1; 
    //f[1] = 1;
    /*
	long long prev = 1; 
    long long curr = 1;
    long long fib;
    for(long long i =2;i<n; i++){
        fib=(curr+prev)%10;
		prev = curr;
		curr = fib;
		sum = (sum + fib)%10;
    }
	
	*/
	
    // for(long long i =2;i<n; i++){
        // f[i]=(f[i-1]+f[i-2])%10;
		// sum = (sum + f[i])%10;
    // }
    return result;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
