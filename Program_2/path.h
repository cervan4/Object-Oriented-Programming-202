/*
	Luis Cervantes Oropeza
	Program 2
	In this program we are focused on the dynamic binding aspect of the code and the use of RTTI
	in this program we create a laser tag game where we use an array of DLL where every node holds a base class pointer 
	that allows us to create any type of a derived class(point) we are allowed to do this due to dynamic binding
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>

class path // base class of the hierachy 
{
	public:
		// Constructor 
		path();
		path(char * data);
		//Pure virtual destructor
		virtual ~path() = 0;
		//pure virtual display funtion;
		virtual int display() = 0;
		// pure virtual option class
		virtual int option() = 0;
		//Function to give damage to other team
		virtual int attack();
		//funtion to pass in character type 
		virtual int attack(class player & bot);
		//pure stun funtion 
		virtual int stun() = 0;
		//retrieve funtion
		virtual int retriev(path *& head);	
	protected:
		char * name;
		
		
};
class obstacle : public path// class derived from path
{
	public:
		// Constructor 
		obstacle();
		//construtor with argument 
		obstacle(char * data);
		//destructor
		~obstacle();
		//display funtion 
		int display();
		//option funtion 
		int option();
		//stun funtion
		int stun();

	private:
		//variable that holds what type of variable it is 
		char * barrier;
};

class home_base : public path// class derived from path
{
	public:
		//constructor
		home_base();
		//constructor with arguments 
		home_base(char * data);
		//destructor
		~home_base();
		//display funtion 
		int display();
		//option funtion 
		int option();
		//stun funtion
		int stun();

	private:
		char * base;
};

class weapon// weapon class
{
	public:
		//constructor
		weapon();
		//constructor with arguments 
		weapon(char * input);
		//destructor
		~weapon();
		//display funtion 
		int display();
	private:
		char * my_weapon;
};

class player : public path// class derived from path
{
	public:
		//constructor
		player();
		//destructor
		~player();
		//display funtion 
		int display();
		//option funtion
		int option();
		//attack funtion 
		int attack(player & bot);
		//attack funtion 
		int attack();
		//stun funtion
		int stun();
		//calls funtion to 
		int my_bullets();
		//retriev funtion 	
		int retriev(path *& head);

	private:
		int health;
		int bullets;
		weapon laser_gun;
};
