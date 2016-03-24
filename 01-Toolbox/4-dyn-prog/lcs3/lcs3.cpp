#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	int m = a.size();
	int n = b.size();
	int l = c.size();

	vector< vector< vector<int> > > T(m + 1, vector< vector<int> >(n + 1, vector<int> (l + 1)));
	for (int i = 0; i < m + 1; i++)
		T[i][0][0] = 0;
	for (int j = 0; j < n + 1; j++)
		T[0][j][0] = 0;
	for (int k = 0; k < l + 1; k++)
		T[0][0][k] = 0;

	for (int r = 1; r < m + 1; r++)
		for (int s = 1; s < n + 1; s++)
			for (int t = 1; t < l + 1; t++) {
				if (a[r - 1] == b[s - 1] && a[r - 1] == c[t - 1]){
					T[r][s][t] = T[r - 1][s - 1][t - 1] + 1;
				}
				else {
					int max = T[r - 1][s][t];
					if (T[r][s - 1][t] > max) max = T[r][s - 1][t];
					if (T[r][s][t - 1] > max) max = T[r][s][t - 1];
					if (T[r - 1][s - 1][t] > max) max = T[r - 1][s - 1][t];
					if (T[r][s - 1][t - 1] > max) max = T[r][s - 1][t - 1];
					if (T[r - 1][s][t - 1] > max) max = T[r - 1][s][t - 1];
					if (T[r - 1][s - 1][t - 1] > max) max = T[r - 1][s - 1][t - 1];

					T[r][s][t] = max;
				}

			}
  return T[m][n][l];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
