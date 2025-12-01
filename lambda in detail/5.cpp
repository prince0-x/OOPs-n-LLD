#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double x,y;
	cin>>x>>y;
	// lambda with return type
	auto divide =[](double a, double b)->double{
		if(b!=0)return a/b;
		else return 0.0;
	};
    cout<<divide(x,y)<<endl;
	return 0;
}