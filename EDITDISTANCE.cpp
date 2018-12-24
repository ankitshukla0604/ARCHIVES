//https://www.spoj.com/problems/EDIST/
//Dynamic Programming

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
 
ll check[2005][2005];
string a,b;
ll lena,lenb;
ll checked(ll x,ll y){
    if(check[x][y]!=-1){
        return check[x][y];
    }
    
    if(x>=lenb&&y>=lena){
 
        check[x][y]=0;
        return 0;
    }
    else if(y>=lena){
        check[x][y]=1+checked(x+1,y);
        return check[x][y]; 
    }
    else if(x>=lenb){
 
        check[x][y]=1+checked(x,y+1);
        return check[x][y];
    }
 
    ll rep,del,ins;
    if(a[y]!=b[x]){
     rep = 1+checked(x+1,y+1);
     del = 1+checked(x+1,y);
     ins = 1+checked(x,y+1);
     if (rep<del)
    {
        if(rep<ins)
           { check[x][y]=rep;return rep;}
        else
            {check[x][y]=ins;return ins;}
    }
    else
    {
        if(del<ins)
            {check[x][y]=del;return del;}
        else
            {check[x][y]=ins;return ins;}
    }
        }
    if(a[y]==b[x])
        {  
          rep = checked(x+1,y+1);
     del = 1+checked(x+1,y);
     ins = 1+checked(x,y+1);
     if (rep<del)
    {
        if(rep<ins)
           { check[x][y]=rep;return rep;}
        else
            {check[x][y]=ins;return ins;}
    }
    else
    {
        if(del<ins)
            {check[x][y]=del;return del;}
        else
            {check[x][y]=ins;return ins;}
    }
        
        }
    
 
    
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>a;
        cin>>b;
        if(a.length()==b.length()){
            //equal string
            ll i;
 
            lena=a.length();
            lenb=lena;
            for( i=0;i<lena;i++){
                if(a[i]!=b[i])
                    break;
            }
            if(i==lena)
                cout<<0<<endl;
            else{
 
            memset(check,-1,sizeof(check));
            ll min = checked(0,0);
            cout<<min<<endl;
 
            }
        }
        else{
 
            lena=a.length();
            lenb=b.length();
            memset(check,-1,sizeof(check));
            ll min = checked(0,0);
 
          cout<<min<<endl;
        }
    }
} 
