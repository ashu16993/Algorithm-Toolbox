# Uses python3
import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m
	
	
def get_fibonacci_huge_fast(n,m):
	if (n<=1):
		return n;
	
	sequence =[];
	sequence.append(0);
	sequence.append(1);
	prev =0;
	curr = 1;
	
	i=2
	while i <n+1:
		fib=(curr+prev)%m;
		prev = curr;
		curr = fib;
		sequence.append(fib));
		if((fib%m) ==0):
			fib=(curr+prev;)%m
			#print("i ",i)
			
			if(fib%m == 1):
				sequence.pop();
				break;
	
		i+=1;
		
	#print(sequence);
	#print(len(sequence))
	val = n % len(sequence);#print(val)
	result = sequence[val];
	return result;

if __name__ == '__main__':
	input = sys.stdin.read();
	n, m = map(int, input.split())
	#print(get_fibonacci_huge_naive(n, m))
	print(get_fibonacci_huge_fast(n, m))
