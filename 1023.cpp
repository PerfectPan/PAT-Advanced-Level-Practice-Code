#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
string s,t;
char ans[50];
int p,cnt1[10],cnt2[10];
int main(){
    cin>>s;
    reverse(s.begin(),s.end());
    t=s;
    int add=0;
    for (int i=0;i<(int)s.length();++i){
        int num=s[i]-'0'+t[i]-'0'+add;
        add=num/10;
        num%=10;
        ans[p++]=num+'0';
        cnt1[s[i]-'0']++;
        cnt2[num]++;
    }
    if (add) ans[p++]=add+'0',cnt2[add]++;
    ans[p]='\0';
    reverse(ans,ans+p);
    bool flag=0;
    for (int i=0;i<10;++i)if(cnt1[i]!=cnt2[i]) flag=1;
    puts(flag?"No":"Yes");
    puts(ans);
    return 0;
}