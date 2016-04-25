#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::swap;

struct Worker_EndTimes {
	Worker_EndTimes(int w, long long et) :
		worker(w), 
		end_time(et) 
	{}

	Worker_EndTimes() {}

	int worker;
	long long end_time;
};

/*
This class implements a min heap for Worker_EndTimes elements.
The min (top of the heap) is the element with the lowest end_time value.
If two elements have the same end_time value, the min is the one with the
lowest worker value.
*/
class MinHeap {
private:
	vector<Worker_EndTimes> end_times_;
	unsigned int _count = 0;

	int Parent(int i) {
		if (i > 0)
			return (int)floor(((double)i - 1) / 2);
		else
			return 0;
	}

	int LeftChild(int i) {
		return 2 * i + 1;
	}

	int RightChild(int i) {
		return 2 * i + 2;
	}

	//SiftUp moves up elements with lower end_time or lower worker for elements of the
	//same end_time
	void SiftUp(int i) {
		long long p_end_t, c_end_t;
		int p_worker, c_worker;
		p_end_t = end_times_[Parent(i)].end_time;
		p_worker = end_times_[Parent(i)].worker;
		c_end_t = end_times_[i].end_time;
		c_worker = end_times_[i].worker;

		while (i >= 0 && (p_end_t > c_end_t) || ((p_end_t == c_end_t) && (p_worker > c_worker))) {
			swap(end_times_[Parent(i)], end_times_[i]);
			i = Parent(i);
			p_end_t = end_times_[Parent(i)].end_time;
			p_worker = end_times_[Parent(i)].worker;
			c_end_t = end_times_[i].end_time;
			c_worker = end_times_[i].worker;
		}
	}

	//SiftUp moves down elements with larger end_time or larger worker for elements with the
	//same end_time
	void SiftDown(int i){
		int minIndex = i;
		unsigned int l = LeftChild(i);
		if (l < _count){
			if (
				(end_times_[l].end_time < end_times_[minIndex].end_time ||
				(end_times_[l].end_time == end_times_[minIndex].end_time &&
				end_times_[l].worker < end_times_[minIndex].worker)
				)) {
				minIndex = l;
			}
		}
		unsigned int r = RightChild(i);
		if (r < _count){
			if (
				(end_times_[r].end_time < end_times_[minIndex].end_time ||
				(end_times_[r].end_time == end_times_[minIndex].end_time &&
				end_times_[r].worker < end_times_[minIndex].worker)
				)) {
				minIndex = r;
			}
		}
		if (i != minIndex){
			swap(end_times_[i], end_times_[minIndex]);
			SiftDown(minIndex);
		}
	}

public:
	void Insert(Worker_EndTimes p) {
		if (_count < end_times_.size()) {
			_count++;
			end_times_[_count - 1] = p;
			SiftUp(_count - 1);
		}
	}

	Worker_EndTimes ExtractMin() {
		Worker_EndTimes result = end_times_[0];
		end_times_[0] = end_times_[_count - 1];
		_count--;
		SiftDown(0);
		return result;
	}

	MinHeap(int size) {
		end_times_.resize(size);
	}
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (unsigned int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
	for (int i = 0; i < m; ++i)
		cin >> jobs_[i];
  }

  /* We assign jobs to the workers by extracting the worker with the minimum end_time from the heap of 
  end_times (worker that will be free next) and assigning it to the next available job.
  After a job has been assigned, we also insert it to the MinHeap with the 
  end_time expected. */
  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
	MinHeap* p_queue = new MinHeap(num_workers_);

	//Initialize the Worker_EndTimes heap to the max
	//between the number of jobs or the number of
	//workers available
	int max_ini = num_workers_;
	if (jobs_.size() < num_workers_)
		max_ini = jobs_.size();

	for (int w = 0; w < max_ini; w++){
			p_queue->Insert(Worker_EndTimes(w, jobs_[w]));
			assigned_workers_[w] = w;
			start_times_[w] = 0;
	}

	for (unsigned int j = max_ini; j < jobs_.size(); j++) {
		Worker_EndTimes min = p_queue->ExtractMin();
		assigned_workers_[j] = min.worker;
		start_times_[j] = min.end_time;
		p_queue->Insert(Worker_EndTimes(min.worker, min.end_time + jobs_[j]));
	}
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
