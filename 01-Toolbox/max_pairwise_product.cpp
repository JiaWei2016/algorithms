#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  long long max = numbers[0];
  long long max_1 = 0;
  for(int i = 1; i < n; i++)
  {
    if(numbers[i] > max)
    {
      max_1 = max;
      max = numbers[i]; 
    }
  }


  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * numbers[j] > result) {
        result = ((long long)numbers[i]) * numbers[j];
      }
    }
  }
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