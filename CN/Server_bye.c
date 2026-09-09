#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int s,c;
    char msg[100];
    struct sockaddr_in a,ca;
    socklen_t l=sizeof(ca);

    s=socket(AF_INET,SOCK_STREAM,0);

    a.sin_family=AF_INET;
    a.sin_addr.s_addr=INADDR_ANY;
    a.sin_port=htons(54);

    bind(s,(struct sockaddr*)&a,sizeof(a));
    listen(s,1);

    printf("Waiting for client...\n");

    c=accept(s,(struct sockaddr*)&ca,&l);

    while(1)
    {
        recv(c,msg,100,0);
        printf("Client: %s\n",msg);

        if(strcmp(msg,"Bye")==0)
            break;

        printf("Server: ");
        fgets(msg,100,stdin);
        msg[strcspn(msg,"\n")]=0;

        send(c,msg,strlen(msg)+1,0);

        if(strcmp(msg,"Bye")==0)
            break;
    }

    close(c);
    close(s);
}
