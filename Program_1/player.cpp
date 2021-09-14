/*
	Luis Cervantes Oropeza
	Program 1
	In this program the purpose was to make a OOP the task was to create a game that I'm calling WAR in this game the user's have the choice 
	to chose a character or they have the option to create their own as well they can see their match history and have battles with the other player as
	well you can check all of the characters stats.
	This programs is build hierarchys as well the use of dynamic binding to create the program.
*/
#include"player.h"
using namespace std;

//Constructor to set data to zero or equal to zero 
weapon::weapon() : my_weapon(NULL) { }

//Destructor to realease dynamic memory
weapon::~weapon() 
{
	//checks if there is data and if so dealocates it 
	if(my_weapon)
		delete [] my_weapon;
}
int weapon::display()
{
	//Dislays the weapon that they have 
	cout<<"Weapon: "<<my_weapon<<endl;
}
int weapon::insert(char * data)// funtion to insert the weapon into the class
{
	//allocates memory and copys data that was passed in 	
	my_weapon = new char [strlen(data) +1];
	strcpy(my_weapon,data);
}
//Constructor to set data to zero or equal to zero 
player::player() : name(NULL) { }

//Destructor to realease dynamic memory
player::~player()
{
	//checks if there is data and if so dealocates it 
	if(name)
		delete [] name;
}
//virtual funtions 
int player::display() { }

int player::HP(player *& player_2) { }

int player::HP() { }

int player::strike(player *& player_2) { }

int player::strike(int health) { }

int player::insert(char * user, int HP, int strike, int armor, char * weapon) { }

int player::match_won() { }

int player::match_lost() { }
//virtual funtions 

int player::set_name(char * user)
{
	//allocates memory and copys data that was passed in 	
	name = new char [strlen(user) +1];
	strcpy(name,user);
	cout<<"Welcome "<<name<<" to WAR"<<endl;
}

//Constructor to set data to zero or equal to zero & to read in data from the external data file 
attack_character::attack_character() : name(NULL), health(0),attack(0),armor(0)
{
	/*
		The data is read in from external data file and sets the variables to the values that were read in from 
		the external data files 
	*/
	char tmp[500];
	ifstream file_ins("attack_character.txt");
	if(file_ins)// checks if file exist 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			name = new char[strlen(tmp) + 1];//allocates memory 
			strcpy(name,tmp);//copys data 

			file_ins >> health;//gets value
			file_ins.ignore();

			file_ins >> attack;//gets value
			file_ins.ignore();

			file_ins >> armor;//gets value 
			file_ins.ignore();

			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');

			char * data;

			data = new char[strlen(tmp) + 1];//allocates memory 
			strcpy(data,tmp);//copys data 
			my_weapon.insert(data);//inserts into weapon 

			
			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');
		}

         }
	//Sets values
	og_health = health;
	og_armor = armor;
	og_attack = attack;
	//sets values 
}

