/* Name : Md Johaer Plabon
   Dept. of Computer Science & Engineering, SEC. */


#include <bits/stdc++.h>
using namespace std; 
#define mod 1000000007
/* Condition For inverse modulo is, 
      (r1^-1)%r2 will exists if gcd(r1,r2)==1 */
void EE(ll a, ll b, ll& x, ll& y){
    if(a%b == 0){
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = (temp%mod) - ((y%mod)*((a/b)%mod))%mod; 
    y%=mod;
} 

int main() {
	int a,b,x,y;
	EE(a,b,x,y);
	ll modinv = (x+mod)%mod;
}
