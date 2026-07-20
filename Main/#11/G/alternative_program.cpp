#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > li;

long long mi[114514],ni[114514];
const int MOD=1000000007;

int p[114514],q[114514],a[114514],b[114514];

int main(){freopen("seminar.in","r",stdin);freopen("seminar.out","w",stdout);
    mi[0]=1;for(int i=1;i<114514;i++)mi[i]=mi[i-1]*10%MOD;
    ni[0]=1;for(int i=1;i<114514;i++)ni[i]=ni[i-1]*700000005%MOD;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>q[i],p[q[i]]=i;
    a[1]=1;
    for(int i=2;i<=n;i++)
        if(p[i]<p[i-1])a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    for(int i=1;i<=n;i++)b[p[i]]=a[i];
    long long nowans=0,ans=0;int sz=-1;
    for(int i=1;i<=n;i++){
        while(sz>=0&&li[sz].first>b[i])nowans-=li[sz].second*mi[b[i-1]-li[sz].first],li.pop_back(),sz--;
        if(b[i]>b[i-1])nowans*=mi[b[i]-b[i-1]];else nowans*=ni[b[i-1]-b[i]];
        nowans%=MOD;
        if(sz==-1)li.push_back(make_pair(1,1)),nowans+=mi[b[i]-1],sz++;
        else if(b[i-1]<b[i]);
        else if(li[sz].first==b[i]){
            auto t=li[sz];li.pop_back();li.push_back(make_pair(t.first,t.second+1));
            nowans+=mi[b[i]-t.first];
        }else{
            li.push_back(make_pair(b[i],1));sz++;nowans++;
        }
        nowans%=MOD;
        ans+=nowans;
        ans%=MOD;
    }
    cout<<(ans+MOD)%MOD<<endl;
}
