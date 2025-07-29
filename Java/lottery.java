import java.util.Scanner;
class lottery
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
int lnum,mynum;
lnum=(int)(Math.random() *100);

System.out.println("Enter your number:");
mynum=sc.nextInt();

System.out.println("The lottery number is "+lnum);

int mynumtens=mynum/10;
int mynumones=mynum%10;

int lnumtens=lnum/10;
int lnumones=lnum%10;

if(mynum==lnum)
{
System.out.println("You have won $10,000");
}
else if(mynumones==lnumtens && mynumtens==lnumones)
{
System.out.println("You have won $3000");
}
else if(mynumones==lnumones || mynumtens==lnumtens || mynumones==lnumtens || mynumtens==lnumones)
{
System.out.println("You have won $1000");
}
else
{
System.out.println("Sorry,no match!Better luck next time.");
}
}
}

