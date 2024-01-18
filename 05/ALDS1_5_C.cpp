#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

struct Point{
  long double x,y;
  Point(){}
  Point(long double x,long double y):x(x),y(y){}
};
ostream& operator<<(ostream &os,Point p) { os<<p.x<<' '<<p.y; return os;}

Point internal_division(Point a,Point b,long double m,long double n){
  return Point((a.x*n+b.x*m)/(m+n),(a.y*n+b.y*m)/(m+n));
}

Point rotL(Point origin,Point p,long double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

int n;
const long double rad60=60.0*M_PI/180.0;
void koch(int depth,Point l,Point r){
  if(depth==n) return;

  Point s=internal_division(l,r,1,2);
  Point t=internal_division(l,r,2,1);
  Point u=rotL(s,t,rad60);

  koch(depth+1,l,s);
  cout<<s<<'\n';
  koch(depth+1,s,u);
  cout<<u<<'\n';
  koch(depth+1,u,t);
  cout<<t<<'\n';
  koch(depth+1,t,r);
}

int main() {
  cout<<fixed<<setprecision(5);
  cin>>n;
  Point left(0,0);
  Point right(100,0);

  cout<<left<<'\n';
  koch(0,left,right);
  cout<<right<<'\n';
}