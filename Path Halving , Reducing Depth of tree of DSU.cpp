/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
*/ 


#include <bits/stdc++.h>
using namespace std;
vector<int>par(10005),chil(10005,0); 
int child=0;
int find(int x){ 
	child++;
   if(par[x]==x) return x; 
      cout<<" --- "<<endl;
   return find(par[x]); 
}

void un(int x,int y){ 
	child=0;
	int a = find(x); 
	chil[a] += child;
	
	child=0;
	int b = find(y); 
	chil[b] += child; 
	
	if(chil[b]>chil[a])
	par[a] = b,chil[b]+=chil[a],chil[a]=0; 
	
	else if(chil[a]>chil[b])
	par[b] = a,chil[a]+=chil[b],chil[b]=0; 
	
	else par[b] = a,chil[a]+=chil[b],chil[b]=0;
}

int main() {
	
	for(int i=1;i<=10;i++)par[i]=i; 
	
	un(8,7); 
	un(7,6);
	un(6,5);
    un(5,4);
	un(4,3);
	un(3,2);
	un(2,1);

	cout<<find(1)<<endl;
	cout<<find(2)<<endl;
	cout<<find(3)<<endl;
	cout<<find(4)<<endl;
	cout<<find(5)<<endl;
	cout<<find(6)<<endl;
	cout<<find(7)<<endl;
	cout<<find(8)<<endl;
	return 0;
}
