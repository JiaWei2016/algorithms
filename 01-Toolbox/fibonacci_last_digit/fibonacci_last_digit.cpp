#include <iostream>

int get_fibonacci_last_digit(int n) {
	int result;
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		int *F = new int[n + 1];
		F[0] = 0;
		F[1] = 1;
		for (int i = 2; i <= n; i++) {
			F[i] = (F[i - 1] + F[i - 2]) % 10;
		}
		result = F[n];
		delete[] F; 
		F = NULL;
	}
	return result;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
