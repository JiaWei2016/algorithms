#include <iostream>
#include <vector>

using std::vector;
using std::swap;

struct Ix
{
	int low;
	int high;
};

Ix partition2(vector<int> &a, int l, int r) {
  Ix result;
  result.low = l;
  result.high = r;

  int x = a[l];
  int i = l;
  while ((result.low < result.high) && i <= r){
	  if (a[i] > x) {
		  swap(a[i], a[result.high]);
		  result.high--;
	  }
	  else if (a[i] < x) {
		  swap(a[i], a[result.low]);
		  result.low++;
	  }
	  else {
		  i++;
	  }
  }

  return result;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  Ix result = partition2(a, l, r);

  randomized_quick_sort(a, l, result.low - 1);
  randomized_quick_sort(a, result.high + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
