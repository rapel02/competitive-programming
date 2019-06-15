#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	while(1)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a==0&&b==0&&c==0&&d==0) break;
		int val1=a*60+b;
		int val2=c*60+d;
		if(val2<val1) val2+=1440;
		printf("%d\n",val2-val1);
	}
}
