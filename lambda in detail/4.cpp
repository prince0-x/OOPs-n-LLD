#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	std::vector<int>arr={1, 2, 3, 4, 5};
	for_each(arr.begin(),arr.end(),[](int &n){ n*=n;});
	for(auto a:arr)
	{
		cout<<a<<" \n"[a==arr.back()];
	}

	return 0;
}