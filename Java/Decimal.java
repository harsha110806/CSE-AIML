import java.util.Scanner;

class Decimal
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter the 1st float number:");
double x=sc.nextDouble();
System.out.print("Enter the 2nd float number:");
double y=sc.nextDouble();
x=Math.round(x*1000);
y=Math.round(y*1000);
if(x==y)
{
System.out.println("x and y are same upto 3 decimal places");
}
else
{
System.out.println("x and y are different");
}
}
}