//Destructor to realease dynamic memory
attack_character::~attack_character()
{
	if(name)//checks if there is data and if so deletes the data 
		delete [] name;

	health = 0;
	attack = 0;
	armor = 0;
}
//Gets data from the user and sets the variables that are passed in to the variables from the class
int attack_character::insert(char * user, int HP, int strike, int defence,char * weapon)
{
	//allocates memory & copys data as well it sets the variables to the values that were passed in 
	name = new char [strlen(user) +1];
	strcpy(name,user);
	health = HP;
	attack = strike;
	armor = defence;
	my_weapon.insert(weapon);// calls funtion to set weapon in the weapon class 
}
//This funtion passes in a player  class type and gives the player extra health 
int attack_character::HP(player *& player_2)
{
	cout<<"You have receive extra health"<<endl; 
	player_2->HP();
}
// gives extra health of 10 points 
int attack_character::HP()
{
	health += 10;
}
//passes in a player class type and player 2 loses health points here 
int attack_character::strike(player *& player_2)
{
	player_2->strike(attack);// calls funtion to pass in the damage that it will take 
}
//funtion to attack and here health and armor is deducted 
int attack_character::strike(int user_attack)
{
	// checks if armor is greater than 0
	if(armor > 0)
	{
		//Reduces that health points of the armor 
		cout<<"Your armor value before the attack: "<<armor<<endl;
		armor -= user_attack;
		//if armor is less than 0 then the health points gets affected and this means there is no armor left 
		if(armor <= 0)
		{
			//health is deducted based on the negative or zero points from the armor
			cout<<"This is your health before the attack: "<<health<<endl;
			health += armor;
			// checks if heatlth is less than zero and is so player 2 loses the match 	
			if(health <= 0)
			{
				match_lost();	
				return 0;
			}
			//ele this means there there is still health so it deducts points from health 
			else
			{
				//if armor is less than zero that means there is no armor left 
				if(armor <= 0)
				{
					cout<<"You have zero armor left =("<<endl;
				}
				cout<<"This is your health after the attack: "<<health<<endl;
				return 1;
			}

		}
		cout<<"Your armor value after the attack: "<<armor<<endl;
	}
	// else there is zero armor and the attack wll go directy to the health 
	else
	{
		cout<<"This is your health before the attack: "<<health<<endl;
		health -= user_attack;
		//health is less than 0 then match is lost 
		if(health <= 0)
		{
			match_lost();	
			return 0;
		}
		//This means there is still health left 
		else
		{
			cout<<"This is your health after the attack: "<<health<<endl;
			return 1;
		}

	}
}
//The funtion displays the characters stats and info 
int attack_character::display()
{
	cout<<"Attack character Stats"<<endl;
	cout<<endl;
	cout<<"Name of character: "<<name<<endl;
	cout<<"Health: "<<health<<endl;
	cout<<"Attack: "<<attack<<endl;
	cout<<"Armor: "<<armor<<endl;
	//calls funtion to display weapon 
	my_weapon.display();	
	cout<<endl;
	
}
//funtion to determine that the match was been won 
int attack_character::match_won()
{
	//Since match has been win value are set back to default
	// and are added a little bit of a boost since they won 
	health = 5 + og_health;
	attack = 10 + og_attack;
	armor = 3 + og_armor;

	og_health = health;
	og_attack = attack;
	og_armor = armor;
}
//funtion to say that match has been lost and values are set back to original values 
int attack_character::match_lost()
{
	//VAlues are set back to original and stats get lower since player
	//lost the match 
	health = og_health;
	health -= 2;

	attack = og_attack;
	attack -= 5;

	armor = og_armor;
	armor -= -2;

	og_health = health;
	og_attack = attack;
	og_armor = armor;
}
//Constructor to set data to zero or equal to zero & to read in data from the external data file 
defensive_character::defensive_character() : name(NULL), health(0),attack(0),armor(0)
{
	/*
		The data is read in from external data file and sets the variables to the values that were read in from 
		the external data files 
	*/
	char tmp[500];
	ifstream file_ins("defensive_character.txt");
	if(file_ins)//Checks if file exist 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			name = new char[strlen(tmp) + 1];//allocates memory 
			//copys data 
			strcpy(name,tmp);
				
			//gets data from the external data file
			file_ins >> health;
			file_ins.ignore();

			//gets data from the external data file
			file_ins >> attack;
			file_ins.ignore();

			//gets data from the external data file
			file_ins >> armor;
			file_ins.ignore();

			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');

			char * data;

			data = new char[strlen(tmp) + 1];//allocates memory 
			strcpy(data,tmp);//copys data
			my_weapon.insert(data);

			
			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');
		}

         }
	og_health = health;
	og_armor = armor;
	og_attack = attack;
}

