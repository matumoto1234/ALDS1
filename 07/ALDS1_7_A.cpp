#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ids, parents, depths;
vector<string> types;
vector<vector<int>> children;
vector<string> answers;

ostream &operator<<(ostream &os, const vector<int> &vs) {
  for (size_t i = 0; i < vs.size(); i++) {
    if (i) os << ", ";
    os << vs[i];
  }
  return os;
}

int get_root(int id) {
  if (parents[id] == -1) return id;
  return get_root(parents[id]);
}

void dfs(int id, int dep) {
  depths[id] = dep;

  for (auto child: children[id]) {
    parents[child] = id;
    dfs(child, dep + 1);
  }
}

void set_types() {
  for (int i = 0; i < n; i++) {
    if (parents[i] == -1) {
      types[i] = "root";
      continue;
    }

    if (children[i].empty()) {
      types[i] = "leaf";
      continue;
    }

    types[i] = "internal node";
  }
}

void set_node_info(int i) {
  int id = ids[i];
  stringstream ss;
  ss << "node " << id << ": ";
  ss << "parent = " << parents[id] << ", ";
  ss << "depth = " << depths[id] << ", ";
  ss << types[id] << ", ";
  ss << "[" << children[id] << "]";
  answers[id] = ss.str();
}

int main() {
  cin >> n;

  ids.resize(n);
  parents.assign(n, -1);
  depths.resize(n);
  types.resize(n);
  children.resize(n);
  answers.resize(n);

  for (int i = 0; i < n; i++) {
    int id, k;
    cin >> id >> k;

    ids[i] = id;

    vector<int> cs(k);
    for (int &c: cs) {
      cin >> c;
      parents[c] = id;
    }

    children[id] = cs;
  }

  dfs(get_root(0), 0);

  set_types();

  for (int i = 0; i < n; i++) {
    set_node_info(i);
  }

  for (int i = 0; i < n; i++) {
    cout << answers[i] << endl;
  }
}