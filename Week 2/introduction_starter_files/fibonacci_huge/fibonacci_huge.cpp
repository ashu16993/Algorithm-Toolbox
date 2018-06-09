#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n,long long m){
	if (n<=1)
		return n;
	
	long long sequence[6*m];
	sequence[0]=0;
	sequence[1]=1;
	long long prev =0;
	long long curr = 1;
	long long val;
    long long result;
	long long i=2;
    long long fib;
	for(;i<n+1;i++){
		fib=(curr+prev)%m;
		prev = curr;
		curr = fib;
		sequence[i] = fib;
        /*if(sequence[i] <0)
        {
            std::cout<<" i at error " << i<<'\n';
            std::cout<<" fib at error " << fib<<'\n';
            std::cout<<" prev at error " << prev<<'\n';
        }*/
		if((fib) ==0){
			fib=(curr+prev)%m;
			
			if(fib == 1){
				i--;
				break;
			}
		}
	}
	//print(sequence);
    //for(long long j=0;j<=i;j++)
    //    std::cout<<sequence[j]<<" ";
    
	//print(len(sequence))
    i = i+1;
    //std::cout<<"i "<<i<<'\n';
	val = n %i ;
    //std::cout<<"val "<<val<<'\n';
	result = sequence[val];
	return result;
	
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
