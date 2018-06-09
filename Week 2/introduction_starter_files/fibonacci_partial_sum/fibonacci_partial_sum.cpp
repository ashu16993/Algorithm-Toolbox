#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long * fibonacci_fast(long long n) {
    // write your code here
    static long long result[2];
	
	if(n==0)
	{
		result[0] = 0;
		result[1] = 0;
		return result;
	}
	if(n==1) 
	{		
		result[0] = 0;
		result[1] = 1;
		return result;
	}	
	    
	
    //int f[n] ;
    long long prev = 1; 
    long long curr = 1;
    long long fib;
    for(long long i =2;i<n; i++){
        fib=(curr+prev)%10;
		prev = curr;
		curr = fib;
    }
	
    // std::cout << prev << '\n';
    // std::cout << curr << '\n';
    
    
    result[0] = prev;
	result[1] = curr;

    return result;
}




long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    
	
	
	
	if (to<=1)
		return to;
	
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
    long long sum1 = 0;
	long long sum2 = 0;
    //long long quotient = n/60;
    long long remainder1 = from%60;
	long long remainder2 = to%60;
    //long long sum =0;
    
    //std::cout<<quotient<<" qu\n";
    //std::cout<<remainder<<" remainder\n";
	for(;i<60;i++){
		fib=(curr+prev)%10;
		prev = curr;
		curr = fib;
		sequence[i] = fib;
	}

    for (long long j = remainder1 ;j<60;j++)
		sum1 = (sum1 +sequence[j])%10;
    for(long long j=0;j<=remainder2;j++)
       sum2 = (sum2 +sequence[j])%10;
    
    result = (sum1+sum2)%10;
    return result;
	
	
	/*
	// std::cout<<"to "<<to<< '\n';
    // std::cout<<"from "<<from<< '\n';
    
    if (to <= 1)
        return to;
	
	long long *result;
	result = fibonacci_fast(from);
	
	if(to==from) 
		return (*(result+1)%10);
	
	long long prev = *(result+0);
	long long curr = *(result+1);
	long long fib;
	long long sum = curr;
	
    // std::cout <<"prev"<< prev << '\n';
    // std::cout <<"curr "<< curr << '\n';
    
    // std::cout<<" i "<<i<< '\n';
    for(long long i = (from+1); i <= to; i++) {
        
		//std::cout<<"Hello";
		fib = (prev +curr)%10;
		sum =(sum +fib)%10;
        prev = curr;
		curr = fib;
        
        //std::cout <<"fib"<< fib << '\n';
        //std::cout <<"sum"<< sum << '\n';
    }

    // long long sum = current;

    // for (long long i = 0; i < to - from; ++i) {
        // long long tmp_previous = previous;
        // previous = current;
        // current = tmp_previous + current;
        // sum += current;
    // }

    //return sum % 10;
	return sum;*/
}




int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	
	std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
