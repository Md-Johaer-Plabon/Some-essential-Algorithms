void tarjan(int x){
   	vis[x] = low[x] = ++tme; 
   	st.push(x);
   	   for(int i=0;i<v[x].size();i++){
   	   	if(!vis[v[x][i]]){
   	   	   	par[v[x][i]]=x; 
   	   	   	tarjan(v[x][i]); 
   	   	   	
   	   	   	low[x] = min(low[x],low[v[x][i]]);
   	   	}
   	   	
   	   	if(v[x][i]!=par[x]) 
   	   	low[x] = min(low[x],vis[v[x][i]]);
   	   } 
   	  if(low[x]==vis[x]){
   	  	int ind; 
   	  	flag++;
   	  	while(!st.empty()){
   	  	ind = st.top(); 
   	  	color[ind]=flag; 
   	  	st.pop(); 
   	  	if(ind==x)break;
   	  	} 
   	  } 
}
