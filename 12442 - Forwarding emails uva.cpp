
#include <bits/stdc++.h>
using namespace std;
vector<int>v[50005],vis(50005),rv[50005],nn(50005),nv[50005],in(50005),dis(50005),par(50005); 
stack<int>st;
int coun;
int ind=INT_MAX;
void dfs(int x){
	vis[x]=1; 
	for(int i=0;i<v[x].size();i++) 
	if(!vis[v[x][i]]) 
	dfs(v[x][i]); 
	
	st.push(x); 
}

void dag(int x){
	vis[x]=1;
	coun++;
	ind = min(ind,x);
	for(int i=0;i<rv[x].size();i++) 
	if(!vis[rv[x][i]]) 
	dag(rv[x][i]); 
	
	nn[x]=ind;
}
void clr(){ 
	for(int i=0;i<=50000;i++)
	v[i].clear(),vis[i]=0,rv[i].clear(),nn[i]=0, 
	nv[i].clear(),in[i]=0,dis[i]=0,par[i]=i; 
	while(!st.empty()) 
	st.pop();
}
int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
		clr();
		int n,x,y; 
		cin>>n; 
		for(int i=0;i<n;i++) 
		cin>>x>>y,v[x].push_back(y),rv[y].push_back(x); 
		
		for(int i=1;i<=n;i++)if(!vis[i])dfs(i); 
		for(int i=0;i<=n;i++)vis[i]=0; 
		vector<int>chk(50005),col(50005);
		while(!st.empty()){
		if(!vis[st.top()]){ 
		ind = INT_MAX,coun=0; 
		dag(st.top());
		if(coun>1)
		col[ind]=coun-1;
		chk[ind]=1;
		}
		st.pop(); 
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) 
		   for(int j=0;j<v[i].size();j++) 
		       if(nn[i]!=nn[v[i][j]]) 
		          nv[nn[i]].push_back(nn[v[i][j]]),in[nn[v[i][j]]]++;
		          
		queue<int>q;
		for(int i=1;i<=n;i++) 
		if(!in[i]&&chk[i])q.push(i); 
		int maxx=0;
		while(!q.empty()){
			x = q.front(); 
			maxx=max(maxx,max(col[x],dis[x]));
		//	cout<<x<<" "<<par[x]<<endl;
			q.pop(); 
			for(int i=0;i<nv[x].size();i++){ 
			if(dis[nv[x][i]]<dis[x]+1+col[nv[x][i]]) 
			dis[nv[x][i]]=dis[x]+1+col[nv[x][i]],q.push(nv[x][i]),par[nv[x][i]]=par[x]; 
			else if(dis[nv[x][i]]==dis[x]+1+col[nv[x][i]]&&par[nv[x][i]]>par[x]) 
			par[nv[x][i]]=par[x]; 
			}
		} 
	int ans = INT_MAX; 
//	cout<<maxx<<endl;
	for(int i=1;i<=n;i++)
	if(dis[i]==maxx||col[i]==maxx)ans=min(ans,par[i]); 
	printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}
