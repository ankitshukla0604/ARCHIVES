//https://www.spoj.com/problems/BITMAP/
//MULTISOURCE BFS AND DJISKITRA'S ALGO
#include <bits/stdc++.h>
using namespace std;
#define  ll long long int

char a[200][200];
ll dist[200][200];
ll n,m;
set < pair<ll,pair<ll,ll>>> s; //Set act as priority queue
void bfs(){
    set < pair<ll,pair<ll,ll>>>:: iterator itr,itr2;
    pair<ll,pair<ll,ll>> p;
    
    while(!s.empty()){
        itr2 = s.begin();
    p = *itr2;
    ll x = p.second.first;
    ll y = p.second.second;
   // cout<<x<<" "<<y<<endl;
    if(x>n||y>m||x<=0||y<=0)
        {   
        //cout<<x<<" "<<y<<endl;
            s.erase(itr2);
            continue;     
        }
    else{
     //traversing in possible adjacent nodes
    if(dist[x][y]+1<dist[x][y+1])
    {
       // cout<<x<<" "<<y<<endl;
        //yahn aa rha h fault
        itr = s.find({dist[x][y+1],{x,y+1}});
        if(itr!=s.end())
        s.erase(itr);
        dist[x][y+1]=dist[x][y]+1;
        //cout<<dist[x][y+1]<<endl;
        s.insert({dist[x][y+1],{x,y+1}});
    }

    if(dist[x][y]+1<dist[x][y-1])
    {
        itr = s.find({dist[x][y-1],{x,y-1}});
        if(itr!=s.end())
        s.erase(itr);
        dist[x][y-1]=dist[x][y]+1;
        s.insert({dist[x][y-1],{x,y-1}});
    }

    if(dist[x][y]+1<dist[x+1][y])
    {
        itr = s.find({dist[x+1][y],{x+1,y}});
        if(itr!=s.end())
        s.erase(itr);
        dist[x+1][y]=dist[x][y]+1;
        s.insert({dist[x+1][y],{x+1,y}});
    }


    if(dist[x][y]+1<dist[x-1][y])
    {
        itr = s.find({dist[x-1][y],{x-1,y}});
        if(itr!=s.end())
        s.erase(itr);
        dist[x-1][y]=dist[x][y]+1;
        s.insert({dist[x-1][y],{x-1,y}});
    }
    s.erase(itr2);
}
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for (ll i = 0; i <200; i++)
    {
        for (ll j=0;j<200;j++)
        {
            dist[i][j]=100000;
        }
        
    }
        for(ll i=1;i<=n;i++){
            for( ll j=1;j<=m;j++){
                cin>>a[i][j];
            if(a[i][j]=='1')
                {dist[i][j]=0;
                    s.insert({0,{i,j}});
                }

                   // cout<<"inserted"<<endl;
        }
    }
   
    bfs();
    for (ll i = 1; i <= n; i++)
    {
        for (ll j=1;j<=m;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
} 
}
