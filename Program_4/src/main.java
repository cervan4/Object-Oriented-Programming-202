/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.util.Scanner;
public class main
{
    public static void main(String[] args)
    {
        //Sets variables
        Scanner in = new Scanner(System.in) ;
        int done = 0;
        int choice;
        orders tmp = new orders();
        orders retrieve = new orders();
        //this loop will loop until they decide that they are done with the program
        while(done != 1)
        {
            //Essentially the menu and shows them what they can do here
            System.out.println("Hello Welcome to Cervantes Tacos and Pizza where you can make your own custom Pizza/Tacos");
            System.out.println("1: Order food Pizza/Tacos");
            System.out.println("2: Check Food Status");
            System.out.println("3: Display all Orders");
            System.out.println("4: Delete all orders");
            System.out.println("5: Retrieve orders with same name");
            System.out.println("6: Cancel an order");
            System.out.println("10: Exit Program");
            System.out.print("Enter in choice *number*: ");
            //reads in choice from the user
            choice = in.nextInt();
            //switch statement to go to a case
            switch(choice)
            {
                case 1:
                        //to get a new order
                        //calls function to order food
                        tmp.order();
                        for (int loop = 0; loop < 20; loop++) {
                            System.out.println("\n");
                        }
                        break;
                case 2:
                        for (int loop = 0; loop < 5; loop++) {
                            System.out.println("\n");
                        }
                        tmp.status();
                        for (int loop = 0; loop < 5; loop++) {
                            System.out.println("\n");
                        }
                    break;
                case 3:
                        //calls function to display all
                        tmp.display();
                        for (int loop = 0; loop < 5; loop++) {
                            System.out.println("\n");
                        }
                        break;
                case 4:
                        //calls funtion to delete everthing inside the bst
                        tmp.delete_all_orders();
                        for (int loop = 0; loop < 20; loop++) {
                            System.out.println("\n");
                        }
                    break;
                case 5:
                        //calls function to retrieve data that is under the same name
                        retrieve = tmp.retrieve(retrieve,tmp);
                        for (int loop = 0; loop < 20; loop++) {
                            System.out.println("\n");
                        }
                        retrieve.display();
                    //retrieve.display();
                        break;
                case 6:
                        tmp.delete_order();
                        for (int loop = 0; loop < 20; loop++) {
                            System.out.println("\n");
                        }
                    break;
                case 10:
                    //exits the loop
                    done = 1;
                        break;
            }
        }
    }
}
