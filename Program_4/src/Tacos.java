/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Tacos extends food
{
    private Scanner in = new Scanner(System.in) ;
    private String meat;
    private String sauce;
    private String topping;
    private int amount = 0;
    //constructor to set data to null
    public Tacos()
    {

        meat = null;
        sauce = null;
        topping = null;
        amount = 0;
    }
    public Tacos(int value)
    {
        Scanner sc = null;
        try
        {
            //gets the external data file that has all of the data
            File file;
            //checks what value was passed in and reads in the data based on that
            if(value < 3)
            {
                file = new File("src\\Special.txt");
            }
            //checks what value was passed in and reads in the data based on that
            else
            {
                file = new File("src\\Special_2.txt");
            }
            sc = new Scanner(file);
            //until theres not a next line
            while (sc.hasNextLine())
            {
                String data = sc.nextLine();
                read_from_file(data);
            }
        }
        catch (IOException exp)
        {
            exp.printStackTrace();
        }
    }
    int read_from_file(String data)
    {
        Scanner sc = new Scanner(data);
        String data1,data2,data3,data_4;
        //makes the stopping condition the ,
        sc.useDelimiter(",");
        //until it had reached the end of the file
        while (sc.hasNext())
        {
            //reads in data and inserts it into the string
            data1 = sc.next();
            meat = String.valueOf(data1);
            //reads in data and inserts it into the string
            data2 = sc.next();
            sauce = String.valueOf(data2);
            //reads in data and inserts it into the string
            data3 = sc.next();
            topping = String.valueOf(data3);
            amount = sc.nextInt();
        }
        sc.close();
        return 1;
    }
    //display the data
    public int display()
    {
        //Displays all of the data
        //checks if there is actually data
        if(meat == null && sauce == null && topping == null) return 0;
        System.out.println("This your Order Summary for Tacos: \n");
        System.out.println("Meat: " + meat);
        System.out.println("Sauce: " + sauce);
        System.out.println("Topping: " + topping);
        System.out.println("Number of tacos ordered: " + amount);
        return 1;
    }
    public int new_taco_order()
    {
        String data = null;
        //reads in data from the user copy data to the variable
        //Get to choose what meat they want on their tacos
        super.topping.display_tacos_meats();
        System.out.println("Please enter the meat you want on your tacos");
        data = in.nextLine();
        meat = String.valueOf(data);

        //reads in data from the user copy data to the variable
        //Get to choose what veggies they want on their tacos
        super.topping.display_veggies();
        System.out.println("Please enter the type of toppings you want on your tacos");
        data = in.nextLine();
        topping = String.valueOf(data);

        //reads in data from the user copy data to the variable
        //Get to choose what sauce they want on their tacos
        super.topping.display_sauces();
        System.out.println("Please enter the type of sauce you want on your tacos");
        data = in.nextLine();
        sauce = String.valueOf(data);
        //reads in data from the user copy data to the variable
        //Enters how many tacos they want of each
        System.out.println("Please enter the amount of tacos you want");
        int number = 0;
        number = in.nextInt();
        amount = Integer.valueOf(number);

        for (int loop = 0; loop < 20; loop++) {
            System.out.println("\n");
        }
        //display();
        return 1;
    }
    public Tacos copy(Tacos my_copy)
    {
        //copys all do the pizza to the object thats passed in and returns it
        if(meat == null && sauce == null && topping == null) return my_copy;
       my_copy.meat = String.valueOf(meat);
       my_copy.topping = String.valueOf(topping);
       my_copy.amount = Integer.valueOf(amount);
       my_copy.sauce = String.valueOf(sauce);
       return my_copy;
    }

}
