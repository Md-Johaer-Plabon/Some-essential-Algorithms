#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll hs1 = 343;
const ll hs2 = 1003;
#define mod 1000000007
#define ff first
#define ss second

ll poww[1000005],poww1[1000005],inv[1000005],inv1[1000005];
ll finv,sinv;
string s,pat;
gp_hash_table<ll,pair<ll,ll> >mp,mp1;/// Works like unordered map but efficient then unordered map. Worst complexity(o(1)).
ll dp[1000005]={0},dp1[1000005]={0};

ll bigmod(ll x,ll y){if(y==0)return 1;if(y==1)return x;
if(y%2==0){ll res = bigmod(x,y/2)%mod;res*=res;res%=mod;return res;}
    else{return (bigmod(x,y-1)*x)%mod;}}

void texthash(){
for(int i=0;i<s.size();i++){dp[i+1]=(s[i]*poww[i+1]+dp[i])%mod,dp[i+1]=(dp[i+1]+mod)%mod;
dp1[i+1]=(s[i]*poww1[i+1]+dp1[i])%mod,dp1[i+1]=(dp1[i+1]+mod)%mod;}
}
pair<ll,ll> normalhash(){
    ll temp = 0,temp2 = 0;
    for(int i=0;i<pat.size();i++){temp+=(pat[i]*poww[i+1])%mod;temp2+=(pat[i]*poww1[i+1])%mod;
    temp=(temp+mod)%mod;temp2=(temp2+mod)%mod;}return {temp,temp2};
}
void gen(){
    finv=bigmod(hs1,mod-2)%mod;sinv = bigmod(hs2,mod-2)%mod;
    poww[1]=hs1,poww1[1]=hs2,poww[0]=poww1[0]=1;inv[1]=finv,inv1[1]=sinv,inv[0]=inv1[0]=1;
    for(ll i=2;i<=1000000;i++){poww[i] = poww[i-1]*hs1;poww1[i] = poww1[i-1]*hs2;
        inv[i] = inv[i-1]*finv;inv1[i] = inv1[i-1]*sinv;poww[i]%=mod, poww1[i]%=mod;inv[i]%=mod, inv1[i]%=mod;
    }
}
pair<ll,ll> rollinghash(int i,int len){
        ll flag=dp[i]-dp[i-len];flag=(flag+mod)%mod;flag=(flag*inv[i-len])%mod;
        ll flag1=dp1[i]-dp1[i-len];flag1=(flag1+mod)%mod;flag1=(flag1*inv1[i-len])%mod;
        return {flag,flag1};
}

int main (){
    gen();
    cin>>s>>pat;
    texthash();
    pair<ll,ll>p = normalhash();
    int coun = 0;
    int sz = pat.size();
    for(int i = sz;i<=s.size();i++){
       pair<ll,ll> temp = rollinghash(i,sz);
       if(temp.ff==p.ff && temp.ss==p.ss)coun++;
    }
    cout<<coun<<endl;

return 0;
}
