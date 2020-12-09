#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main (){
	ll n;
	while(cin>>n && n){
		ll q,r,s,s1=1,s2=0,t,t1=0,t2=1,c1,c2,a,b,g;
		cin>>c1>>a>>c2>>b;
		g=__gcd(a,b);
		ll a1=a,b1=b;
		if(n%g){cout<<"failed"<<endl;continue;}
		while(b){
		   q=a/b;
		   r=a%b;
		   a=b;
		   b=r;
		   if(b){
		   	s=s1-q*s2;
		   	t=t1-q*t2;
		   	t1=t2;
		   	t2=t;
		   	s1=s2;
		   	s2=s;
		   }
		}
		ll x,y;
		x=s*n/g;
		y=t*n/g;
		ll k1=abs(x)/b1,k2=abs(y)/a1;
		if(k1>k2)swap(k1,k2);
		ll x0,y0,ansx,ansy,cost=900000000000000;
		for(ll i=k1;i<=k2;i++){
		    x0= x + i*b1/g;
		    y0= y - i*a1/g;
		    if(x0>0&&y0>0){
		      if(cost>x0*c1+y0*c2)
		      cost=x0*c1+y0*c2,ansx=x0,ansy=y0;
		    }
		}
		cout<<ansx<<" "<<ansy<<endl;
	}
	return 0;
}
