void bfs(int u)
{
	queue<int>que ;
	que.push(u) ;
	wh_cmpnnt[u] = cmpnnt ;
	while(!que.empty())
	{
		auto u = que.front() ;
		que.pop();
		vector<int>restricted;
		for(auto v: graph[u])
		{
			if(!wh_cmpnnt[v])
			{
				restricted.push_back(v);
				adj[v] = 1 ;
			}
		}
		for(auto v: not_visited)
		{
			if(v == u || adj[v]) continue ;
			que.push(v) ;
			wh_cmpnnt[v] = cmpnnt ;
		}
		for(auto v: restricted)adj[v] = 0 ;
		not_visited = restricted ;
	}
}