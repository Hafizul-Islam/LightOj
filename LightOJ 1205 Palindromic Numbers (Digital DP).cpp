/*  Author: Md Hafizul Islam
    Accepted
    Digit dp
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
int  digit[20];
const int mx=1e6;
const int M=1e9+7;
ll dp[20][20][2],temp[20],a,b;
ll cnt_palin(int start,int cur,int state,int restrict)
{
    if(cur<0) return state;
    if(!restrict && dp[start][cur][state]!=-1) return dp[start][cur][state];
    ll ans=0;
    int k=(restrict)?digit[cur]:9;
    for(int i=0;i<=k;i++){
        int newrestrict=(digit[cur]==i)?restrict:0;
        temp[cur]=i; /*Current Digit*/
        if(start==cur && i==0) /*front digit zero*/
            ans+=cnt_palin(start-1,cur-1,state,newrestrict);
        else if(state && cur<(start+1)/2) /*Consist one palindrome */
            ans+=cnt_palin(start,cur-1,temp[start-cur]==i,newrestrict);
        else /*Now no palindrome consist*/
            ans+=cnt_palin(start,cur-1,state,newrestrict);
    }
    if(!restrict) dp[start][cur][state]=ans;
    return ans;
}
ll get_digit(ll n)
{
    int i=0;
    while(n){
        digit[i++]=(n%10);
        n/=10;
    }
    memset(dp,-1,sizeof dp);
    return cnt_palin(i-1,i-1,1,1);
}
int main()
{
    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<b) swap(a,b);
      //  cout<<a<<" "<<b;
        printf("Case %d: %lld\n",cs++,get_digit(a)-get_digit(b-1));
    }

    return 0;
}
