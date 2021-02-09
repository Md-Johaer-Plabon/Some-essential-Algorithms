/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College. 
Algorithm : Articulation points (Tarzan's Algorithm). 
Complexity : O(V+E) 
*/ 


#include <bits/stdc++.h>
using namespace std; 
vector<int>v[1000]; 
int vis[1000],low[1000],parent[1000],tme=0,ap[1000],chk;
void AP(int x){ 
  vis[x] = low[x] = ++tme; 
  
  for(int i=0;i<v[x].size();i++){
  	if(!vis[v[x][i]]) {
  	parent[v[x][i]]=x; 
  	if(parent[x]==-1)chk++;
  	AP(v[x][i]); 
  	
  	low[x] = min(low[x],low[v[x][i]]); 
  	
  	if(parent[x]!=-1&&vis[x]<=low[v[x][i]]) 
  	ap[x]=1; 
  	
  }	
  	if(v[x][i]!=parent[x]) 
  	low[x] = min(low[x],vis[v[x][i]]); 
  }
	
}
int main() {
	int n,m,x,y; 
	cin>>n>>m; 
	for(int i=0;i<m;i++) 
	cin>>x>>y,v[x].push_back(y),v[y].push_back(x); 
	
	for(int i=0;i<n;i++) 
	vis[i]=0,low[i]=INT_MAX,parent[i]=-1; 
	
	AP(0); 
	 
	if(chk>=2)ap[0]=1; 
	
	cout<<"Articulation Points are : "<<endl;
	for(int i=0;i<n;i++) 
	if(ap[i])cout<<i<<" "; 
	cout<<endl;
	return 0;
}
