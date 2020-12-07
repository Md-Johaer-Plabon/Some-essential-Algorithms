/* Name : Md Johaer Plabon
   Dept. of Computer Science & Engineering, SEC. */
   
   
   #include <bits/stdc++.h>
using namespace std;
/* The solution is exists for ,
    ax + by = c if c%gcd(a,b)==0; where, 
    
    we know ,
      a(xg) + b(yg) = gcd(a,b) or g, [According to Euclideian Extended GCD algorithm]
      then divide by g and multiplied by c we get,
       => a(xg*c/g) + b(yg*c/g) = g*c/g or c;
       so, x= (xg*c/g) and y= (yg*c/g) .
*/

int main() {
	
	int a,b,c,q,r1,r2,r,s1=1,s2=0,s,t1=0,t2=1,t;
	
	cin>>a>>b>>c;
	if(c%__gcd(a,b)){cout<<"Solution DOesn't Exist"<<endl;return 0;}
	r1=a,r2=b;
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
	int g=r1,xg=s,yg=t; 
	// Accordance to linear diophantine equation 
	int x= xg*c/g, y= yg*c/g; 
	cout<<x<<" "<<y<<endl;
	return 0;
}

   
