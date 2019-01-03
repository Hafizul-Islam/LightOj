/*  Accepted
    just dfs & tree & diameter
    Md Hafizul Islam
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef pair <int,int > ii;
typedef vector<int> vi;
typedef vector <ii> vii;
const int mx=3e5+5;
ll root;
ll ans=0,n;
vector <vii> g;
set <ii> p;
void dfs0(int u,int p,ll dist)
{
    if(dist>ans) ans=dist,root=u;
    for(int i=0;i<g[u].size();i++){
        ii v=g[u][i];
        if(v.ff !=p){
            dfs0(v.ff,u,dist+v.ss);
        }
    }
}
int main()
{
    int i,u,v,w,q,t,cases=1;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        g.assign(n+1,vii());
        for(i=1;i<n;i++){
            cin>>u>>v>>w;
            g[u].pb(ii(v,w));
            g[v].pb(ii(u,w));
        }
        dfs0(0,-1,0);
        dfs0(root,-1,0);
        printf("Case %d: %lld\n",cases++,ans);
    }
    return 0;
}
