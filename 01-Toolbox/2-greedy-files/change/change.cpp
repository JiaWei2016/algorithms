#include <iostream>

int get_change(int n) {
	int coins[] = { 10, 5, 1 };
	int i = 0;
	int counter = 0;

	while (n > 0) {
		while (n < coins[i]){
			i++;
		}
		n = n - coins[i];
		counter++;
	}

  return counter;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
