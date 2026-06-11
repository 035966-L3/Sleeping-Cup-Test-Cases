#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,M=800005;
char B[1<<20],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=B)+fread(B,1,1<<20,stdin),p1==p2)?0:*p1++)
inline int rd(){
	int x=0;char c=GC;
	while(c<'0'||c>'9')c=GC;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=GC;
	return x;
}
int ls[M],rs[M],L[M],R[M],sz[M],pr[M],tr[M],tp,tot,rt[N];
inline int nd(int l,int r){
	int u=tp?tr[tp--]:++tot;
	ls[u]=rs[u]=0;L[u]=l;R[u]=r;sz[u]=r-l+1;pr[u]=rand();
	return u;
}
inline void up(int u){sz[u]=(R[u]-L[u]+1)+sz[ls[u]]+sz[rs[u]];}
void sp(int u,int k,int&x,int&y){
	if(!u){x=y=0;return;}
	if(L[u]<k)x=u,sp(rs[u],k,rs[u],y);
	else y=u,sp(ls[u],k,x,ls[u]);
	up(u);
}
int mg(int x,int y){
	if(!x||!y)return x|y;
	if(pr[x]<pr[y]){rs[x]=mg(rs[x],y);up(x);return x;}
	else{ls[y]=mg(x,ls[y]);up(y);return y;}
}
inline void ins(int v,int l,int r){
	int x,y;sp(rt[v],l,x,y);
	rt[v]=mg(mg(x,nd(l,r)),y);
}
inline void del(int v,int l){
	int x,y,z;sp(rt[v],l,x,z);sp(z,l+1,y,z);
	if(y)tr[++tp]=y;rt[v]=mg(x,z);
}
int rk(int u,int k){
	if(!u)return 0;
	if(k<=L[u])return rk(ls[u],k);
	if(k>R[u])return sz[ls[u]]+(R[u]-L[u]+1)+rk(rs[u],k);
	return sz[ls[u]]+(k-L[u]);
}
int kth(int u,int k){
	if(!u)return-1;
	if(k<=sz[ls[u]])return kth(ls[u],k);
	k-=sz[ls[u]];
	int len=R[u]-L[u]+1;
	if(k<=len)return L[u]+k-1;
	return kth(rs[u],k-len);
}
struct Node{
	int l,r;mutable int v;
	Node(int L,int R=0,int V=0):l(L),r(R),v(V){}
	bool operator<(const Node&o)const{return l<o.l;}
};
set<Node>s;typedef set<Node>::iterator IT;
IT split(int p){
	IT it=s.lower_bound(Node(p));
	if(it!=s.end()&&it->l==p)return it;
	--it;int l=it->l,r=it->r,v=it->v;
	del(v,l);ins(v,l,p-1);ins(v,p,r);
	s.erase(it);s.insert(Node(l,p-1,v));
	return s.insert(Node(p,r,v)).first;
}
void assign(int l,int r,int v){
	IT itr=split(r+1),itl=split(l);
	for(IT it=itl;it!=itr;){del(it->v,it->l);s.erase(it++);}
	s.insert(Node(l,r,v));ins(v,l,r);
}
int qx[N];ll qy[N];
int main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	srand(19260817);
	int n=rd(),q=rd(),st=1,v=rd();
	for(int i=2,c;i<=n;++i){
		c=rd();
		if(c!=v){s.insert(Node(st,i-1,v));ins(v,st,i-1);st=i;v=c;}
	}
	s.insert(Node(st,n,v));ins(v,st,n);
	while(q--){
		int op=rd();
		if(op==1){
			int l=rd(),r=rd(),x=rd();
			assign(l,r,x);
		}else{
			int m=rd(),c=0;ll tot=0;
			for(int i=0,x,y;i<m;++i){
				x=rd();y=rd();tot+=y;
				if(c&&qx[c-1]==x)qy[c-1]+=y;
				else qx[c]=x,qy[c++]=y;
			}
			if(tot>n){puts("No");continue;}
			bool ok=1;int cur=1;
			for(int i=0;i<c;++i){
				if(qy[i]<=0)continue;
				if(!rt[qx[i]]){ok=0;break;}
				int r=rk(rt[qx[i]],cur);
				if(r+qy[i]>sz[rt[qx[i]]]){ok=0;break;}
				cur=kth(rt[qx[i]],r+qy[i])+1;
				if(cur>n+1)cur=n+1;
			}
			puts(ok?"Yes":"No");
		}
	}
	return 0;
}
