#include<bits/stdc++.h>
using namespace std;

bool ada=false;
long long num;

long long compute(long long now,long long step)
{
	if(now>=num && step==0) ada=true;
	if(now>=num) return 0;
	if(step==0) compute(now*9,step^1);
	else compute(now*2,step^1);
}

int main()
{
	while(scanf("%lld",&num)!=EOF)
	{
		ada=false;
		compute(1,0);
		if(ada==false) printf("Stan wins.\n");
		else printf("Ollie wins.\n");
	}
}
