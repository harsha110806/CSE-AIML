import java.util.Scanner;
class skipodd
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter the number:");
int n=sc.nextInt();
int i;
for(i=1;i<=n;i++)
{
if((i%2)==0)
{
System.out.print(i +" ");
}
else
{
continue;
}
}
}
}
