#include <stdio.h>

int isValid(int r, int c, int n, int m)
{
	if(r < 0 || r >=n || c < 0 || c >= m)
		return 0;
	else 
		return 1;
}

void dfs(int r, int c, int n, int m, char map[][m], int vis[][m])
{
	vis[r][c] = 1;
	if(isValid(r-1,c,n,m) && map[r-1][c]=='L' && vis[r-1][c]==0)
		dfs(r-1,c,n,m,map,vis);
	if(isValid(r+1,c,n,m) && map[r+1][c]=='L' && vis[r+1][c]==0)
		dfs(r+1,c,n,m,map,vis);
	if(isValid(r,c-1,n,m) && map[r][c-1]=='L' && vis[r][c-1]==0)
		dfs(r,c-1,n,m,map,vis);
	if(isValid(r,c+1,n,m) && map[r][c+1]=='L' && vis[r][c+1]==0)
		dfs(r,c+1,n,m,map,vis);
}

int main()
{
	int n,m,i,j,ct=0;
	scanf("%d%d",&n,&m);
	char map[n][m];
	int vis[n][m];
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf(" %c",&map[i][j]);
			vis[i][j] = 0;
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(vis[i][j] == 1 || map[i][j] == 'W')
				continue;
			dfs(i,j,n,m,map,vis);
			ct++;
		}
	}
	printf("%d\n",ct);
	return 0;
}
