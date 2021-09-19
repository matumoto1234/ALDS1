#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int dy[]={0,1,0,-1};
const int dx[]={1,0,-1,0};
int board[3][3];

int to_v(int y,int x){
  return y*3+x+1;
}

bool is_correct(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i][j]==0){
        continue;
      }
      if(board[i][j]!=to_v(i,j)){
        return false;
      }
    }
  }
  return true;
}

bool range_check(int y,int x){
  return 0<=y&&y<3&&0<=x&&x<3;
}

bool dfs(int depth,int& y,int& x,int prev){
  if(depth==0){
    return is_correct();
  }

  for(int i=0;i<4;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(abs(prev-i)==2){
      continue;
    }

    if(range_check(ny,nx)==false){
      continue;
    }

    swap(board[ny][nx],board[y][x]);
    if(dfs(depth-1,ny,nx,i)){
      return true;
    }
    swap(board[ny][nx],board[y][x]);
  }
  return false;
}

int main(){
  int depth=0;
  int sy,sx;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>board[i][j];
      if(board[i][j]==0){
        sy=i;
        sx=j;
      }
    }
  }
  while(!dfs(depth,sy,sx,100100100)){
    depth++;
  }
  cout<<depth<<endl;
  return 0;
}