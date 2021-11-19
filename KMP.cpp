#include <bits/stdc++.h>
using namespace std;
string s,ss;
int dp[3000005];
void lps(int len){
  	int i=1,j=0; 
	  dp[i]=j; 
	  while(i<len){
		  while(j>0 && ss[i]!=ss[j])j=dp[j-1]; 
		  i++,j++; 
		  dp[i]=j+1;
	  }
}

int main() {
	int t,cs=0; 
	cin>>t; 
	while(t--){
    s="",ss="";
    cin>>s;
	int len = s.size();//strlen(s); 
	for(int i=0;i<=2*len;i++)dp[i]=0;
	for(int i=len-1;i>=0;i--)ss+=s[i]; 
	lps(len); 
	int i=0,j=0; 
	  while(i<len){
		  while(j>0 && s[i]!=ss[j])j=dp[j-1];
		  i++,j++; 
	  }

	printf("Case %d: ",++cs);
	printf("%d\n",2*len-j);
	}
	return 0;
}
