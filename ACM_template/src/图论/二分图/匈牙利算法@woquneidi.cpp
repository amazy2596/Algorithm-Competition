int match[N]; //match是表示右边的点匹配左边的哪一个点
set<int> st; // 每次dfs后要清空
bool dfs(int x) {
	for(auto it : edge[x]) {
		if(st.count(it)) continue;
		st.insert(it);
		if(!match[it] || dfs(match[it])) {
			match[it] = x;
			return 1;
		}
	}


	return 0;
}