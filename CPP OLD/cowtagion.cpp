#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100000

int N;
int d[MAXN];

int main()
{
	cin >> N;
	int a,b;
	for(int i=0;i<N-1;i++)
	{
		cin >> a >> b;
		a--,b--;
		d[a]++, d[b]++;
	}
	int ans = N-1; // number of move events
	for(int i=0;i<N;i++)
		if(d[i] > 1 || i == 0)	// check that i is not leaf node in tree
		{
			int children = d[i];
			if(i!=0) children--;
			// compute ceil(log(children + 1))
			int log_children = 0;
			int pow = 1;
			while(pow < children + 1)
				log_children++, pow *= 2;
			ans += log_children;
		}
	cout << ans << '\n';
}