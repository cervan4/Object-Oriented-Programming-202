public class value
{
    private node head = null;
    public int insert()
    {
        head = head.insert(head) ;
        return 0;
    }
    public int display_all()
    {
       head.display_all(head);
       return 0;
    }
}
