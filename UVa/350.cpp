#include<bits/stdc++.h>
using namespace std;

bool mark[150000];

int main()
{
	int z,i,m,l,tot = 0;
	int k = 0;
	while(1)
	{
		scanf("%d %d %d %d",&z,&i,&m,&l);
		if(z+i+m+l==0) break;
		k++;
		memset(mark,false,sizeof(mark));
		mark[l] = true;
		tot = 1;
		while(mark[(z*l+i)%m]!=true)
		{
			mark[(z*l+i)%m] = true;
			l = (z*l+i)%m;
			tot++;
		}
		printf("Case %d: %d\n",k,tot);
	}
}
