import java.util.Scanner;
class ternary
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
//score = (x > 10) ? 3 * scale : 4 * scale;
int score,x,scale;
System.out.println("Enter the value of x:");
x=sc.nextInt();
System.out.println("Enter the scale:");
scale=sc.nextInt();
if(x>10)
{
score=3*scale;
}
else
{
score=4*scale;
}
System.out.println("score is "+score);
}
}
