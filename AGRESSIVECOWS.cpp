//solution for AGRESSIVECOWS
//https://www.spoj.com/problems/AGGRCOW/
//by Ayush Shukla

#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
#define inf std::numeric_limits<double>::infinity()
#define DECI(n) fixed<<showpoint<<setprecision(n)
#define MOD 1000000007LL

bool checkdis(ll dis,ll a[],ll n,ll c){
ll last=0,cnt=1;
for(ll i=1;i<n;i++){
    if(a[i]-a[last]>=dis){
        last=i;
        cnt++;
    }
    if(cnt==c)
        return true;
}
 return false;
}
main(){
    int t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n); //sort the points in ascending order
        ll max=a[n-1]-a[0],min=0; //mark rhe max difference possible and min distance possible
        int cnt=0;
        while(max>min){
            ll mid=(max+min)/2+1;
            if(checkdis(mid,a,n,c)){ //check if it is possible to have min difference greater than or equal to mid   
                min=mid;
            }
            else{
                max=mid-1;
            }
            
            }
        cout<<max<<endl;
    }

return 0;
    
}
