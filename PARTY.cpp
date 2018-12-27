//https://www.spoj.com/problems/PARTY/
//Knapsack Problem 
#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
#define inf std::numeric_limits<double>::infinity()
#define DECI(n) fixed<<showpoint<<setprecision(n)
#define MOD 1000000007LL
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define FORR(i,end,start) for(int i=end-1;i>=start;i--)
#define INPUT(arr,n) FOR(i,0,n)cin>>arr[i];
#define INPUT2d(arr,n,k) FOR(i,0,n)FOR(j,0,k)cin>>arr[i][j];
#define MAX(a,b) (a>=b)?a:b;
#define SIZE 100005
ll kp[105][505];
ll c[105];
ll f[105];
ll n,b,minj;
void solve(){
    for(ll i=0;i<=b;i++)
        kp[0][i]=0;

    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=b;j++){
            if(c[i]<=j){
                kp[i][j] = max(kp[i-1][j],f[i]+kp[i-1][j-c[i]]);
                

            }
            else
                kp[i][j] = kp[i-1][j];   
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ll n,b;
    cin>>b>>n;
    while(!(n==0&&b==0)){
        memset(kp,-1,sizeof(kp));
        for(ll i=1;i<=n;i++){
            cin>>c[i]>>f[i];
        }
        minj=500;
        solve();
        for(ll i=1;i<=n;i++){
        for(ll j=0;j<=b;j++){
           if(kp[i][j]==kp[n][b])
            minj = j>minj?minj:j;
        }
    }
        cout<<minj<<" "<<kp[n][b]<<endl;
        cin>>b>>n;
    }
   

  
}
