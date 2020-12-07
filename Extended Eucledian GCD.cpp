/* Name : Md Johaer Plabon
   Dept. of Computer Science & Engineering, SEC. */


#include <bits/stdc++.h>
using namespace std;

int main() {
	// Extended Eucledian GCD 
	
	int q,r1,r2,r,s1=1,s2=0,s,t1=0,t2=1,t;
	// s= s1-q*s2 & t= t1-q*t2 where [s1,s2,t1,t2]=[1,0,0,1]
	
	cin>>r1>>r2; 
	while(r2){
		q=r1/r2;
		r=r1%r2;
		r1=r2;
		r2=r;
		if(r2){
			s= s1-q*s2;
			t= t1-q*t2;
			s1=s2;
			s2=s;
			t1=t2;
			t2=t;
		}
	}
	int gcd=r1;
	int x=s,y=t;// where r1*x + r2*y = g [g=gcd(r1,r2)]
	cout<<gcd<<" "<<x<<" "<<y<<endl;
	return 0;
}
