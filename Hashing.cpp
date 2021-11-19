#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007 

ll bigmod(ll x, ll y){

    ll res = 1; 
    x%=mod; 
    if(x==0)return 0;
    while (y){
        if (y&1)
            res*=x,res%=mod;
        y >>= 1;
        x*=x; 
        x%=mod;
    }
    return res;
}



int main() {
	string s,ss; 
	cin>>s>>ss; 
	ll hash[3]={0},temp[3]={0},flag=0; 
	ll c1=347,c2=1003; 
	ll invc1 = bigmod(c1,mod-2); 
	invc1+=mod,invc1%=mod;
	ll invc2 = bigmod(c2,mod-2); 
	invc2+=mod,invc2%=mod;
	for(int i=0;i<ss.size();i++) {
	   hash[0] += ((ll)(ss[i]-'a'+1)*bigmod(c1,(ll)i))%mod; 
	   hash[1] += ((ll)(ss[i]-'a'+1)*bigmod(c2,(ll)i))%mod; 
	}
	
	for(int i=0;i<ss.size();i++) {
	   temp[0] += ((ll)(s[i]-'a'+1)*bigmod(c1,(ll)i))%mod; 
	   temp[1] += ((ll)(s[i]-'a'+1)*bigmod(c2,(ll)i))%mod; 
	   
	} 
	
	if(temp[0]==hash[0]&&temp[1]==hash[1])flag=1;
	cout<<hash[0]<<" "<<hash[1]<<" "<<temp[0]<<" "<<temp[1]<<endl;
	int sz = ss.size()-1; 
	
	for(int i=ss.size(),j=0;i<s.size();i++,j++) { 
	   temp[0]-=(s[j]-'a'+1),temp[0]=(temp[0]*invc1)%mod; 
	   temp[0] += ((ll)(s[i]-'a'+1)*bigmod(c1,(ll)sz))%mod; 
	   temp[1]-=(s[j]-'a'+1),temp[1]=(temp[1]*invc2)%mod; 
	   temp[1] += ((ll)(s[i]-'a'+1)*bigmod(c2,(ll)sz))%mod; 
	   if(temp[0]==hash[0]&&temp[1]==hash[1])flag=1; 
	   cout<<hash[0]<<" "<<hash[1]<<" "<<temp[0]<<" "<<temp[1]<<endl;
	} 
	
	if(flag)cout<<"YES"<<endl; 
	else cout<<"NO"<<endl;
	return 0;
}
