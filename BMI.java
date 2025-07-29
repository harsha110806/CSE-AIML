import java.util.Scanner;
class BMI
{
public static void main(String[]args)
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter weight in pounds:");
float weight=sc.nextFloat();
System.out.println("Enter height in inches:");
float height=sc.nextFloat();
weight=weight/2.205f;
height=height/39.37f;
float sq=height*height;
double bmi=weight/sq;
System.out.println("BMI is "+bmi);
if(bmi<18.5)
{
System.out.println("Underweight");
}
else if(bmi>=18.5 && bmi<25.0)
{
System.out.println("Normal");
}
else if(bmi>=25.0 && bmi<30.0)
{
System.out.println("Overweight");
}
else
{
System.out.println("Obese");
}

}
}

