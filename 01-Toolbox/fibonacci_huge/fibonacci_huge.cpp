#include <iostream>
long long get_fib(long long n, long long m) {
	long long fib[] = { 0, 1, 1 };
	if (n < 3) {
		return fib[n] % m;
	}
	int i = 3;
	while (i <= n) {
		fib[0] = fib[1] % m;
		fib[1] = fib[2] % m;
		fib[2] = ((fib[1] % m) + (fib[0] % m)) % m;
		i++;
	}
	return fib[2];
}

int get_pisanoperiod(long long m) {
	long long fib[] = { 0, 1, 1 };
	long long mod[] = { 0, fib[1] % m, fib[2] % m };
	if (m <  2) {
		return m;
	}

	int i = 3;
	while (true) {
		fib[0] = fib[1];
		fib[1] = fib[2];
		fib[2] = fib[1] + fib[0];
		mod[0] = mod[1];
		mod[1] = mod[2];
		mod[2] = (mod[1] + mod[0]) % m;
		
		if ((mod[2] == 0) && ((mod[1] + mod[2]) % m == 1)) {
			return i;
		}
		i++;
	}
}

long long get_fibonaccihuge(long long n, long long m) {
	//we want to calculate {fib(n) mod m}
	//if fib(n) is very large, we get {r = n mod pisano(m)}
	//then we can calculate fib(r) mod m

	int pisano = get_pisanoperiod(m);
	//std::cout << "pisano(" << m << ")=" << pisano << '\n';

	long long r = n % pisano;
	//std::cout << "r = n mod pissano(m) : " << r << '\n';

	long long fib = get_fib(r, m);
	//std::cout << "fib(r) % m = " << fib << '\n';
	
  return fib;
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonaccihuge(n, m) << '\n';
}
