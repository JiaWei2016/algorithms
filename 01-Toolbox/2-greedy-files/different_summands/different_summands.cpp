#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  int current = n;
  for (int i = 1; i <= n; i++) {
	  if (i==current || (i <= current && i+1 <= current - i)) {
		  summands.push_back(i);
		  current -= i;
	  }
	  if (current == 0)
		  break;
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
