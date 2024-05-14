#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=100002;
int dp[N];

// Memoization
// Time complexity..O(K^2*N)..recursion call (N*K) and look k times for every call
// Space complexity..O(N)..max depth of recursion tree
int frog(int i,int h[],int n,int dp[],int k){
	if(i==n)
		return 0;
	if(i>n-k)
		return abs(h[n]-h[i]);

	if(dp[i]!=-1)
		return dp[i];
	int re=frog(i+1,h,n,dp,k)+abs(h[i+1]-h[i]);
	for(int l=2;l<=k;l++){
		re=min(re,frog(i+l,h,n,dp,k)+abs(h[i+l]-h[i]));
	}

	return dp[i]=re;
}

int main(){
	int n,k;
	cin>>n>>k;
	int h[n+1];
	// min energy from ith index to last index
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>h[i];
  // Memoization
	int ans=frog(1,h,n,dp,k);
	cout<<ans<<"\n";
	return 0;
}
