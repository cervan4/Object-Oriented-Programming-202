public class node
{

    private int data;
    private node next;
    node(int value)
    {
        data = value;
        next = null;
    }
    public static node insert(node head)
    {
        if(head == null)
        {
            node tmp = new node(69);
            head = tmp;
            return head;
        }
        else
        {
            node tmp = new node(69);
            head = add_end(head,tmp);
            return head;
        }
    }
    public static node add_end(node head, node tmp)
    {
        if(head == null) return head;

        if(head.next == null)
        {
            head.next = tmp;
            return head;
        }
        else
        {
            head.next = add_end(head.next,tmp);
            return head;
        }
    }
    public void display_all(node head)
    {
        if(head == null) return;
        System.out.println(head.data);
        display_all(head.next);
    }
}
