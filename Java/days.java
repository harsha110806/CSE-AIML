import java.util.Scanner;

class day
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
int today,daysahead,futureday;
System.out.println("Enter today's day:");
today=sc.nextInt();
System.out.println("Today is ");
switch(today)
{
case 1:System.out.println("Sunday");
break;
case 2:System.out.println("Monday");
break;
case 3:System.out.println("Tuesday");
break;
case 4:System.out.println("Wednesday");
break;
case 5:System.out.println("Thursday");
break;
case 6:System.out.println("Friday");
break;
case 7:System.out.println("Saturday");
break;
}
System.out.println("Enter number of days after today:");
daysahead=sc.nextInt();
today-=1;
futureday=(today+daysahead)%7;
futureday+=1;
System.out.println("Future day is ");
switch(futureday)
{
case 1:System.out.println("Sunday");
break;
case 2:System.out.println("Monday");
break;
case 3:System.out.println("Tuesday");
break;
case 4:System.out.println("Wednesday");
break;
case 5:System.out.println("Thursday");
break;
case 6:System.out.println("Friday");
break;
case 7:System.out.println("Saturday");
break;
}
}
}




