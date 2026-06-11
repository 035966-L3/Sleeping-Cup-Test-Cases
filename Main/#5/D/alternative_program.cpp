#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
#define sort stable_sort
constexpr int mod=100000007,B=1145;
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename TP> inline TP read(TP &num)
{
	TP x=0;
	int f=0;
	char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename TP> inline TP read_mod(TP &num)
{
	TP x=0;
	int f=0;
	char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=((x<<1)+(x<<3)+(ch^48))%mod,ch=getchar();
	return num=f?-x:x;
}
template<typename ...Args> inline void read(Args &...args)
{
	(read(args),...);
}
template<typename TP> inline void write(TP x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename TP> inline void writeln(TP x)
{
	write<TP>(x);
	puts("");
}
inline int qpow(int a,int b)
{
	a%=mod;
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
struct mat
{
	int a00,a01,a10,a11;
	mat(int b00=0,int b01=0,int b10=0,int b11=0):a00(b00),a01(b01),a10(b10),a11(b11){}
	mat operator*(const mat &b) const
	{
		return mat((a00*b.a00+a01*b.a10)%mod,(a00*b.a01+a01*b.a11)%mod,(a10*b.a00+a11*b.a10)%mod,(a10*b.a01+a11*b.a11)%mod);
	}
	mat operator^(int b) const
	{
		mat res(1,0,0,1),a(*this);
		while(b)
		{
			if(b&1) res=res*a;
			a=a*a;
			b>>=1;
		}
		return res;
	}
} P[B];
inline pair<string,int> strdiv(string s,int k)
{
	string q; int res=0;
	for(char c:s)
	{
		res=res*10+(c^48);
		if(!q.empty()||res>=k) q.push_back((res/k)^48);
		res%=k;
	}
	if(q.empty()) q.push_back('0');
	return {q,res};
}
inline string strsub(string s)
{
	string res=s;
	int i=(int)res.size()-1;
	while(i>=0&&res[i]=='0') res[i]='9',--i;
	if(i>=0) res[i]--;
	if(res[0]=='0'&&res.size()>1) res.erase(res.begin());
	if(res.empty()) res.push_back('0');
	return res;
}
signed main()
{
#ifndef LOCAL
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
#endif
	P[0]=mat(1,0,0,1);
	rep(i,1,B-1) P[i]=P[i-1]*mat(2023,i*i%mod,i,833);
	int T; cin>>T; while(T--)
	{
		string ns; cin>>ns; string sn=strsub(ns);
		int n=0;
		for(char c:ns) n=((n<<1)+(n<<3)+(c^48))%mod;
		auto [q,r]=strdiv(sn,B);
		mat mt=mat(1,0,0,1);
		for(auto c:q) mt=(mt^10)*(P[B-1]^(c^48));
		mt=mt*P[r];
		writeln(((mt.a00*n%mod+mt.a01)*qpow(mt.a10*n+mt.a11,mod-2)%mod+mod)%mod);
	}
	return 0;
}
