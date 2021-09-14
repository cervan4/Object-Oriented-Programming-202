/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
import java.util.Scanner;

public class l_node
{
    private food[] their_order = new food[2];
    private food[] special = new food[2];
    private int special_order;
    private l_node next;

    public l_node() {
        their_order[0] = new Pizza();
        their_order[1] = new Tacos();
        int tmp = 0;
        //generates a random value
        double x = Math.random() * 100 % 5;
        //converter to an int
        tmp = (int) x;
        special[0] = new Pizza(tmp);
        //generates a random value
        x = Math.random() * 100 % 5;
        tmp = (int) x;
        special[1] = new Tacos(tmp);
        special_order = 0;
    }

    public static l_node insert(l_node head) {
        Scanner in = new Scanner(System.in);
        //allocates new memory
        l_node tmp = new l_node();
        int value = 0;
        //calls function and catches the value
        value = tmp.their_order[0].menu();
        //if value is one that means they want a pizza
        if (value == 1) {
            tmp.their_order[0].new_pizza();
        }
        else if (value == 0)//else they want a taco
        {
            //makes a new order
            tmp.their_order[1].new_taco_order();
        } else if (value == 4)//this means they want to see the special
        {
            //displays the special of the day
            System.out.println("THESE ARE THE SPECIALS OF THE DAY:");
            System.out.println("*****************---------*****************");
            //calls display function
            tmp.special[0].display();
            System.out.println("*****************---------*****************\n");
            System.out.println("*****************---------*****************");
            //calls display function
            tmp.special[1].display();
            System.out.println("*****************---------*****************\n");

            System.out.println();
            System.out.println("Would you like the special of the day? \n1:Pizza\n2:Tacos\n3: Both\n4:Neither");
            tmp.special_order = in.nextInt();
            //calls recursive call and takes them back to the menu
            if (tmp.special_order == 4) {
                insert(head);
            }
        } else//this means they want to order both things from the menu
        {
            //makes two orders of pizza and tacos
            tmp.their_order[0].new_pizza();
            tmp.their_order[1].new_taco_order();
        }
        //checks if there is data and if there is it gets added to the end of the list
        if (head == null)
        {
            head = tmp;
            return head;
        }
        else {
            head = add_end(head, tmp);//calls funtion
            return head;
        }
    }

    public static l_node add_end(l_node head, l_node tmp)
    {
        if (head == null) return head;
        //at the end of the LLL
        if (head.next == null) {
            head.next = tmp;
            return head;
        }
        else {
            //calls function
            head.next = add_end(head.next, tmp);
            return head;
        }
    }
    public void display_all(l_node head)
    {
        if(head == null) return;
        //traverses to left node
        System.out.println("*****************---------*****************");
        //calls funtions to display the data
        head.their_order[0].display();
        head.their_order[1].display();
        //checks if they wanted the special of the day
        if(head.special_order == 1)
        {
            head.special[0].display();
        }
        //checks if they wanted the special of the day
        else if(head.special_order == 2)
        {
            head.special[1].display();
        }
        else if(head.special_order == 3)
        {
            head.special[0].display();
            head.special[1].display();
        }
        System.out.println("*****************---------*****************\n");
        //calls recursive funtion
        display_all(head.next);
    }
    public l_node retrieve(l_node source, l_node head)
    {
        if(source == null) return head;
        //if head is null then it add a new node and if not it will add to the end of the list
        if(head == null)
        {
            l_node tmp = new l_node();
            //calls the copy funtions to copy the data
            tmp.their_order[0] = source.their_order[0].copy((Pizza) tmp.their_order[0]);
            //calls the copy funtions to copy the data
            tmp.their_order[1] = source.their_order[1].copy((Tacos) tmp.their_order[1]);
            //calls the copy funtions to copy the data
            tmp.special[0] = source.special[0].copy((Pizza) tmp.special[0]);
            //calls the copy funtions to copy the data
            tmp.special[1] = source.special[1].copy((Tacos) tmp.special[1]);
            tmp.special_order = source.special_order;
            head = tmp;
        }
        else
        {
            l_node tmp = new l_node();
            //calls the copy funtions to copy the data
            tmp.their_order[0] = source.their_order[0].copy((Pizza) tmp.their_order[0]);
            //calls the copy funtions to copy the data
            tmp.their_order[1] = source.their_order[1].copy((Tacos) tmp.their_order[1]);
            tmp.special[0] = source.special[0].copy((Pizza) tmp.special[0]);
            //calls the copy funtions to copy the data
            tmp.special[1] = source.special[1].copy((Tacos) tmp.special[1]);
            //calls the copy funtions to copy the data
            tmp.special_order = source.special_order;
            head.next = tmp;
        }
        head.next = retrieve(source.next,head.next);
        return head;
    }
}
