#include<bits/stdc++.h>
using namespace std;
bool vis[10000000+10];
void Eratosthenes(int n)
{
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;i++)
	if(!vis[i])
	for(int j=i*i;j<=n;j+=i)
	vis[j]=true;
}
int main()
{
	memset(vis,0,sizeof(vis));
	vis[1]=true;
	int n,m;
	cin>>n>>m;
	Eratosthenes(n);
	int a;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		printf("%s\n",!vis[a]?"Yes":"No");
	}
	return 0;
}
