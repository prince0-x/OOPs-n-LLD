#include<iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
    cin >> a >> b;
	//lambda with parameter and capture a by value
	auto sum =[a](int c){return a+c;};
    // function call
    cout<<sum(5)<<endl;


    // capture a and b by reference
    auto update = [&a,&b](){a*=2;b*=3;};
    update();
    cout<<a<<" "<<b<<endl;

	return 0;
}