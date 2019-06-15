#include<bits/stdc++.h>
using namespace std;

char arr[20][10]={" ",".,?\"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int pr[1500];
int tp[1500];

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int a=0;a<n;a++) cin>>pr[a];
		for(int b=0;b<n;b++)
		{
			cin>>tp[b];
			cout<<arr[pr[b]][tp[b]-1];
		}
		cout<<endl;
	}
}
