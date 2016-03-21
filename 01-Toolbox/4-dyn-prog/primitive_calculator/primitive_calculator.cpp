#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
	std::vector<int> min_op;

	min_op.push_back(0);
	min_op.push_back(0);
	min_op.push_back(1);
	min_op.push_back(1);

	int i = 4;
	while (i <= n) {
		int min = min_op[i - 1];

		if (i % 3 == 0 && min_op[i / 3] < min) {
			min = min_op[i / 3];
		}
		else if (i % 2 == 0 && min_op[i / 2] < min) {
			min = min_op[i / 2];
		}

		min_op.push_back(min + 1);
		i++;
	}

	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		int min_ops = min_op[n - 1];

		if (n % 3 == 0 && min_op[n / 3] < min_ops) {
			min_ops = min_op[n / 3];
			n /= 3;
		} 
		else if (n % 2 == 0 && min_op[n / 2] < min_ops) {
			min_ops = min_op[n / 2];
			n /= 2;
		}
		else
			n -= 1;
	}

	reverse(sequence.begin(), sequence.end());
	return sequence;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
