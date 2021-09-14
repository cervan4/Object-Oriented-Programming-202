/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.util.Scanner;

public class orders
{
    //sets up variables that will be needed
    private b_node root;
    private Scanner in = new Scanner(System.in) ;
    //constructor
    public orders()
    {
       root = null;
    }

    //function to display everything inside the bst so all of the orders
    public int display()
    {
        if(root == null) return 0;
        root.display_orders(root);
       return 0;
    }
    //fuction to actuall place the order and choose what they want to create
    public int order()
    {
        String name;
        System.out.println("Please enter in your name for the order:");
        String data = null;
        //reads in data
        data = in.nextLine();
        //sets the name to all uppercase
        data = data.toUpperCase();
        //name get the vakue of data
        name = String.valueOf(data);
        //calls funtion to insert into the bst
        root = root.insert(root,name);
        return 0;
    }
    //will delete everything inside of the bst
    public void delete_all_orders()
    {
        //sets root to NULL since theres a garbage collector
        root = null;
    }
    //funtion to retrieve all of the order that have the same order name
    public orders retrieve(orders obj, orders source)
    {
        if(source.root == null) return obj;
        String data;
        System.out.println("Please enter in name of the order (will retrieve orders with same name");
        //reads in name
        data = in.nextLine();
        //sets name to all uppercase
        data = data.toUpperCase();
        //calls function to retrive the data
        obj.root = source.root.retrieve(obj.root,source.root,data);
        return obj;
    }
    public int status()
    {
        if(root == null) return 0;
        String data;
        System.out.println("Please enter in name of the order (will retrieve orders with same name");
        //reads in name
        data = in.nextLine();
        //sets name to all uppercase
        data = data.toUpperCase();
        root.progress_bar(data,root);
        return 0;
    }
    int delete_order()
    {
        if(root == null) return 0;
        String data;
        System.out.println("Please enter in name of the order you want to cancel *name of the person of who places the order*");
        //reads in name
        data = in.nextLine();
        //sets name to all uppercase
        data = data.toUpperCase();
        root = root.delete_order(root,data);
        return 0;
    }
    int order_recommended()
    {
        System.out.println("These are the specials of the day:");
        return 0;
    }
}