//Destructor to realease dynamic memory
defensive_character::~defensive_character()
{
	//Checks if there is data and if so deletes it 
	if(name)
		delete [] name;

	health = 0;
	attack = 0;
	armor = 0;
}
//Gets data from the user and sets the variables that are passed in to the variables from the class
int defensive_character::insert(char * user, int HP, int strike, int defence,char * weapon)
{
	//allocates memory & copys data as well it sets the variables to the values that were passed in 
	name = new char [strlen(user) +1];
	strcpy(name,user);
	health = HP;
	attack = strike;
	armor = defence;
	my_weapon.insert(weapon);
}
//This funtion passes in a player  class type and gives the player extra health 
int defensive_character::HP(player *& player_2)
{
	cout<<"Player 2 you have receive extra health"<<endl; 
	player_2->HP();
}
// gives extra health of 10 points 
int defensive_character::HP()
{
	health += 10;
}
//passes in a player class type and player 2 loses health points here 
int defensive_character::strike(player *& player_2)
{
	player_2->strike(attack);
}
//funtion to attack and here health and armor is deducted 
int defensive_character::strike(int user_attack)
{
	// checks if armor is greater than 0
	if(armor > 0)
	{
		//Reduces that health points of the armor 
		cout<<"Your armor value before the attack: "<<armor<<endl;
		armor -= user_attack;
		//if armor is less than 0 then the health points gets affected and this means there is no armor left 
		if(armor <= 0)
		{
			//health is deducted based on the negative or zero points from the armor
			cout<<"This is your health before the attack: "<<health<<endl;
			health += armor;
			// checks if heatlth is less than zero and is so player 2 loses the match 	
			if(health <= 0)
			{
				match_lost();	
				return 0;
			}
			//else this means there there is still health so it deducts points from health 
			else
			{
				//if armor is less than zero that means there is no armor left 
				if(armor <= 0)
				{
					cout<<"You have zero armor left =("<<endl;
				}
				cout<<"This is your health after the attack: "<<health<<endl;
				return 1;
			}

		}
		cout<<"Your armor value after the attack: "<<armor<<endl;
	}
	// else there is zero armor and the attack wll go directy to the health 
	else
	{
		cout<<"This is your health before the attack: "<<health<<endl;
		health -= user_attack;
		//health is less than 0 then match is lost 
		if(health <= 0)
		{
			match_lost();	
			return 0;
		}
		//This means there is still health left 
		else
		{
			cout<<"This is your health after the attack: "<<health<<endl;
			return 1;
		}
	}

}
//The funtion displays the characters stats and info 
int defensive_character::display()
{
	cout<<"Defensive character Stats"<<endl;
	cout<<endl;
	cout<<"Name of character: "<<name<<endl;
	cout<<"Health: "<<health<<endl;
	cout<<"Attack: "<<attack<<endl;
	cout<<"Armor: "<<armor<<endl;
	//calls funtion to display weapon 
	my_weapon.display();	
	cout<<endl;
}
//funtion to determine that the match was been won 
int defensive_character::match_won()
{
	//Since match has been win value are set back to default
	// and are added a little bit of a boost since they won 
	health = 5 + og_health;
	attack = 10 + og_attack;
	armor = 3 + og_armor;

	og_health = health;
	og_attack = attack;
	og_armor = armor;
}
//funtion to say that match has been lost and values are set back to original values 
int defensive_character::match_lost()
{
	//VAlues are set back to original and stats get lower since player
	//lost the match 
	health = og_health;
	health -= 2;

	attack = og_attack;
	attack -= 5;

	armor = og_armor;
	armor -= -2;
	
	og_health = health;
	og_attack = attack;
	og_armor = armor;
}


//Constructor to set data to zero or equal to zero & to read in data from the external data file 
neutral_character::neutral_character() : name(NULL), health(0),attack(0),armor(0)
{
	/*
		The data is read in from external data file and sets the variables to the values that were read in from 
		the external data files 
	*/
	char tmp[500];
	ifstream file_ins("neutral_character.txt");
	if(file_ins)//Checks if there is a file 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			name = new char[strlen(tmp) + 1];//allocates memory 
			strcpy(name,tmp);

			//gets data from external file
			file_ins >> health;
			file_ins.ignore();

			//gets data from external file
			file_ins >> attack;
			file_ins.ignore();

			//gets data from external file
			file_ins >> armor;
			file_ins.ignore();

			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');
			
			char * data;

			data = new char[strlen(tmp) + 1];//allocates memory 
			strcpy(data,tmp);//copys data 
			my_weapon.insert(data);//calls funtion to insert data 

			
			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');
		}

         }
	//Sets data 
	og_health = health;
	og_armor = armor;
	og_attack = attack;
}

