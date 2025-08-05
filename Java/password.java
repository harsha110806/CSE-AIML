import java.util.Scanner;

class password
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
System.out.print("Set the password:");
String correct_password=sc.nextLine();
int attempts=0;
while(attempts<3)
{
System.out.print("Input the password:");
String password=sc.nextLine();
if(password.equals(correct_password))
{
System.out.println("Correct password");
break;
}
else
{
System.out.println("wrong password");
attempts+=1;
}
}
if(attempts==3)
{
System.out.println("Account locked");
}
}
}
