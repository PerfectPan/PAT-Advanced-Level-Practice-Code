#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct Node{
    string name;
    int g[4];
    Node(){memset(g,-1,sizeof(g));}
    bool operator < (const Node&rhs)const{
        if (g[3]==rhs.g[3]) return name<rhs.name;
        return g[3]>rhs.g[3];
    }
}p[maxn],q[maxn];
string s;
map<string,int>mp;
int P,N,M,cnt,i,x,n;
int get(const string&s){
    if (mp.find(s)!=mp.end()) return mp[s];
    return mp[s]=++cnt;
}
int cal(int idx){
    if (p[idx].g[1]>p[idx].g[2]) return round(0.4*p[idx].g[1]+0.6*p[idx].g[2]);
    return p[idx].g[2];
}
int main(){
    scanf("%d%d%d",&P,&M,&N);
    for (i=1;i<=P;++i){
        cin>>s;scanf("%d",&x);
        int id=get(s);
        p[id].name=s,p[id].g[0]=x;
    }
    for (i=1;i<=M;++i){
        cin>>s;scanf("%d",&x);
        int id=get(s);
        p[id].name=s,p[id].g[1]=x;
    }
    for (i=1;i<=N;++i){
        cin>>s;scanf("%d",&x);
        int id=get(s);
        p[id].name=s,p[id].g[2]=x;
    }
    for (i=1;i<=cnt;++i){
        if (p[i].g[0]<200 || cal(i)<60) continue;
        q[++n]=p[i];
        q[n].g[3]=cal(i);
    }
    sort(q+1,q+1+n);
    for (i=1;i<=n;++i) cout<<q[i].name<<" "<<q[i].g[0]<<" "<<q[i].g[1]<<" "<<q[i].g[2]<<" "<<q[i].g[3]<<endl;
    return 0;
}