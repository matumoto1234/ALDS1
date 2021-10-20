#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input() {
  vector<vector<int>> board(4, vector<int>(4));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> board[i][j];
    }
  }
  return board;
}

pair<int, int> start_pos(const vector<vector<int>> &board) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == 0) { return pair(i, j); }
    }
  }
  return pair(-1, -1);
}

vector<vector<int>> correct() {
  vector<vector<int>> board(4, vector<int>(4));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      board[i][j] = 4 * i + (j + 1);
    }
  }
  board[3][3] = 0;
  return board;
}

int manhattan(const vector<vector<int>> &board) {
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == 0) continue;
      int v = board[i][j] - 1;
      sum += abs(i - v / 4) + abs(j - v % 4);
    }
  }
  return sum;
}

int main() {
  vector<vector<int>> board = input();

  auto [sy, sx] = start_pos(board);

  vector<vector<int>> cor = correct();

  constexpr int dy[] = { 0, 1, 0, -1 };
  constexpr int dx[] = { 1, 0, -1, 0 };

  int ans = 45;

  auto dfs = [&](auto &&f, int y, int x, int dep, int dist, int pre) -> void {
    if (board == cor) {
      ans = min(ans, dep);
      return;
    }

    if (dep + dist > ans) return;

    for (int i = 0; i < 4; i++) {
      if (abs(i - pre) == 2) continue;

      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 or ny >= 4 or nx < 0 or nx >= 4) continue;

      swap(board[y][x], board[ny][nx]);

      f(f, ny, nx, dep + 1, manhattan(board), i);

      swap(board[y][x], board[ny][nx]);
    }
  };

  dfs(dfs, sy, sx, 0, manhattan(board), -10101);

  cout << ans << endl;
}