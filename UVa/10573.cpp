#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc); getchar();
	while(tc--)
	{
		double r1,r2,r;
		scanf("%lf",&r1);
		char w = getchar();
		if(w=='\n')
		{
			printf("%.4lf\n",PI*(r1*r1/8));
		}
		else
		{
			scanf("%lf",&r2);
			getchar();
			r = (r1+r2);
			printf("%.4lf\n",PI*(2*r1*r2));
		}
	}
}
