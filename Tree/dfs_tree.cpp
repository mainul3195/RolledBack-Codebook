void dfs(int u, int p)
{
	dp[u] = 0 ;
 
	for(auto v: graph[u])
	{
		if(v == p)continue ;
		if(level[v] == 0)
		{
			level[v] = level[u] + 1 ;
			vp.push_back({u, v}) ;
			dfs(v, u) ;
			dp[u] += dp[v] ;
		}
		else if(level[v] < level[u])
		{
			vp.push_back({u, v}) ;
			dp[u]++ ;
		}
		else
		{
			dp[u]-- ;
		}
	}
 
	if(level[u] > 1 && dp[u] == 0)bridges++ ;
 
}