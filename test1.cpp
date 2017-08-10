#include <iostream>
#include <string>

using namespace std;
class Animal{ 
	protected: 
		Animal(){} 
	public:
		virtual string eat() = 0;
};

class Dog: public Animal{
	public:
		Dog():eat_return("Eats bone\n"){}
		virtual string eat(){
			return  eat_return;
		}

	private:
		string eat_return;
};

class Cat: public Animal{
	public:
		Cat():eat_return("Eats fish\n"){}
		virtual string eat(){
			return  eat_return;
		}

	private:
		string eat_return;
};

int main(){
	Dog dog;
	Cat cat;
	Animal animal;

	Animal *pAnimal = &dog;
	cout <<  pAnimal->eat();

	pAnimal = &cat;

	cout << pAnimal->eat();
}


