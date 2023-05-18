#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;

int main()
{
	freopen("input.txt","w",stdout);
	srand(time(NULL));
	int p=pow(2,20)-1;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			cout<<rand()<<" ";
		}
		cout<<endl;
	}
	return 0;
}