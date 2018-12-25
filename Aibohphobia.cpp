//https://www.spoj.com/problems/AIBOHP/
//DYNAMIC PROGRAMMING
#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
#define inf std::numeric_limits<double>::infinity()
#define DECI(n) fixed<<showpoint<<setprecision(n)
#define MOD 1000007LL
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define FORR(i,end,start) for(int i=end-1;i>=start;i--)
#define INPUT(arr,n) FOR(i,0,n)cin>>arr[i];
#define INPUT2d(arr,n,k) FOR(i,0,n)FOR(j,0,k)cin>>arr[i][j];
#define SIZE 100005
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
 
ll checked[6500][6500];
string s;
ll k;
ll check(ll x, ll y){
    if(checked[x][y]!=-1){
        return checked[x][y];
    }
    if(x>=y){
        return 0;
    }
    ll insx,insy,insn=1000000000;
    ll min;
    insx = 1+check(x,y-1);
    insy = 1+check(x+1,y);
    min = (insx>insy)?insy:insx;
    if(s[x]==s[y])insn = check(x+1,y-1);
    min = (min>insn)?insn:min;
    checked[x][y]=min;
 
    return min;
 
 
 
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
        cin>>t;
      while(t--){
        cin>>s;
         k = s.length();
        memset(checked,-1,sizeof(checked));
        cout<<check(0,k-1)<<endl;;
      }  
    
} 
