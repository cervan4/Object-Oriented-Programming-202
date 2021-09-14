/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.util.Scanner;

public class b_node
{
    private b_node left;
    private b_node right;
    private l_node order;
    //default constructor
    private String name;
    private  int status;
    b_node()
    {
        left = null;
        right = null;
        name = null;
        status = 0;
    }
    //funtion to insert into the bst
    public static b_node insert(b_node root, String user)
    {
        Scanner in = new Scanner(System.in) ;
        //if its NULL that means to inset that data in
        if(root == null)
        {
            b_node tmp = new b_node();
            tmp.order = tmp.order.insert(tmp.order);
            tmp.name = String.valueOf(user);
            root = tmp;
            return root;
        }
        else if(user.equals(root.name))
        {
            root.order = root.order.insert(root.order);
            return root;
        }
        else //else that means that there is data already in the tree so it will just add to it and place it in the right order
        {
            //gets the length of their names and sorts it based on that
           int length = root.name.length();
           int length2 = user.length();
           //the new data is larger
           if(length2 >= length)
           {
               //traverses to the right node
                root.right = insert(root.right,user);
           }
           else
           {
               //traverse to the left node
               root.left = insert(root.left,user);
           }
            return root;
        }
    }
    //function will display all of the orders in the tree
    public void display_orders(b_node root)
    {
        //if null exits
       if(root == null) return;
       //traverses to left node
       display_orders(root.left);
       System.out.println("Order Summary for: " + root.name);
       root.order.display_all(root.order);
       //traverses to right node
       display_orders(root.right);
    }
    //sets root to null
    public static b_node delete_all(b_node root)
    {
        root = null;
        return root;
    }
    //retrieve function to get all orders with same name
    public b_node retrieve(b_node root, b_node source, String data)
    {
        if(source == null) return root;
        //checks if values are the same
        if(source.name.equals(data))
        {
            //makes new node and calls copy functions
            b_node tmp = new b_node();
            tmp.order = source.order.retrieve(source.order,tmp.order);
            tmp.name = String.valueOf(data);
            root = tmp;
            //goes to the left and right node
            root.left = retrieve(root.left,source.left,data);
            root.right = retrieve(root.right,source.right,data);
            return root;
        }
        else
        {
            //goes to the left and right
            retrieve(root,source.left,data);
            retrieve(root,source.right,data);
        }
        return root;
    }
    //Function to check order status
    public static int progress_bar(String user, b_node root)
    {
        //makes sure its not null
       if(root == null) return 0;
       //traverses to the left node
       progress_bar(user,root.left);
       //checks if the name the user entered matches the one thats in the order
       if(root.name.equals(user))
       {
           //adds one to the order
           root.status++;
           //if value is 1 then tells them they are only 35% there
          if(root.status == 1)
          {
              System.out.println("You're order is 35% done");
          }
          //if value is 2 then tells them they are only 70% there
          else if(root.status == 2)
          {
              System.out.println("You're order is 70% done");
          }
          //if value is 3 then tells them that their order is ready for pick up
          else if(root.status >= 3)
          {
              System.out.println("You're order is 100% done please come and pick it up");
          }
          return 0;
       }
       progress_bar(user,root.right);
       return 0;
    }
    //function to delete an indivual node
    public static b_node delete_order(b_node root, String user)
    {
        //checks if null
        if(root == null) return root;
        //checks if value is the same as the data passed in
        if(root.name.equals(user))
        {
            //calls funtion
            root = root.delete(root);
            return root;
        }
        //gets the length of both strings
        int length = root.name.length();
        int length2 = user.length();
        if(length2 >= length)
        {
            //calls function to traverse to right node
            root.right = delete_order(root.right,user);
        }
        else
        {
            //calls function to traverse to left node
            root.left = delete_order(root.left,user);
        }
        return root;
    }
    //function to actually delete the node
    public static b_node delete(b_node root)
    {
        if(root == null) return root;
        //if its only that one node and no children sets it to null
        if(root.left == null && root.right == null)
        {
           root = null;
        }
        //checks if left is null and right isnt
        else if(root.left == null && root.right != null)
        {
            //root gets value of right
           root = root.right;
        }
        else if(root.left != null && root.right == null)
        {
            //root gets value of left
            root = root.left;
        }
        else if(root.left != null && root.right != null)//this means that it has two children
        {
            //tmp node
            b_node tmp = root;
            //calls funtion to find on order
           b_node inorder = find_inorder(root.right);
           //gets the name value
           root.name = String.valueOf(inorder.name);
           //goes to the right node
           root.right = delete_order(root.right,root.name);
        }
        return root;
    }
    //fuction to find the in order succesor
    public static b_node find_inorder(b_node inorder)
    {
        //if null exits
        if(inorder == null) return inorder;
        //this means its found the inorder succesor
        if(inorder.left == null)
        {
           return inorder;//returns the inorder succesor
        }
       return find_inorder(inorder.left);//calls recursive function find in order
    }
    public static b_node display_special(b_node root)
    {
       return root;
    }
}
