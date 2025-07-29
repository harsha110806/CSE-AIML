//tax = (income > 10000) ? income * 0.2 : income * 0.17 + 1000;

import java.util.Scanner;
class tax
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
float tax,income;
System.out.println("Enter the income:");
income=sc.nextFloat();
if(income>10000)
{
tax=income*0.2f;
}
else
{
tax=(income*0.17f)+1000;
}
System.out.println("Tax is "+tax);
}
}
 