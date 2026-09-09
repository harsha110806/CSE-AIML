#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>

int main()
{
int s,n,f;
char file[100],buf[1024];
struct sockaddr_in a;

```
s=socket(AF_INET,SOCK_DGRAM,0);

a.sin_family=AF_INET;
a.sin_port=htons(59);
inet_pton(AF_INET,"127.0.0.1",&a.sin_addr);

printf("Enter file name: ");
scanf("%s",file);

sendto(s,file,strlen(file),0,
       (struct sockaddr*)&a,sizeof(a));

f=open("received_file",
       O_WRONLY|O_CREAT|O_TRUNC,0666);

while((n=recvfrom(s,buf,1024,0,NULL,NULL))>0)
    write(f,buf,n);

close(f);
close(s);
```

}

