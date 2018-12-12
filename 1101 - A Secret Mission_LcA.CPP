/*
    accepted code
    problem: MST & LCA
    Md Hafizul Islam
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
const int mx=50002;
typedef long long ll;
typedef pair <int,int > ii;
typedef vector<int> vi;
typedef vector <ii> vii;
vector < pair<int ,ii> > edge;
vii g[mx];
struct tr{
    int node,cost;
}t[mx],s_t[mx][16];
int d[mx],f[mx],u,v,w;
bool vis[mx];
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
void create_mst(int n)
{
    int i,e=0,x,y;
    for(i=1;i<=n;i++) f[i]=i,g[i].clear();
    sort(edge.begin(),edge.end());
    for(i=0;i<edge.size()&&e<n-1;i++){
        w=edge[i].f;
        u=edge[i].s.f;
        v=edge[i].s.s;
        x=find(u);
        y=find(v);
        if(x!=y){
            f[x]=y;
            g[u].pb(ii(v,w));
            g[v].pb(ii(u,w));
            e++;
        }
    }
}
void dfs(int u,int depth)
{
    d[u]=depth;
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        ii v=g[u][i];
        if(!vis[v.f]){
            t[v.f].node=u;
            t[v.f].cost=v.s;
            dfs(v.f,depth+1);
        }
    }
}
int Build_Lca(int n)
{
    int i,j,k;
    memset(s_t,-1,sizeof s_t);
    for(i=1;i<=n;i++) {
        s_t[i][0].node=t[i].node;
        s_t[i][0].cost=t[i].cost;
    }
    for(j=1;(1<<j)<=n;j++){
        for(i=1;i<=n;i++){
            if(s_t[i][j-1].node!=-1){
                s_t[i][j].node=s_t[s_t[i][j-1].node][j-1].node;
                s_t[i][j].cost=max(s_t[i][j-1].cost,s_t[s_t[i][j-1].node][j-1].cost);
            }
        }
    }
    return 0;
}
int Lca_querry(int n,int p,int q)
{
    int tmp,log,i,ans=-1;
    if(d[p]<d[q]) tmp=p,p=q,q=tmp;
    log=1;
    while(1){
        int next=log+1;
        if((1<<next)>d[p]) break;
        log++;
    }
    for(i=log;i>=0;i--){
        if(d[p]-(1<<i)>=d[q]){
            ans=max(ans,s_t[p][i].cost);
            p=s_t[p][i].node;
        }
    }
    if(p==q) return ans;
    for(i=log;i>=0;i--){
        if(s_t[p][i].node!=-1 && s_t[p][i].node!=s_t[q][i].node){
            ans=max(ans,max(s_t[p][i].cost,s_t[q][i].cost));
            p=s_t[p][i].node;
            q=s_t[q][i].node;
        }
    }
    return max(ans,max(t[p].cost,t[q].cost));
}
int main()
{
    int n,m,i,j,q,ts,cs=1;
    scanf("%d",&ts);
    while(ts--){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            edge.pb(make_pair(w,ii(u,v)));
        }
        create_mst(n);
        memset(vis,false,sizeof vis);
        memset(t,0,sizeof t);
        t[1].node=1;
        dfs(1,0);
        Build_Lca(n);
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        for(i=0;i<q;i++){
            scanf("%d%d",&u,&v);
            printf("%d\n",Lca_querry(n,u,v));
        }
        edge.clear();
    }
    return 0;
}
