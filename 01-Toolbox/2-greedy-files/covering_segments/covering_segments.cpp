#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
};


vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	int min;

	while (segments.size() > 0)
	{
		min = segments[0].end;

		for (int j = 1; j < segments.size(); j++) {
			if (segments[j].end < min) {
				min = segments[j].end;
			}
		}

		points.push_back(min);

		//Get all the segments that are crossed by this min point
		for (int i = segments.size() - 1; i >= 0; i--) {
			if (segments[i].start <= min && segments[i].end >= min) {
				segments.erase(segments.begin() + i);
			}
		}
	}

	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