//Destructor to realease dynamic memory
neutral_character::~neutral_character()
{
	//Checks if there is data and if so deletes it 
	if(name)
		delete [] name;

	health = 0;
	attack = 0;
	armor = 0;
}
//Gets data from the user and sets the variables that are passed in to the variables from the class
int neutral_character::insert(char * user, int HP, int strike, int defence,char * weapon)
{
	//allocates memory & copys data as well it sets the variables to the values that were passed in 
	name = new char [strlen(user) +1];
	strcpy(name,user);
	health = HP;
	attack = strike;
	armor = defence;
	my_weapon.insert(weapon);
}
//This funtion passes in a player  class type and gives the player extra health 
int neutral_character::HP(player *& player_2)
{
	cout<<"Player 2 you have receive extra health"<<endl; 
	player_2->HP();
}
// gives extra health of 10 points 
int neutral_character::HP()
{
	health += 10;
}
//passes in a player class type and player 2 loses health points here 
int neutral_character::strike(player *& player_2)
{
	player_2->strike(attack);
}
//funtion to attack and here health and armor is deducted 
int neutral_character::strike(int user_attack)
{
	// checks if armor is greater than 0
	if(armor > 0)
	{
		cout<<"Your armor value before the attack: "<<armor<<endl;
		armor -= user_attack;
		//if armor is less than 0 then the health points gets affected and this means there is no armor left 
		if(armor <= 0)
		{
			//health is deducted based on the negative or zero points from the armor
			cout<<"This is your health before the attack: "<<health<<endl;
			health += armor;
			// checks if heatlth is less than zero and is so player 2 loses the match 	
			if(health <= 0)
			{
				match_lost();	
				return 0;
			}
			//else this means there there is still health so it deducts points from health 
			else
			{
				//if armor is less than zero that means there is no armor left 
				if(armor <= 0)
				{
					cout<<"You have zero armor left =("<<endl;
				}
				cout<<"This is your health after the attack: "<<health<<endl;
				return 1;
			}

		}
		cout<<"Your armor value after the attack: "<<armor<<endl;
	}
	// else there is zero armor and the attack wll go directy to the health 
	else
	{
		cout<<"This is your health before the attack: "<<health<<endl;
		health -= user_attack;
		//health is less than 0 then match is lost 
		if(health <= 0)
		{
			match_lost();	
			return 0;
		}
		//This means there is still health left 
		else
		{
			cout<<"This is your health after the attack: "<<health<<endl;
			return 1;
		}
	}


}
//The funtion displays the characters stats and info 
int neutral_character::display()
{
	cout<<"Neutral character Stats"<<endl;
	cout<<endl;
	cout<<"Name of character: "<<name<<endl;
	cout<<"Health: "<<health<<endl;
	cout<<"Attack: "<<attack<<endl;
	cout<<"Armor: "<<armor<<endl;
	//calls funtion to display weapon 
	my_weapon.display();	
	cout<<endl;
}
//funtion to determine that the match was been won 
int neutral_character::match_won()
{
	//Since match has been win value are set back to default
	// and are added a little bit of a boost since they won 
	health = 5 + og_health;
	attack = 10 + og_attack;
	armor = 3 + og_armor;

	og_health = health;
	og_attack = attack;
	og_armor = armor;
}
//funtion to say that match has been lost and values are set back to original values 
int neutral_character::match_lost()
{
	//VAlues are set back to original and stats get lower since player
	//lost the match 
	health = og_health;
	health -= 2;

	attack = og_attack;
	attack -= 5;

	armor = og_armor;
	armor -= -2;

	og_health = health;
	og_attack = attack;
	og_armor = armor;
}
