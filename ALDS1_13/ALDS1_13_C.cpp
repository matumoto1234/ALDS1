#include<iostream>
#include<vector>
using namespace std;

int board[4][4];
int ans=45;
const int dy[]={1,0,-1,0};
const int dx[]={0,1,0,-1};

// 位置を値に変換
int to_v(int y,int x){
  return y*4+x+1;
}

bool is_correct(){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      // 右下は除く
      if(i==3&&j==3) continue;
      if(board[i][j]!=to_v(i,j)){
        return false;
      }
    }
  }
  return true;
}

// マンハッタン距離
int manhattan(){
  int res=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(board[i][j]==0){
        continue;
      }
      int v=board[i][j]-1;
      res+=abs(v/4-i)+abs(v%4-j);
    }
  }
  return res;
}

bool range_check(int y,int x){
  return 0<=y&&y<4&&0<=x&&x<4;
}

void debug_output(){
  cerr<<"-------------------\n";
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cerr<<board[i][j]<<' ';
    }
    cerr<<endl;
  }
}

// depth, ヒューリスティック値, 前回動いた方向, y, x
void dfs(int d,int h,int prev,int y,int x){
  if(is_correct()){
    ans=min(ans,d);
    return;
  }
  if(d+h>ans) return;

  for(int dir=0;dir<4;dir++){ 
    int ny=y+dy[dir];
    int nx=x+dx[dir];

    // 範囲外
    if(range_check(ny,nx)==false) continue;
    // 行ったり来たりしない
    if(abs(prev-dir)==2) continue;

    swap(board[y][x],board[ny][nx]);
    dfs(d+1,manhattan(),dir,ny,nx);
    swap(board[y][x],board[ny][nx]);
  }
}

int main(){
  int sy,sx;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cin>>board[i][j];
      if(board[i][j]==0){
        sy=i;
        sx=j;
      }
    }
  }
  const int INF = 1001001001;
  dfs(0,manhattan(),INF,sy,sx);
  cout<<ans<<endl;
  return 0;
}