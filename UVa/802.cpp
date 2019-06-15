#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;

double comp[3][105];
int t;

double temp[4][4],temp2[4][4];

bool gauss()
{
	int n=3;
	for(int a=0;a<n;a++)
	{
		int k=a;
		for(int b=a+1;b<n;b++) if(fabs(temp[b][a]>fabs(temp[k][a]))) k=b;
		if(temp[k][a]>-eps &&temp[k][a]<eps) continue;
		if(k!=a)
			for(int b=0;b<=n;b++) swap(temp[k][b],temp[a][b]);
		for(int b=0;b<n;b++)
			if(a!=b)
				for(int c=n;c>=a;c--)
					temp[b][c]-=temp[b][a]/temp[a][a]*temp[a][c];
	}
	for(int a=0;a<n;a++)
	{
		int totnz=0;
		for(int b=0;b<n;b++)
			if(temp[a][b]<-eps ||temp[a][b]>eps) totnz++;
		if(totnz==0) 
		{
			if(temp[a][n]>-eps ||temp[a][n]<eps) return false; 
			else continue;
		}
		if(totnz==1) 
		{
			if(temp[a][n]/temp[a][a]==-1) return false;
			else continue;	
		}
		if(temp[a][n]+1<eps)
		{
			for(int b=0;b<=n;b++) temp[a][b]*=-1;
		}
		bool check=false;
		for(int b=0;b<n;b++)
		{
			if(temp[a][b]>eps)
			{
				check=true;
				break;
			}
		}
		if(check==false) return false;
	}
	return true;
}

bool compute()
{
	for(int a=0;a<t;a++)
	{
		for(int b=a;b<t;b++)
		{
			for(int c=b;c<t;c++)
			{
				temp2[0][0]=comp[0][a],temp2[0][1]=comp[0][b],temp2[0][2]=comp[0][c],temp2[0][3]=comp[0][t];
				temp2[1][0]=comp[1][a],temp2[1][1]=comp[1][b],temp2[1][2]=comp[1][c],temp2[1][3]=comp[1][t];
				temp2[2][0]=comp[2][a],temp2[2][1]=comp[2][b],temp2[2][2]=comp[2][c],temp2[2][3]=comp[2][t];
				int order[]={0,1,2};
				bool ada=true;
				do
				{
					for(int d=0;d<3;d++)
						for(int e=0;e<3;e++) temp[e][order[d]]=temp2[e][d];
					for(int d=0;d<3;d++) temp[d][3]=temp2[d][3];
					if(gauss()==false)
					{
						ada=false;
						break;
					}
				}while(next_permutation(order,order+3));
				if(ada==true) return true;
			}
		}
	}
	return false;
//	for(int a=0;a<=t;a++)
//	{
//		for(int b=0;b<=2;b++)
//	//	printf("%lf ",comp[a][b]);
//	//	printf("\n");
//	}
	for(int a=0;a<=2;a++)
	{
		if(comp[a][t]<-eps) return false;
	}
	return true;
}

int main()
{
	int ctt=0;
	while(1)
	{
		scanf("%d",&t);
		if(t==0) break;
		ctt++;
		for(int a=0;a<=t;a++)
			scanf("%lf %lf %lf",&comp[0][a],&comp[1][a],&comp[2][a]);
		//scanf("%lf %lf %lf",&comp[0][t],&comp[1][t],&comp[2][t]);
		printf("Mixture %d\n",ctt);
		if(compute()==true) printf("Possible\n");
		else printf("Impossible\n");
	}
}
