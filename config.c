#include"sys/types.h"//open
#include"sys/stat.h"//open
#include"fcntl.h"//open
#include"stdio.h"//printf perror
#include"stdlib.h"//exit
#include"unistd.h"//close
#include"string.h"

void main(void){
	int fd;
	fd=open("/etc/shadowsocks/us.json",O_RDWR|O_CREAT|O_TRUNC,0777);
	if(fd==-1){
		perror("open file");
		exit(1);
	}

	char server[3][1024]={};
	printf("请输入服务器ip:\n");
	scanf("%s",server[0]);
	printf("请输入服务器port:\n");
	scanf("%s",server[1]);
	printf("请输入服务器password:\n");
	scanf("%s",server[2]);

	printf("--------------------------------------------------\n");

	lseek(fd,0,SEEK_SET);
	write(fd,"{\n\t\"server\":\"",strlen("{\n\t\"server\":\""));
	write(fd,server[0],strlen(server[0]));
	write(fd,"\",\n\t\"server_port\":",strlen("\",\n\t\"server_port\":"));
	write(fd,server[1],strlen(server[1]));
	write(fd,",\n\t\"local_address\":\"127.0.0.1\",\n\t\"local_port\":9050,\n\t\"password\":\"",strlen(",\n\t\"local_address\":\"127.0.0.1\",\n\t\"local_port\":9050,\n\t\"password\":\""));
	write(fd,server[2],strlen(server[2]));
	write(fd,"\",\n\t\"timeout\":300,\n\t\"method\":\"aes-256-cfb\",\n\t\"fast_open\":false,\n\t\"workers\":1,\n\t\"prefer_ipv6\":false\n}",strlen("\",\n\t\"timeout\":300,\n\t\"method\":\"aes-256-cfb\",\n\t\"fast_open\":false,\n\t\"workers\":1,\n\t\"prefer_ipv6\":false\n}"));

	lseek(fd,0,SEEK_SET);

	char server_data[1024]={};
	read(fd,server_data,sizeof(server_data));

	printf("read:%s\n",server_data);

	close(fd);
}
