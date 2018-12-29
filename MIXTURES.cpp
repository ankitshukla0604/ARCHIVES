//https://www.spoj.com/problems/MIXTURES/
//Based on Matrix Chain Multiplication 

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
#define MAX(a,b) (a>b)?a:b;
#define SIZE 100005

ll checked[105][105];
ll a[105];
ll pref[105];
ll check(ll x,ll y){
    if(checked[x][y]!=-1)
        return checked[x][y];
    if(x==y){          //if one element is left then no smoke from it
        checked[x][y]=0;
        return checked[x][y];
    }
    if(x+1==y)
        {                            //if two elements present then only one possible way
            checked[x][y]=a[x]*a[y];
            return checked[x][y];
        }
        ll min=1000000;
    for(ll k=x;k<=y-1;k++){   //placing parenthesis at different possible places
        ll smoke = check(x,k);
        smoke+=check(k+1,y);
        smoke+=((pref[k]-pref[x-1])%100)*((pref[y]-pref[k])%100);//smoke formed by the two partitioned mixtures
                                                                //since numbers are less then 100 sum%100 will not depend on parenthesis possition
        if(smoke<min)
            min = smoke;
    }
    checked[x][y]=min;
    return min;

}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;    
    while((cin>>n))
    {   for(ll i=0;i<=104;i++){
            for(ll j=0;j<=104;j++)
                checked[i][j]=-1;
        }
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        pref[1]=a[1];
        for(ll i=2;i<=n;i++){
            pref[i]=(pref[i-1]+a[i]);
        }
        
        cout<<check(1,n)<<endl;
        
    }
} 
