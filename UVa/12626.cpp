#include<bits/stdc++.h>
using namespace std;

int tot[150];

int main()
{
	int tc;
	cin>>tc; getchar();
	string in;
	while(tc--)
	{
		memset(tot,0,sizeof(tot));
		getline(cin,in);
		int len = in.length();
		for(int a=0;a<len;a++)
		{
			tot[in[a]]++;
		}
		int maxi = 1e+9;
		//M,A3,R2,G,I,T
		maxi = min(maxi,tot['M']);
		maxi = min(maxi,tot['A']/3);
		maxi = min(maxi,tot['R']/2);
		maxi = min(maxi,tot['G']);
		maxi = min(maxi,tot['I']);
		maxi = min(maxi,tot['T']);
		cout<<maxi<<endl;
	}
}
