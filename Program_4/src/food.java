/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.util.Scanner;
//base class for dynamic binding
public class food
{
    protected toppings topping;
    //allocates the memory
    public food()
    {
        topping = new toppings();
    }
    //asks the user what they will be ordering
    public int menu()
    {
        //display to the screen and reads in data
        System.out.println("Hello Welcome to tacos & pizza would you like to order \n1: Pizza \n2: Tacos\n3: Both\n4: See Special");
        Scanner in = new Scanner(System.in) ;
        int value = in.nextInt();
        //1 means they want tacos and return a 1
        if(value == 1)
        {
            return 1;
        }
        else if(value == 2)
        {
            //they want tacos so return a 0
            return 0;
        }
        else if(value == 4)
        {
           return 4;
        }
        else
        {
            return 2;
        }
    }
    //function to be able to call them when doing dynamic binding
    public int display()
    {
        return 0;
    }
    //function to be able to call them when doing dynamic binding
    public int new_pizza()
    {
       return 0;
    }
    public int new_taco_order()
    {
       return 0;
    }
    public Pizza copy(Pizza my_copy)
    {
       return my_copy;
    }
    public Tacos copy(Tacos my_copy)
    {
       return my_copy;
    }
}
