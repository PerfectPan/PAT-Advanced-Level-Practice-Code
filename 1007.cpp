#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef long long ll;
const int N=10000+10;
struct Node{
    ll pre;
    int pos;
    bool operator<(const Node&rhs)const{
        if (pre==rhs.pre) return pos<rhs.pos;
        return pre<rhs.pre;
    }
};
set<Node>S;
int n,i;
ll a[N],pre,ret=-1000000000000000000LL;
bool flag;
int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%lld",&a[i]),flag|=a[i]>=0;
    if (flag){
        pair<int,int>ans=MP(1,1);
        S.insert((Node){0,1});
        for (i=1;i<=n;++i){
            pre+=a[i];
            auto it=S.begin();
            ll delta=pre-it->pre;
            if (delta>ret){
                ret=delta;
                ans=MP(it->pos,i);
            }
            else if (delta==ret) ans=min(ans,MP(it->pos,i));
            S.insert((Node){pre,i+1});
        }
        printf("%lld %lld %lld\n",ret,a[ans.first],a[ans.second]);
    }
    else printf("%d %lld %lld\n",0,a[1],a[n]);
    return 0;
}