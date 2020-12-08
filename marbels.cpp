#include<bits/stdc++.h>
using namespace std;
int main (){
	int n;
	while(cin>>n && n){
		int q,r,s,s1=1,s2=0,t,t1=0,t2=1,c1,c2,a,b,g;
		cin>>c1>>a>>c2>>b;
		g=__gcd(a,b);
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
		int x,y;
		x=s*n/g;
		y=t*n/g;
		cout<<s<<" "<<t<<endl;
	}
	return 0;
}
