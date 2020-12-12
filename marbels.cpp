#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,r,s,s1=1,s2=0,t,t1=0,t2=1,c1,c2,a,b,g,x,y;
void ex_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
 if (b == 0) {
 x = 1, y = 0, d = a;
 return;
 }
 ll x1, y1;
 ex_gcd(b, a % b, d, x1, y1);
 x = y1;
 y = x1 - (a / b) * y1;
}
int main (){
	ll n;
	while(cin>>n && n){
		cin>>c1>>a>>c2>>b;
		ex_gcd(a,b,g,x,y);
		x*=n/g;
		y*=n/g;
		ll k1=ceil(-x*g/(double)b),k2=floor(y*g/(double)a);
		if(k1>k2||n%g){cout<<"failed"<<endl;continue;}
		ll x0,y0,x1,y1,ansx,ansy,cost;
		    x0= x + k1*b/g;
		    y0= y - k1*a/g;
		    x1= x + k2*b/g;
		    y1= y - k2*a/g;
		    cost= x0*c1+y0*c2;
		    if(cost<x1*c1+y1*c2)ansx=x0,ansy=y0;
		    else ansx=x1,ansy=y1;
		cout<<ansx<<" "<<ansy<<endl;
	}
	return 0;
}
