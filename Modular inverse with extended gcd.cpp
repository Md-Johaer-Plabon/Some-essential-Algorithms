/* Name : Md Johaer Plabon
   Dept. of Computer Science & Engineering, SEC. */


#include <bits/stdc++.h>
using namespace std;
/* Condition For inverse modulo is, 
      (r1^-1)%r2 will exists if gcd(r1,r2)==1 */
int main() {
	
	int q,r1,r2,r,s1=1,s2=0,s;
	// t= t1-q*t2 where [s1,s2]=[1,0]
	
	cin>>r1>>r2; 
	int mod = r2;
	while(r2){
		q=r1/r2;
		r=r1%r2;
		r1=r2;
		r2=r;
		if(r2){
			s= s1-q*s2;
			s1=s2;
			s2=s;
		}
	}
	// (r1^-1)%r2 = s if s is negative then ans = s+mod
	if(s<0)s+=mod;
	cout<<s<<endl;
	return 0;
}
