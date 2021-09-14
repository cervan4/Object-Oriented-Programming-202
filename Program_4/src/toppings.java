import java.io.File;
import java.io.IOException;
import java.util.Scanner;
public class toppings
{
    //array of LLL
    private node [] head;
    public toppings()
    {
        head = new node [6] ;
      Scanner sc = null;
      try
      {
          //gets the external data file that has all of the data
          //File file = new File("C:\\Users\\luisc\\Documents\\Computer Science\\202\\Fall 2019\\Program_4\\src\\Veggies.txt");
          File file = new File("src\\Veggies.txt");
          sc = new Scanner(file);
          int loop =0;
          //until theres not a next line
          while (sc.hasNextLine())
          {
                String data  = sc.nextLine();
                read_from_file(data,loop);
                loop++;
          }
      }
      catch(IOException exp)
      {
          exp.printStackTrace();
      }
      sc.close();
    }
    private int read_from_file(String data, int loop)
    {
        Scanner sc = new Scanner(data);
        String data2;
        sc.useDelimiter(",");
        while (sc.hasNext())
        {
            //reads in data and inserts it inside the array of LLL
            String tmp = sc.next();
            data = String.valueOf(tmp);
            head[loop] = head[loop].insert(head[loop], data);
        }
        sc.close();
        return 1;
    }
    //display all of the veggies that they can choose from
    public int display_veggies()
    {
        if(head[0] != null)//checks if its not null
        {
            System.out.println("*****************---------*****************");
            System.out.println("Veggies:\n");
            head[0].display_all(head[0]);//calls display function
            System.out.println("*****************---------*****************\n");
        }
        return 1;
    }
    public int display_tacos_meats()
    {
        //checks if its not null and if not calls the display fucntion to display everything inside that index
        if(head[1] != null)
        {
            System.out.println("*****************---------*****************");
            System.out.println("Taco meats:\n");
            head[1].display_all(head[1]);
            System.out.println("*****************---------*****************\n");
        }
        return 1;
    }
    public int display_pizza_meats()
    {
        //checks if its not null and if not calls the display fucntion to display everything inside that index
        if(head[2] != null)
        {
            System.out.println("*****************---------*****************");
            System.out.println("Pizza meats:\n");
            head[2].display_all(head[2]);
            System.out.println("*****************---------*****************\n");
        }
        return 1;
    }
    public int display_sauces()
    {
        //checks if its not null and if not calls the display fucntion to display everything inside that index
        if(head[3] != null)
        {
            System.out.println("*****************---------*****************");
            System.out.println("Taco Sauces:\n");
            head[3].display_all(head[3]);
            System.out.println("*****************---------*****************\n");
        }
        return 1;
    }
    public int display_crust()
    {
        //checks if its not null and if not calls the display fucntion to display everything inside that index
        if(head[4] != null)
        {
            System.out.println("*****************---------*****************");
            System.out.println("Crust Type:\n");
            head[4].display_all(head[4]);
            System.out.println("*****************---------*****************\n");
        }
       return 1;
    }
    public int display_sizes()
    {
        //checks if its not null and if not calls the display fucntion to display everything inside that index
        if(head[5] != null)
        {
            System.out.println("*****************---------*****************");
            System.out.println("Sizes:\n");
            head[5].display_all(head[5]);
            System.out.println("*****************---------*****************\n");
        }
        return 0;
    }

}
