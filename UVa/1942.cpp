#include<bits/stdc++.h>
using namespace std;

bool ceksqr(int a)
{
	int b = sqrt(a);
	if(b*b!=a) return false;
	return true;
}

int main(){
	while(1)
	{
		int vt,vo;
		scanf("%d %d",&vt,&vo);
		if(vt==vo && vo==0) break;
		double ans = 0;
		int tot = 0;
		for(int a=1;a<=vt;a++)
		{
			if(vt<=vo*a) break;
			if(vt%a==0)
			{
				//if(ceksqr(vt/a-vo)==false) continue;
				double temp = 0.3* a * sqrt(vt/a - vo);
				cout<<a <<" "<<temp<<endl;
				if(temp>ans)
				{
					ans = temp;
					tot = a;
				}
			}
		}
		printf("%d\n",tot);
	}
}
