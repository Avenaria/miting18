//Создать базовый класс «Домашнее животное» и производные
//классы «Собака», «Кошка», «Попугай», «Хомяк».
//С помощью конструктора установить имя каждого животного и его характеристики.
//Реализуйте для каждого из классов функции :
//Sound – издает звук животного(пишем текстом в консоль);
//Show – отображает имя животного;
//Type – отображает название его подвида.

#include <string>
#include <iostream>
using namespace std;

class Animal
{
protected:
	string name;
public:
	Animal(string name)
		: name(name)
	{
	}

	virtual void Say() = 0;
	virtual void Nick() = 0;
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name)
	{
	}

	void Say()
	{
		cout << name << " speak gav-gav" << endl;
	}
	void Nick()
	{
		cout << name << " name Dog#1" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name)
	{
	}

	void Say()
	{
		cout << name << " speak may-may" << endl;
	}
	void Nick() ////override - проверка на опечатку
	{
		cout << name << " name Cat#1" << endl;
	}
};

class Bird : public Animal
{
public:
	Bird(string name) : Animal(name)
	{
	}

	void Say() override
	{
		cout << name << " speak kray-kray" << endl;
	}
	void Nick() override
	{
		cout << name << " name Bird#1" << endl;
	}
};


int main()
{
	/*Animal * animals[3] = {
		new Dog("Dog"),
		new Cat("Cat"),
		new Bird("Bird")
	};*/
	Dog dog("Dog");
	Cat cat("Cat");
	Bird bird("Bird");

	std::reference_wrapper<Animal> animals[3] = {
	  dog,
	  cat,
	  bird
	};


	for (int i = 0; i < 3; ++i)
	{
		((Animal&)(animals[i])).Say();
		((Animal&)(animals[i])).Nick();
		/*animals[i]->Say();
		animals[i]->Nick();*/
	}

	system("pause");
	return 0;
}