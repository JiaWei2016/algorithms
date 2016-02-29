#include <iostream>

int gcd(int a, int b) {
  //write your code here
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd2(int a, int b) {
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

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd2(a, b) << std::endl;
  return 0;
}
