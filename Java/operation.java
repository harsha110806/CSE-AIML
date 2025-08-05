class operation
{
int m1,m2;
void arithmetic1()
{
System.out.println("Addition:"+(m1+m2));
System.out.println("Subtraction:"+(m1-m2));
System.out.println("Multiplication:"+(m1*m2));
System.out.println("Division:"+(m1/m2));
}
void arithmetic2(int x, int y)
{
System.out.println("Addition:"+(x+y));
System.out.println("Subtraction:"+(x-y));
System.out.println("Multiplication:"+(x*y));
System.out.println("Division:"+(x/y));
}
int arithmetic3()
{
return((m1+m2));
}
int arithmetic4(int a,int b)
{
return((a+b));

}
public static void main(String[]args)
{
operation a1=new operation();
a1.m1=90;
a1.m2=45;
a1.arithmetic1();
a1.arithmetic2(60,30);
int r=a1.arithmetic3();
System.out.println(r);
int r1=a1.arithmetic4(50,100);
System.out.println(r1);
}
}
