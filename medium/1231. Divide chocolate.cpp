#include <bits/stdc++.h>
using namespace std;

int f(int mid, vector<int>&sweet, int n){
  int pieces = 0;
  int i=0, sum = 0;
  while(i<n){
    sum += sweet[i];
    if(sum >= mid){
      pieces++;
      sum = 0;
    }
    i++;
  }
  return pieces;
}

int main() 
{
  int k;
  int n;
  cin>>n>>k;
  vector<int>sweet(n);
  int sum = 0;
  for(int i=0; i<n; i++){
    cin>>sweet[i];
    sum += sweet[i];
  }
  // we have to maximise minimum sweetness 
  int left = 1, right = sum;
  int ans = right;
  while(left<=right){
    int mid = (left+right)/2;
    if(f(mid, sweet, n)>=k+1){
      ans = mid;
      left = mid+1;
    }
    else{
      right = mid-1; 
    }
  }
  cout<<ans;
}
