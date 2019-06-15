#include<bits/stdc++.h>
using namespace std;

long long arr[]={ 	1, 1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563, 1622632573, 28091567595, 526858348381};

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",arr[n]);
	}
}
