class book
{
int code;
String title;
double price;
book(int code, String title, double price )
{
this.code=code;
this.title=title;
this.price=price;
System.out.println("Code:"+this.code+" title:"+this.title+" price:"+this.price);
}
}
class Main
{
public static void main(String[]args)
{
book b1=new book(1234,"wings of fire",599.5);
}
}