/*
    accepted code
    problem: Mo's Algorithm
    Md Hafizul Islam
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mx 100009
#define N 50006
#define block 555
#define A 1111111
typedef long long ll;
typedef pair <int,int > ii;
typedef vector<int> vi;
typedef vector <ii> vii;
int cnt=0,vt=1;
int f[mx],a[mx],ans[N];
struct query{
    int index,l,r;
}q[N];
bool cmp(query a,query b){
    if((a.l/block)==(b.l/block)) return a.r<b.r;
    return (a.l/block)<(b.l/block);
}
void addd(int x){
    ++f[a[x]];
    if(f[a[x]]==1) cnt++;
}
void remov(int x){
    --f[a[x]];
    if(f[a[x]]==0) cnt--;
}
int main()
{
    int t,n,m,i;

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        cnt=0;
        memset(f,0,sizeof f);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<m;i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            --q[i].l,--q[i].r,q[i].index=i;
        }
        sort(q,q+m,cmp);

        printf("Case %d:\n",vt++);

        int l=0,r=0;
        for(i=0;i<m;i++){
            while(l<q[i].l){
                remov(l);
                ++l;
            }
            while(l>q[i].l){
                l--;
                addd(l);
            }
            while(r<=q[i].r){
                addd(r);
                r++;
            }
            while(r>q[i].r+1){
                remov(r-1);
                --r;
            }
            ans[q[i].index]=cnt;
        }
        for(i=0;i<m;i++) printf("%d\n",ans[i]);
    }

    return 0;
}




