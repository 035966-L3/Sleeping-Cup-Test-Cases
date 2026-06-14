#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int maxn=1e6+10;
#define int __int128
bool b[maxn];
__int128 qzh[maxn],pqzh[maxn],qqzh[maxn],q2qzh[maxn],qpqzh[maxn],qqqzh[maxn],qqpqzh[maxn],qq2qzh[maxn],qqqqzh[maxn];
__int128 tans=0;
//pqzh:[l,r]内3的位置之和
//qqzh:[l,r]内qzh[3的位置-1]之和
//q2qzh:[l,r]内qzh[3的位置]之和
//qpqzh:[l,r]内pqzh[3的位置]之和
//qqqzh:[l,r]内qqzh[3的位置]之和
//qqpqzh:[l,r]内qpqzh[3的位置]之和
//qq2qzh:[l,r]内q2qzh[3的位置]之和
//qqqqzh:[l,r]内qqqzh[3的位置]之和
string s;
__int128 n,k;
__int128 zero=0;
__int128 get(int l,int r){
	__int128 ans=0;
	__int128 maya=qzh[r]-qzh[l-1];
	ans=qqzh[r]*qzh[r]*maya;
	ans=ans+(zero-qqzh[r]*(q2qzh[r]-q2qzh[l-1])-pqzh[r]*qzh[r]*maya+pqzh[r]*(q2qzh[r]-q2qzh[l-1])-qzh[r]*qzh[r]*qzh[r]*maya+qzh[r]*qzh[r]*(q2qzh[r]-q2qzh[l-1])+(r+1)*qzh[r]*qzh[r]*maya
		-(r+1)*qzh[r]*(q2qzh[r]-q2qzh[l-1])+qpqzh[r]*maya-(qqpqzh[r]-qqpqzh[l-1])+q2qzh[r]*qzh[r]*maya-(qq2qzh[r]-qq2qzh[l-1])*qzh[r]-(r+1)*q2qzh[r]*maya+(r+1)*(qq2qzh[r]-qq2qzh[l-1])
		-qqqzh[r]*maya+qqqqzh[r]-qqqqzh[l-1]);
	return ans;
}
/*
*/
bool check(int l,int r){
	return get(l,r)>=k;
}
inline __int128 read()
{
	__int128 x = 0;
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar_unlocked();
	}
	return x;
}
inline std::string readline()
{
	std::string x = "";
	char c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	while (c >= '0')
	{
		x += c;
		c = getchar_unlocked();
	}
	return x;
}
void write(__int128 x)
{
	if (x <= 9)
	{
		putchar_unlocked(x + '0');
		return;
	}
	write(x / 10);
	putchar_unlocked(x % 10 + '0');
}
inline void writeline(__int128 x)
{
	write(x);
	putchar_unlocked('\n');
}

signed main(){
	freopen("sorrow.in","r",stdin);
	freopen("sorrow.out","w",stdout);
//	ios;
//	cin.tie(0);
//	cout.tie(0);
	n=read(),k=read();
	s=readline();
	for(int i=0;i<(int)s.size();++i){
		b[i+1]=s[i]=='3';
		qzh[i+1]=qzh[i]+b[i+1];
	}
	for(int i=1;i<=n;++i){
		pqzh[i]=pqzh[i-1]+i*b[i];
		qqzh[i]=qqzh[i-1]+qzh[i-1]*b[i];
		q2qzh[i]=q2qzh[i-1]+qzh[i]*b[i];
		qpqzh[i]=qpqzh[i-1]+pqzh[i]*b[i];
		qqqzh[i]=qqqzh[i-1]+qqzh[i]*b[i];
		qqpqzh[i]=qqpqzh[i-1]+qpqzh[i]*b[i];
		qq2qzh[i]=qq2qzh[i-1]+q2qzh[i]*b[i];
		qqqqzh[i]=qqqqzh[i-1]+qqqzh[i]*b[i];
	}
	int l,r=1;
	for(l=1;l<=n;l++){
		for(;!check(l,r)&&r<=n;r++);
		tans+=n-r+1;
	}
	write(tans);
}
