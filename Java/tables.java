import java.util.Scanner;

class tables
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter the number to get the table:");
int n=sc.nextInt();
int i;
for(i=1;i<=10;i++)
{
System.out.println(n+"x"+i+"="+(n*i));
}
}
}