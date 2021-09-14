
/*
	Luis Cervantes Oropeza 
	Program 3
	The purpose of this program was to use the operatros and overload so like that we can compare classes and add a node with doing node++
	so the main pupose of the program was to use operator overloading to make it easier for ourself. As well this was alll done using OOP as well the program was to 
	essentially create a text editor that will fix your stntax erros and the text is read from a text file and a word from the user
*/
#include"data.h"
int main()
{
	//sets variables 
	int choice = 0;
	int done = 0;
	int flag = 0;
	document obj;

	highlight test;
	char * data = NULL;
	//sets variables 
	//while loop to loop over and over until they are done with the game
	while(done != 1)
	{
		//Displays the user what the editor can fix as well it displays them their options on what they can do so their memnu
		cout<<endl;
		cout<<"*"<<endl;
		cout<<"	THESE ARE THE THING THATS THE EDITOR CAN FIX: "<<endl;
		cout<<"	Will capatalize the first letter"<<endl;
		cout<<"	Will capatalize any i that is alone"<<endl;
		cout<<"	Will delete repeated words that are next to each other"<<endl;
		cout<<"*"<<endl;
		cout<<endl;
		cout<<"1: Fix errors on text"<<endl;
		cout<<"2: Insert text (This will correct your erros by default)"<<endl;
		cout<<"3: Display Text"<<endl;
		cout<<"4: Display highlighted words"<<endl;
		cout<<"10: EXIT PROGRAM"<<endl;
		cout<<"Enter in choice: ";
		//Displays the user what the editor can fix as well it displays them their options on what they can do so their memnu
		//reads in choice 
		cin>>choice;
		cin.ignore();
		switch(choice)
		{
			//It will fix the text that was read in from the file
			case 1:
				obj.fix();
				break;
			case 2:
				//inserts a new word/sentence into the array of LLL
				obj.insert();
				break;
			case 3:
				//uses the ostream operator to display everthing inside the array of LLL
				cout<<obj<<endl;
				break;
			case 4:
				//checks if the highlighted words have alerady been created 
				if(flag != 1)
				{
					//calls funtion to insert the highlighted words
					test.insert(data);
					//sets flag to 1
					flag = 1;
				}
				//calls funtion to display everything thats inside the 2-3 tree
				test.display_all();
				break;
			case 10:
				//will exit the loop and end the program 
				done = 1;
				break;
		}
	}
	if(data)
		delete [] data;
		data = NULL;

	//obj.delete_all();
	obj.delete_all_wrapper();
	
	return 0;
}
