#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=10000+10;
const int INF=2000000000;
int m,n,i,u,v,root,dep[N],sz[N],fa[N],ls[N],rs[N],pre[N],ord[N];
map<int,int>mp;
int c=0;
int solve(int l,int r,int L,int R){
	if (l>r) return n+1;
	if (l==r){
		ls[l]=rs[l]=n+1;
		return l;
	}
	int mid;
	for (int i=l;i<=r;++i){
		if (ord[i]==pre[L]){
			mid=i;
			break;
		}
	}
	ls[mid]=solve(l,mid-1,L+1,L+mid-l);
	rs[mid]=solve(mid+1,r,L+mid-l+1,R);
	return mid;
}
void dfs(int u,int f){
	if (u==n+1) return;
	sz[u]=1,fa[u]=f,dep[u]=dep[f]+1;
	dfs(ls[u],u);
	dfs(rs[u],u);
	sz[u]+=sz[ls[u]]+sz[rs[u]];
}
int lca(int u,int v){
	while (dep[u]!=dep[v]){
		if (dep[u]>dep[v]) u=fa[u];
		else v=fa[v];
	}
	while (u!=v) u=fa[u],v=fa[v];
	return ord[u];
}
int main(){
	read(m),read(n);
	for (i=1;i<=n;++i) read(ord[i]),mp[ord[i]]=i;
	for (i=1;i<=n;++i) read(pre[i]);
	root=solve(1,n,1,n);
	dfs(root,0);
	for (;m--;){
		read(u),read(v);
		bool flagU=mp.find(u)!=mp.end();
		bool flagV=mp.find(v)!=mp.end();
		if (flagU && flagV){
			int idxU=mp[u],idxV=mp[v];
			int lcaValue=lca(idxU,idxV);
			if (lcaValue==u){
				printf("%d is an ancestor of %d.\n",u,v);
			}
			else if (lcaValue==v){
				printf("%d is an ancestor of %d.\n",v,u);
			}
			else{
				printf("LCA of %d and %d is %d.\n",u,v,lcaValue);
			}
		}
		else if (!flagU && flagV){
			printf("ERROR: %d is not found.\n",u);
		}
		else if (flagU && !flagV){
			printf("ERROR: %d is not found.\n",v);
		}
		else{
			printf("ERROR: %d and %d are not found.\n",u,v);
		}
	}
	return 0;
}