#include <iostream>

int calc_fib(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}

long long calc_fib2(int n) {
	long long result;
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		long long *F = new long long[n + 1];
		F[0] = 0;
		F[1] = 1;
		for (int i = 2; i <= n; i++) {
			F[i] = F[i - 1] + F[i - 2];
		}
		result = F[n];
		delete[] F;
		F = NULL;

		return result;
	}

}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib2(n) << '\n';
    return 0;
}
