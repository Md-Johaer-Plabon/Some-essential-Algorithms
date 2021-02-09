/* 
Name : Johaer Plabon 
Dept : CSE,Sylhet Engineering College 
Algorithm : Bi-Connected Component or Maximal Sub-graph. 
Complexity : O(V+E). 
Prerequisite : Articulation points/Bridge.
*/ 



#include <bits/stdc++.h>
using namespace std; 
vector<int>v[1000]; 
int vis[1000],low[1000],parent[1000],tme=0,ap[1000],chk; 
stack<pair<int,int> >st; 
int cs=0;
void AP(int x){ 
  vis[x] = low[x] = ++tme;
  
  for(int i=0;i<v[x].size();i++){
  	if(!vis[v[x][i]]) {
  	parent[v[x][i]]=x; 
  	if(parent[x]==-1)chk++; 
  	st.push({x,v[x][i]}); 
  	AP(v[x][i]); 
  	low[x] = min(low[x],low[v[x][i]]);
  	
  	if(vis[x]<=low[v[x][i]]){ 
  	if(parent[x]!=-1)
  	ap[x]=1; 
  	cout<<++cs<<". ";
  	while(1){ 
  	if(st.top().first==x&&st.top().second==v[x][i])break;	
  	cout<<st.top().first<<" - "<<st.top().second<<" , ",st.pop(); 
  	}
  	cout<<st.top().first<<" - "<<st.top().second<<endl;st.pop();
  	} 
  	
  	
  } 

  	if(v[x][i]!=parent[x]){
  		
  	if(low[x]>vis[v[x][i]])
  	st.push({x,v[x][i]}); 
  	
  	low[x] = min(low[x],vis[v[x][i]]); 
  }
  
  }
	
}
int main() {
	int n,m,x,y; 
	cin>>n>>m; 
	for(int i=0;i<m;i++) 
	cin>>x>>y,v[x].push_back(y),v[y].push_back(x); 
	
	for(int i=0;i<n;i++) 
	vis[i]=0,low[i]=INT_MAX,parent[i]=-1; 
	cout<<"Bi-connected Sub-graphs are :"<<endl;
	AP(0); 
 
	cout<<endl;
	if(chk>=2)ap[0]=1; 
	cout<<"Articulation Points are : "<<endl;
	for(int i=0;i<n;i++) 
	if(ap[i])cout<<i<<" "; 
	cout<<endl; 
	
	return 0;
}
