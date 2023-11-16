import java.util.*;
public class Admin {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String Admin_username="Priyansh Dixit";
        String Password="70733";
        HashMap<String,String> users=new HashMap<>();
        System.out.println("Are you new user? If yes then enter 1 and if you are existing user than enetr any number");
        int entry=sc.nextInt();
        if(entry==70733){
            System.out.println("Welcome Admin!!!!!");
            System.out.println("Here is the list of Existing user");
            Set<String> set1=users.keySet();
            System.out.println(set1);
        }
        else if(entry==1){
            System.out.print("Enter Your Name:- ");
            String name=sc.next();
            System.out.print("Enter Password:- ");
            String Password_user=sc.next();
            users.put(name, Password_user);
        }else{
            System.out.print("Welcome Back!!");
        }
    }   
}
