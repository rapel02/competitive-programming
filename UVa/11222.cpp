#include<bits/stdc++.h>
using namespace std;

int r[3][1005];
int prob[10005];

int main()
{
	int test,a1,a2,a3;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		memset(prob,0,sizeof(prob));
		scanf("%d",&a1);
		for(int b=0;b<a1;b++)
		{
			scanf("%d",&r[0][b]);
			prob[r[0][b]]++;
		}
		scanf("%d",&a2);
		for(int b=0;b<a2;b++)
		{
			scanf("%d",&r[1][b]);
			prob[r[1][b]]++;
		}
		scanf("%d",&a3);
		for(int b=0;b<a3;b++)
		{
			scanf("%d",&r[2][b]);
			prob[r[2][b]]++;
		}
		sort(r[0],r[0]+a1);
		sort(r[1],r[1]+a2);
		sort(r[2],r[2]+a3);
		int w1=0,w2=0,w3=0;
		for(int b=0;b<a1;b++)
		{
			if(prob[r[0][b]]==1) w1++;
		}
		for(int b=0;b<a2;b++)
		{
			if(prob[r[1][b]]==1) w2++;
		}
		for(int b=0;b<a3;b++)
		{
			if(prob[r[2][b]]==1) w3++;
		}
		printf("Case #%d:\n",a);
		if(w1>w2 && w1>w3)
		{
			printf("%d %d",1,w1);
			for(int b=0;b<a1;b++)
				if(prob[r[0][b]]==1) printf(" %d",r[0][b]);
			printf("\n");
		}
		else if(w1>w2 && w1==w3)
		{
			printf("%d %d",1,w1);
			for(int b=0;b<a1;b++)
				if(prob[r[0][b]]==1) printf(" %d",r[0][b]);
			printf("\n");
			printf("%d %d",3,w3);
			for(int b=0;b<a3;b++)
				if(prob[r[2][b]]==1) printf(" %d",r[2][b]);
			printf("\n");
		}
		else if(w1==w2 && w1>w3)
		{
			printf("%d %d",1,w1);
			for(int b=0;b<a1;b++)
				if(prob[r[0][b]]==1) printf(" %d",r[0][b]);
			printf("\n");
			printf("%d %d",2,w2);
			for(int b=0;b<a2;b++)
				if(prob[r[1][b]]==1) printf(" %d",r[1][b]);
			printf("\n");
		}
		else if(w2>w1 && w2>w3)
		{
			printf("%d %d",2,w2);
			for(int b=0;b<a2;b++)
				if(prob[r[1][b]]==1) printf(" %d",r[1][b]);
			printf("\n");
		}
		else if(w2>w1 && w2==w3)
		{
			printf("%d %d",2,w2);
			for(int b=0;b<a2;b++)
				if(prob[r[1][b]]==1) printf(" %d",r[1][b]);
			printf("\n");
			printf("%d %d",3,w3);
			for(int b=0;b<a3;b++)
				if(prob[r[2][b]]==1) printf(" %d",r[2][b]);
			printf("\n");
		}
		else if(w3>w1 && w3>w2)
		{
			printf("%d %d",3,w3);
			for(int b=0;b<a3;b++)
				if(prob[r[2][b]]==1) printf(" %d",r[2][b]);
			printf("\n");
		}
		else if(w1==w2 && w2==w3)
		{
			printf("%d %d",1,w1);
			for(int b=0;b<a1;b++)
				if(prob[r[0][b]]==1) printf(" %d",r[0][b]);
			printf("\n");
			printf("%d %d",2,w2);
			for(int b=0;b<a2;b++)
				if(prob[r[1][b]]==1) printf(" %d",r[1][b]);
			printf("\n");
			printf("%d %d",3,w3);
			for(int b=0;b<a3;b++)
				if(prob[r[2][b]]==1) printf(" %d",r[2][b]);
			printf("\n");
		}
	}
}
