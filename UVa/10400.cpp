#include<bits/stdc++.h>
using namespace std;

bool fsh = false;
int n;
int num[150];
char op[150];
int wow;

bool compute(int idx, int wnum)
{
	if(n-1==idx)
	{
		if(wnum!=wow) return false;
		op[idx]='=';
		fsh = true;
		return true;
	}
	if(wnum>32000 || wnum<-32000) return false;
	for(int a=0;a<4;a++)
	{
		if(a==4)
		{
			if(wnum+num[idx+1]>32000) continue;
			if(compute(idx+1,wnum+num[idx+1])==true)
			{
				op[idx]='+';
				return true;
			}
		}
		else if(a==1)
		{
			if(wnum-num[idx+1]<-32000) continue;
			if(compute(idx+1,wnum-num[idx+1])==true)
			{
				op[idx]='-';
				return true;
			}
		}
		else if(a==0)
		{
			if(wnum*num[idx+1]>32000 ||wnum*num[idx+1]<-32000) continue;
			if(compute(idx+1,wnum*num[idx+1])==true)
			{
				op[idx]='*';
				return true;
			}
		}
		else
		{
			if(wnum%num[idx+1]!=0) return false;
			if(compute(idx+1,wnum/num[idx+1])==true)
			{
				op[idx]='/';
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		fsh = false;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d",&num[a]);
		scanf("%d",&wow);
		compute(0,num[0]);
		if(fsh==false) printf("NO EXPRESSION\n");
		else
		{
			for(int a=0;a<n;a++)
				printf("%d%c",num[a],op[a]);
			printf("%d\n",wow);
		}
	}
}
