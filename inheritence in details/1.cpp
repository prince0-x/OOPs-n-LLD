// single level inheritence
#include<bits/stdc++.h>
using namespace std;
class Animal
{
public:
	void eat()
	{
			cout<<"this animal eats food"<<endl;
	}
};
class Dog : public Animal
{
public:
	void bark()
	{
		cout<<"the dog barks"<<endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	#ifndef SPOJ
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    Dog myDog;
    myDog.eat();
    myDog.bark();
	return 0;
}