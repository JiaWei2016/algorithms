#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
	int n = w.size();
	vector< vector<int> > dp(n + 1, vector<int> (W + 1));
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= W; j++) {
			if (j == 0 || i == 0)
				dp[i][j] = 0;
			else if (w[i-1] > j)
				dp[i][j] = dp[i - 1][j];
			else
			{
				int max = dp[i - 1][j];
				if (dp[i - 1][j - w[i - 1]] + w[i - 1] > max)
					max = dp[i - 1][j - w[i - 1]] + w[i - 1];
				dp[i][j] = max;
			}
	}

	return dp[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
