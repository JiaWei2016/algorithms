#include <iostream>

int gcd(int a, int b) {
	int num, den;
	int rem = 0;
	//initializations first
	if (a > b) {
		num = a;
		den = b;
	}
	else {
		num = b;
		den = a;
	}
	//get the remainder, reassign num and den
	do {
		rem = num % den;
		num = den;
		den = rem;
	} while (rem > 0);

	return num;
}

long long lcm(int a, int b) {
	int temp = gcd(a, b);
	return (long long)a*b / temp;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
