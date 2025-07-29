//System.out.println((number % 3 == 0) ? i : j);

import java.util.Scanner;

class number
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);

int number,i,j;

System.out.println("Enter the number:");
number=sc.nextInt();

System.out.println("Enter the value of i:");
i=sc.nextInt();

System.out.println("Enter the value of j:");
j=sc.nextInt();

if(number%3==0)
{
System.out.println("The value of i is "+i);
}

else
{
System.out.println("The value of j is "+j);
}

}
}
