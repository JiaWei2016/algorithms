#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double sum = 0.0;
  while (capacity > 0 && weights.size() > 0)
  {
	  int j = 0;
	  for (int i = 1; i < weights.size(); i++) {
		  if((double)values[i]/weights[i] > (double)values[j]/weights[j]){
			  j = i;
		  }
	  }

	  if (capacity >= weights[j]) {
		  capacity -= weights[j];
		  sum += values[j];
	  }
	  else {
		  double fraction = (double)capacity / weights[j];
		  capacity -= fraction * weights[j];
		  sum += fraction * values[j];
	  }

	  weights.erase(weights.begin() + j);
	  values.erase(values.begin() + j);
  }

  return sum;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  //std::cout.precision(10);
  std::cout << std::fixed << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}

