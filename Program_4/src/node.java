/*
    Luis Cervantes Oropeza
    Program 4&5
    The purpose of this program is to make an OOP program that is so that they can place an order and gets stored and
    to allow them choose from the specials that is random every time as well to allow them to make their own order
    as well in this program they can cancel all orders or cancel individual orders as well retrieve data.
    As well they can check the status of their order and know when its ready the data structures that are implemented is a Array of LLL as well a BST
*/
public class node
{
    private String data;
    private node next;
    //sets data to null
    public node()
    {
        next = null;
        data = null;
    }
    public node (String source)
    {
        //copys the data
        data = String.valueOf(source);
    }
    public static node insert(node head, String source)
    {
        //if NULL insets the first node
        if(head == null)
        {
            //allocates new node and head is equals to tmp
            node tmp = new node(source);
            head = tmp;
            return head;
        }
        else
        {
            //allocates new node and traverses to the end of the LLL and adds it there
            node tmp = new node(source);
            head = add_end(head,tmp);//calls funtion
            return head;
        }
    }
    //traverses to the end of the LLL and then adds to it
    public static node add_end(node head, node tmp)
    {
        if(head == null) return head;
        //at the end of the LLL
        if(head.next == null)
        {
            head.next = tmp;
            return head;
        }
        else
        {
            //calls function
            head.next = add_end(head.next,tmp);
            return head;
        }
    }
    //funtion to display everything inside the LLL
    public void display_all(node head)
    {
        if(head == null) return;
        System.out.println(head.data);
        display_all(head.next);
    }
}
