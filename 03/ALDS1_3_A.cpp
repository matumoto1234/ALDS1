#include <bits/stdc++.h>
using namespace std;

namespace my {
  template <typename T>
  class stack {
    vector<T> data;

  public:
    stack(): data(0) {}

    void push(T value) { data.push_back(value); }

    T top() { return data.back(); }

    void pop() { return data.pop_back(); }

    bool empty() { return data.empty(); }

    size_t size() { return data.size(); }
  };
} // namespace my


bool solve(my::stack<string> &vals) {
  string s;
  cin >> s;

  if (cin.eof()) return false;

  if (s == "+") {
    string val1 = vals.top();
    vals.pop();
    string val2 = vals.top();
    vals.pop();
    vals.push(to_string(stoll(val1) + stoll(val2)));
    return true;
  }

  if (s == "-") {
    string val1 = vals.top();
    vals.pop();
    string val2 = vals.top();
    vals.pop();
    vals.push(to_string(stoll(val2) - stoll(val1)));
    return true;
  }

  if (s == "*") {
    string val1 = vals.top();
    vals.pop();
    string val2 = vals.top();
    vals.pop();
    vals.push(to_string(stoll(val1) * stoll(val2)));
    return true;
  }

  vals.push(s);

  return true;
}

int main() {
  my::stack<string> vals;
  while (solve(vals)) {}
  cout << vals.top() << endl;
}