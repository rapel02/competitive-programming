#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"halo"<<endl;
	srand(time(NULL));
	long long n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF)
	{
		n++;
		m++;
		if(n>m) swap(n,m);
		int lvn = sqrt(n);
		int lvm = sqrt(m);
	}
}
