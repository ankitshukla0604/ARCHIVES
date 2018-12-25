//https://www.spoj.com/problems/BUGLIFE/
//DFS
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
#define SIZE 100005
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
 
 vector <ll> adj[2001];
 ll visited[2001];
 ll colour[2001];
 //dfs
bool dfs(ll x,ll y){
    visited[x]=1;
    colour[x]=!colour[y];          //assigning colour opposit to the last vertex;
    for(ll i=0;i<adj[x].size();i++){
        if(!visited[adj[x][i]])
        {
            if(!dfs(adj[x][i],x)){
                return false;             
            }
        }
        else{
            if(colour[x]==colour[adj[x][i]])
                return false;      //checking if colour of visited child is opposite to the present one or not
        }
    }
    return true;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll c=1;
    while(t--){
        
        ll n,m;
        cin>>n>>m;
        memset(visited,0,sizeof(visited));
        memset(colour,-1,sizeof(colour));
        while(m--){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
 
        }
        ll i,j;
        colour[0]=1;
        for( i=1;i<2001;i++){
            if(!visited[i]){
                if(!dfs(i,0))
                    break;
            }
        }
        cout<<"Scenario #"<<c<<":"<<endl;
 
        if(i==2001)
            cout<<"No suspicious bugs found!"<<endl;
        else
            cout<<"Suspicious bugs found!"<<endl;
        //clearing the vectors
       for( i=0;i<2001;i++){
        for( j=adj[i].size()-1;j>=0;j--){
            adj[i].pop_back();
        }
       }
        c++;
    }
 
} 
