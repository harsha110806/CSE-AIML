import java.util.Scanner;

class Pattern
{
public static void main(String[]args)
{
Scanner sc = new Scanner(System.in);
int i,j;
System.out.print("Enter the number of rows:");
int n=sc.nextInt();
for(i=1;i<=n;i++)
{
for(j=1;j<=i;j++)
{
System.out.print(j);
}
System.out.println();
}
}
}
