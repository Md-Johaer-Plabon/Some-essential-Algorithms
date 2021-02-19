/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College
*/ 
----> Worst Case for dsu where path compression is necessary.

#include <bits/stdc++.h>
using namespace std;
vector<int>par(10005); 

int find(int x){
   if(par[x]==x) return x;
   
   return par[x] = find(par[x]); 
   
}

void un(int x,int y){
	int a = find(x); 
	int b = find(y); 
	
	par[a] = b;
}

int main() {
	
	for(int i=1;i<=10;i++)par[i]=i; 
	
	un(7,8); 
	un(7,6);
	un(5,6);
  un(5,4);
	un(3,4);
	un(3,2);
	un(1,2);
	
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
