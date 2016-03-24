#include <iostream>
#include <string>
#include <vector> 

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
	int m = str1.length();
	int n = str2.length();
	vector< vector<int> > T(m + 1, vector<int>(n + 1));

	for (int k = 0; k < m + 1; k++){
		T[k][0] = k;
	}
	for (int l = 0; l < n + 1; l++){
		T[0][l] = l;
	}

	for (int i = 1; i < m + 1; i++)
		for (int j = 1; j < n + 1; j++) {

			if (str1.at(i - 1) == str2.at(j - 1)){
				T[i][j] = T[i - 1][j - 1];
			}
			else {
				int min = T[i - 1][j - 1];
				if (T[i - 1][j] < min)
					min = T[i - 1][j];
				if (T[i][j - 1] < min)
					min = T[i][j - 1];
				T[i][j] = min + 1;
			}
		}
	
	return T[m][n];
}

//int main() {
//  string str1;
//  string str2;
//  std::cin >> str1 >> str2;
//  std::cout << edit_distance(str1, str2) << std::endl;
//  return 0;
//}
