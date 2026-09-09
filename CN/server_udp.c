#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>

int main()
{
int s,n,f;
char file[100],buf[1024];
struct sockaddr_in a,ca;
socklen_t l=sizeof(ca);

s=socket(AF_INET,SOCK_DGRAM,0);

a.sin_family=AF_INET;
a.sin_addr.s_addr=INADDR_ANY;
a.sin_port=htons(59);

bind(s,(struct sockaddr*)&a,sizeof(a));

printf("Server waiting...\n");

while(1)
{
    n=recvfrom(s,file,100,0,
               (struct sockaddr*)&ca,&l);

    file[n]=0;
    printf("Client requested: %s\n",file);

    f=open(file,O_RDONLY);

    if(f>=0)
    {
        while((n=read(f,buf,1024))>0)
            sendto(s,buf,n,0,
                   (struct sockaddr*)&ca,l);

        close(f);
    }
}

}

