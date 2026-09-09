#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int s;
    char msg[100];
    struct sockaddr_in a;

    s=socket(AF_INET,SOCK_STREAM,0);

    a.sin_family=AF_INET;
    a.sin_port=htons(54);
    inet_pton(AF_INET,"127.0.0.1",&a.sin_addr);

    connect(s,(struct sockaddr*)&a,sizeof(a));

    while(1)
    {
        printf("Client: ");
        fgets(msg,100,stdin);
        msg[strcspn(msg,"\n")]=0;

        send(s,msg,strlen(msg)+1,0);

        if(strcmp(msg,"Bye")==0)
            break;

        recv(s,msg,100,0);
        printf("Server: %s\n",msg);

        if(strcmp(msg,"Bye")==0)
            break;
    }

    close(s);
}
