#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  long long max = 0;
  long long max_1 = 0;
  if(numbers[0] > numbers[1]) {
	max = numbers[0];
	max_1 = numbers[1];
  }
  else {
    max = numbers[1];
    max_1 = numbers[0];
  }

  for(int i = 2; i < n; i++)
  {
    if(numbers[i] > max) {
      max_1 = max;
      max = numbers[i];
    }
    else if(numbers[i] > max_1) {
      max_1 = numbers[i];
    }
  }
  result = max_1 * max;
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    } 

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}