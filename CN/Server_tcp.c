#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>

int main()
{
    int s,c,n,f;
    char file[100],buf[1024];
    struct sockaddr_in a,ca;
    socklen_t l=sizeof(ca);

    s=socket(AF_INET,SOCK_STREAM,0);

    a.sin_family=AF_INET;
    a.sin_addr.s_addr=INADDR_ANY;
    a.sin_port=htons(57);

    bind(s,(struct sockaddr*)&a,sizeof(a));
    listen(s,5);

    printf("Server waiting...\n");

    while(1)
    {
        c=accept(s,(struct sockaddr*)&ca,&l);

        if(fork()==0)
        {
            close(s);

            recv(c,file,100,0);
            printf("Client requested: %s\n",file);

            f=open(file,O_RDONLY);

            if(f>=0)
            {
                while((n=read(f,buf,1024))>0)
                    send(c,buf,n,0);

                close(f);
            }

            close(c);
            return 0;
        }

        close(c);
    }
}
