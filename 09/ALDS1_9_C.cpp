#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 0-indexed , Max-heap */
template <typename T> class priority_queue {
private:
  vector<T> v;

  void makeMaxHeapBack(int idx) {
    if (idx <= 0) {
      return;
    }
    int p = (idx - 1) / 2;
    int pl = p * 2 + 1;
    int pr = p * 2 + 2;
    if (v[p] >= v[idx]) {
      return;
    }
    if (pl < v.size() && pl != idx && v[pl] >= v[idx]) {
      return;
    }
    if (pr < v.size() && pr != idx && v[pr] >= v[idx]) {
      return;
    }
    swap(v[p], v[idx]);
    makeMaxHeapBack(p);
  }

  void makeMaxHeap(int idx) {
    if (idx >= v.size()) {
      return;
    }
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;
    int largest = idx;
    if (l < v.size() && v[largest] < v[l]) {
      largest = l;
    }
    if (r < v.size() && v[largest] < v[r]) {
      largest = r;
    }
    if (idx != largest) {
      swap(v[idx], v[largest]);
      makeMaxHeap(largest);
    }
  }

public:
  priority_queue() {}

  void push(T key) {
    v.emplace_back(key);
    int idx = v.size() - 1;
    makeMaxHeapBack(idx);
  }

  void pop() {
    v[0] = v[v.size() - 1];
    v.pop_back();
    makeMaxHeap(0);
  }

  T top() { return v[0]; }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  priority_queue<int> Q;
  while (1) {
    string s;
    cin >> s;
    if (s == "end")
      break;
    if (s == "extract") {
      cout << Q.top() << '\n';
      Q.pop();
      continue;
    }

    int x;
    cin >> x;
    Q.push(x);
  }
  return 0;
}