#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

vector<vector<char>> board(8,vector<char>(8,'.'));
vector<bool> dpos(2*8-1,false),dneg(2*8-1,false);
vector<bool> row(8,false),col(8,false);

set<int> s;

void putQueen(int y,int x){
  board[y][x]='Q';
  row[y]=true;
  col[x]=true;
  dpos[y+7-x]=true;
  dneg[y+x]=true;
}

void rmQueen(int y,int x){
  board[y][x]='.';
  row[y]=false;
  col[x]=false;
  dpos[y+7-x]=false;
  dneg[y+x]=false;
}

bool isEmpty(int y,int x){
  bool res=row[y]||col[x]||dpos[y+7-x]||dneg[y+x];
  return !res;
}

void outputBoard(){
  range(i,0,8){
    range(j,0,8){
      cout<<board[i][j];
    }
    cout<<'\n';
  }
}

bool dfs(int depth){
  if(depth==8){
    outputBoard();
    return true;
  }

  if(s.find(depth)!=s.end()) return dfs(depth+1);

  range(j,0,8){
    if(!isEmpty(depth,j)) continue;

    bool res;
    putQueen(depth,j);
    res=dfs(depth+1);
    rmQueen(depth,j);

    if(res) return true;
  }
  return false;
}

int main() {
  int n;
  cin>>n;
  range(i,0,n){
    int y,x;
    cin>>y>>x;
    s.insert(y);
    putQueen(y,x);
  }
  dfs(0);
}