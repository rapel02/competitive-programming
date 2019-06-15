#include<bits/stdc++.h>
using namespace std;

queue<int> q;

double re[150];

double area(double a,double b,double c)
{
	double s = (a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool istriangle(double a,double b,double c)
{
	if(a*a + b*b < c*c) return false;
	if(a*a + c*c < b*b) return false;
	if(b*b + c*c < a*a) return false;
	return true;
}

int main()
{
	int n,ntc;
	cin>>n;
	for(int a=0;a<n;a++) cin>>re[a];
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{
		double aa,bb,cc;
		cin>>aa>>bb>>cc;
		double ra = 0;
		if(istriangle(aa,bb,cc) == true) 
		{
			ra = (aa*bb*cc)/(2*area(aa,bb,cc));
			//printf("Its triangle\n");
		}
		else ra = max(aa,max(bb,cc));
		//cout<<ra<<endl;
		for(int a=0;a<n;a++)
		{
			if(ra<=re[a]) q.push(a);
		}
		printf("Peg %c will ",tc+'A'-1);
		if(q.size()==0) printf("not fit into any holes\n");
		else
		{
			printf("fit into hole(s):");
			while(!q.empty())
			{
				printf(" %d",q.front() + 1);
				q.pop();
			}
			printf("\n");
		}
	}
}
