#include <bits/stdc++.h>
using namespace std;
int n,m,step;
int main() {
	srand(time(NULL));
	for(int i=1;i<=25;i++){
		freopen((to_string(i)+".in").c_str(),"w",stdout);
		n=90+rand()%11;
		m=90+rand()%11;
		step=900+rand()%101;
		cout<<m<<" "<<n<<" "<<step<<endl;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cout<<rand()%5<<" ";
			}
			cout<<endl;
		}
		fclose(stdout);
	}
	return 0;
}
