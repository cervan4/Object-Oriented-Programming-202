/*
	Luis Cervantes Oropeza
	Program 1
	In this program the purpose was to make a OOP the task was to create a game that I'm calling WAR in this game the user's have the choice 
	to chose a character or they have the option to create their own as well they can see their match history and have battles with the other player as
	well you can check all of the characters stats.
	This programs is build hierarchys as well the use of dynamic binding to create the program.
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>
class weapon
{
	public:
		weapon();//constructor
		~weapon();//destructor
		int display();//funtion to display weapon
		int insert(char * data);//funtion to insert data of weapon to funtion 
	private:
		char * my_weapon;
};
class player//base class of hierarchy 
{
	 public:
		player();//constructors
		virtual ~player();//destructor
		//Vitrual funtions that all classes have in common 
		virtual int display();
		virtual int HP(player *& player_2);
		virtual int HP();
		virtual int strike(player *& player_2);
		virtual int strike(int health);
		virtual int insert(char * user, int HP, int strike, int armor,char * weapon);
		virtual int match_won();
		virtual int match_lost();
		//Vitrual funtions that all classes have in common 
		int set_name(char * user);//funtion to set the name of the player
	protected:
		char * name;
		
};

class attack_character : public player//derived class from player 
{
	public:
		attack_character();//constructor
		~attack_character();//destructor
		int insert(char * user, int HP, int strike, int defence,char * weapon);//funtion to insert into class
		int HP(player *& player_2);//wrapper funtion to add health to player
		int HP();//adds health to player
		int strike(player *& player_2);//wrapper funtion to attack player
		int strike(int user_health);//funtion to attack player
		int display();//funtion to display data 
		int match_won();//funtion to know player won match 
		int match_lost();//funtion to players when lost 
	protected:
		char * name;
		int health;
		int attack;
		int armor;

		int og_health;
		int og_attack;
		int og_armor;
		weapon my_weapon;
};
class defensive_character : public player//class thats derived from player 
{
	public:
		defensive_character();//constructor
		//destructor
		~defensive_character();
		//funtion to insert data 
		int insert(char * user, int HP, int strike, int defence,char * weapon);
		//wrapper funtion to add HP
		int HP(player *& player_2);
		//Adds value healh points 
		int HP();
		//wrapper funtion to attack
		int strike(player *& player_2);
		//attack funtion
		int strike(int user_health);
		//funtion to display 
		int display();
		//funtion to reset data when won 
		int match_won();
		//funtion to reset data when lost 
		int match_lost();
	protected:
		char * name;
		int health;
		int attack;
		int armor;	

		int og_health;
		int og_attack;
		int og_armor;
		weapon my_weapon;

};
class neutral_character : public player//class derived from player
{
	public:
		neutral_character();//constructor
		//destructor
		~neutral_character();
		//funtion to insert data 
		int insert(char * user, int HP, int strike, int defence,char * weapon);
		//wrapper funtion to add HP
		int HP(player *& player_2);
		//Adds value healh points 
		int HP();
		//wrapper funtion to attack
		int strike(player *& player_2);
		//attack funtion
		int strike(int user_health);
		//funtion to reset data when won 
		int display();
		//funtion to reset data when won 
		int match_won();
		//funtion to reset data when lost 
		int match_lost();
	protected:
		char * name;
		int health;
		int attack;
		int armor;	

		
		int og_health;
		int og_attack;
		int og_armor;
		weapon my_weapon;
};
