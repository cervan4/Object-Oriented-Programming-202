/*
    Luis Cervantes Oropeza
    Program 4 &5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Pizza extends food
{
   private Scanner in = new Scanner(System.in) ;
   private String topping;
   private String topping_2;
   private String crust;
   private String meat;
   private String meat_2;
   private String size;
   private String other;
   //constuctor to set data to NULL
   public Pizza()
   {
      topping = null;
      topping_2 = null;
      crust = null;
      meat = null;
      meat_2 = null;
      size = null;
      other = null;
   }
   public Pizza(int value)
   {

      Scanner sc = null;
      try
      {
         //gets the external data file that has all of the data
         File file;
         //checks from what file to read the data from so the data is different every time
         if(value < 3)
         {
            file = new File("src\\Pizza_special.txt");
         }
         else
         {
            file = new File("src\\Pizza_special_2.txt");
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
   private int read_from_file(String data)
   {
      Scanner sc = new Scanner(data);
      String data1;
      sc.useDelimiter(",");
      while (sc.hasNext())
      {
         //reads in data and inserts into the the string
         data1 = sc.next();
         meat = String.valueOf(data1);
         //reads in data and inserts into the the string
         data1 = sc.next();
         meat_2 = String.valueOf(data1);
         //reads in data and inserts into the the string
         data1 = sc.next();
         topping = String.valueOf(data1);
         //reads in data and inserts into the the string
         data1 = sc.next();
         topping_2 = String.valueOf(data1);
         //reads in data and inserts into the the string
         data1 = sc.next();
         crust = String.valueOf(data1);
         //reads in data and inserts into the the string
         data1 = sc.next();
         size = String.valueOf(data1);
         //reads in data and inserts into the the string
         data1 = sc.next();
         other = String.valueOf(data1);
      }
      sc.close();
      return 1;
   }
   //will display their entire order
   public int display()
   {
      //checks if there is data and if not exits
      if(crust == null && size == null && meat == null && meat_2 == null && other == null) return 0;
      System.out.println("This is your order for this pizza \n");
      //display if there is data
      if (crust != null) {
         System.out.println("Crust: " + crust);
      }
      //display if there is data
      if (size != null) {
         System.out.println("Size: " + size);
      }
      //display if there is data
      if (meat != null) {
         System.out.println("Meat 1: " + meat);
         System.out.println("Meat 2: " + meat_2);
      }
      //display if there is data
      if (meat != null) {
         System.out.println("Topping 1: " + topping);
         System.out.println("Topping 2: " + topping_2);
      }
      //display if there is data
      if (other != null)
      {
         System.out.println("Special request: " + other +"\n");
      }
      return 1;
   }
      //FUnction to make a new custom pizza
      public int new_pizza()
      {
      String data = null;
      //reads in data from the user copy data to the variable
      super.topping.display_sizes();
      System.out.println("Please enter size of pizza you want");
      data = in.nextLine();
      size = String.valueOf(data);
      System.out.println("\n");

      //reads in data from the user copy data to the variable
     //Chooses the type of crust that they want
      super.topping.display_crust();
      System.out.println("Please enter in the type of crust you want on your pizza \n");
      data = crust = in.nextLine();
      crust = String.valueOf(data);
      //Can choose a max of two meats on they pizza
      super.topping.display_pizza_meats();
      System.out.println("Please enter in the the meat you want on your pizza\n");
      data = in.nextLine();
      meat = String.valueOf(data);
      System.out.println("Please enter in the the second type of meat you want on your pizza and if none type in none \n");
      data = in.nextLine();
      meat_2 = String.valueOf(data);

         //reads in data from the user copy data to the variable
      //Choose the toppings that they want in their pizza and if none they type in none
      super.topping.display_veggies();
      System.out.println("Please enter the first topping you want on your pizza if none enter none \n");
      data = in.nextLine();
      topping = String.valueOf(data);
      System.out.println("Please enter the second topping you want on your pizza\n");
      data = in.nextLine();
      topping_2 = String.valueOf(data);

         //reads in data from the user copy data to the variable
      System.out.println("Please enter in any other request you want like another topping or something of your choice and if nothing type in none\n");
      data = in.nextLine();
      other = String.valueOf(data);
      //for loop to clear the screen
         //clears the screen
      for (int loop = 0; loop < 20; loop++) {
         System.out.println("\n");
      }
      //display();
      return 1;
   }
   public Pizza copy(Pizza my_copy)
   {
      //copys all do the pizza to the object thats passed in
      if(crust == null && size == null && meat == null && meat_2 == null && other == null) return my_copy;
      my_copy.meat = String.valueOf(meat);
      my_copy.meat_2 = String.valueOf(meat_2);
      my_copy.crust = String.valueOf(crust);
      my_copy.other = String.valueOf(other);
      my_copy.size = String.valueOf(size);
      my_copy.topping = String.valueOf(topping);
      my_copy.topping_2 = String.valueOf(topping_2);
      return my_copy;
   }
}
