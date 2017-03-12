#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<utime.h>


int main(){
char *fd ="hola";
struct stat *finfo;
struct utimbuf aion; 
finfo = malloc(sizeof(struct stat));


stat(fd,finfo);


int size = finfo->st_size;
time_t atime =finfo->st_atime;
time_t mtime =finfo->st_mtime;/*seconds since the epoch*/
time_t ctime =finfo->st_ctime;

printf("%d\n",size);
printf("ultimo acceso %d\n",atime);
printf("ultima modificacion %d\n",mtime);
printf("cambio de estado(permisos) %d\n",ctime);

aion.actime=finfo->st_atime;/*keep atime unchanged*/
aion.modtime=1;
//printf("%d\n",size);
utime(fd,&aion);
free(finfo);
return 0;
}
