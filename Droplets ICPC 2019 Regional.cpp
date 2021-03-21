#include <bits/stdc++.h>
using namespace std;
char st[1005][1005]; 
bool vis[1005][1005]; 
int coun;
void dfs(int x,int y){
	coun++; 
//	cout<<x<<" "<<y<<endl;
	vis[x][y]=1;
	if(!vis[x+1][y]&&!vis[x+2][y])vis[x+1][y]=1,dfs(x+2,y);
	if(!vis[x-1][y]&&x-1>=2&&!vis[x-2][y])vis[x-1][y]=1,dfs(x-2,y); 
	if(!vis[x][y+1]&&!vis[x][y+2])vis[x][y+1]=1,dfs(x,y+2);
	if(!vis[x][y-1]&&!vis[x][y-2])vis[x][y-1]=1,dfs(x,y-2);
} 

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
		int n,m; 
		scanf("%d%d",&n,&m);
		for(int i=0;i<n+n-1;i++) 
		  for(int j=0;j<m+m-1;j++) 
		      st[i][j]='.',vis[i][j]=0;
		for(int i=0;i<n+n;i+=2) 
		  for(int j=0;j<m+m;j+=2) 
		     cin>>st[i][j]; 
	   	for(int i=0;i<n+n-1;i+=2) 
		  for(int j=0;j<m+m-1;j+=2) {
		  	if(st[i][j]=='D')vis[i+1][j]=1,vis[i+2][j]=1,vis[i][j]=1;
		  	if(st[i][j]=='B')vis[i][j]=1,vis[i+1][j]=1,vis[i+2][j]=1,vis[i][j+1]=1,vis[i][j+2]=1;
		  	if(st[i][j]=='R')vis[i][j]=1,vis[i][j+1]=1,vis[i][j+2]=1;
		  	if(st[i][j]=='N')vis[i][j]=1;
		  }
	coun=0;
	int res=0;
	for(int j=1;j<2*m-2;j+=2) 
	if(!vis[1][j]&&!vis[0][j]){
	dfs(1,j),res+=coun; 
	coun=0;
	}
	printf("Case %d: %d\n",++cs,res);
	
	}
	return 0;
}
