#include <bits/stdc++.h>
using namespace std;

bool nibun(vector<int> a,int key,int l,int r){
  while(r-l>=2){
    int mid=(l+r)/2;
    if(a[mid]<=key){
      l=mid;
    }else{
      r=mid;
    }
  }
  return a[l]==key||a[r]==key;
}

int main() {
  int n;
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  int q;
  int ans = 0;
  cin >> q;
  vector<int> T(q);
  for (int i = 0; i < q; i++) {
    cin >> T[i];
    if(nibun(S,T[i],0,n-1)){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}