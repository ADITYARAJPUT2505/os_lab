//  Display parent id & process id 
#include<stdio.h> 
int main() 
{ 
printf("\n Parent Process ID %d",getppid()); 
printf("\n Child Process ID %d\n",getpid()); 
} 

//2. Process creation using  fork 
#include<stdio.h> 
main() 
{ 
printf("Before FORK \n"); 
fork(); 
printf("After FORK \n\n"); 
} 

// 3. Process with fork 
#include<stdio.h> 
main() 
{ 
int pid; 
pid=fork(); 
if(pid>0) 
{ 
printf("From Parent \n"); 
printf("Parent process id %d\n",getpid()); 
} 
else 
{ 
printf("From Child \n"); 
printf("Child process id %d\n",getpid()); 
} 
} 

// 4. Making child as orphan* 
#include<stdio.h> 
main() 
{ 
int pid,pid1; 
pid=fork(); 
if(pid>0) 
{ 
printf("From parent process\n"); 
printf("Parent process %d \n",getpid()); 
} 
else 
{ 
sleep(1); 
printf("From child process\n"); 
printf("child process %d \n",getpid()); 
}}

// 5. Parent waits till completion of child 
#include<stdio.h> 
main() 
{ 
int pid; 
pid=fork(); 
printf("%d\n",pid); 
if(pid==0) 
{ 
printf("From child process \n"); 
} 
else 
{ 
wait(0); 
printf("From parent process\n"); 
} 
} 

// 6. Use of exit system call 
#include<stdio.h> 
main() 
{ 
int pid; 
pid=fork(); 
printf("%d\n",pid); 
if(pid<0) 
{ 
perror("Child can't be executed\n"); 
exit(-1); 
} 
else 
{ 
printf("Child created\n"); 
exit(0); 
} 
} 

// 7. Using fork and exec system call 
#include<stdio.h> 
main() 
{ 
int pid; 
pid=fork(); 
printf("%d\n",pid); 
if(pid==0) 
{ 
execve("/bin/date\n",NULL,NULL); 
exit(0); } 
else 
{ 
printf("Parent process %d\n",pid);   }}

// 8. To list files in specified directory 
#include<stdio.h> 
#include<dirent.h> 
main() 
{ 
char d[10]; 
DIR *p; 
struct dirent *d1; 
printf("ENTER A DIRECTORY NAME: "); 
scanf("%s",d); 
p=opendir(d); 
if(p==NULL) 
{ 
perror("Can't find directory"); 
exit(-1); 
} 
while(d1=readdir(p)) 
printf("%s\n",d1->d_name); 
}


// 9. To list files in current directories & sub-directories 
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *p, *sp;
    struct dirent *d, *dd;
    p = opendir(".");
    if (p == NULL) {
        perror("Unable to open directory");
        return 1;
    }
    while ((d = readdir(p)) != NULL) {
        printf("%s \n", d->d_name);
        if (!strcmp(d->d_name, ".") || !strcmp(d->d_name, ".."))
            continue;
        sp = opendir(d->d_name);
        if (sp) {
            while ((dd = readdir(sp)) != NULL)
                printf("--> %s\n", dd->d_name);
            closedir(sp);
        }
    }
    closedir(p);
    return 0;
}


// 10. Create process & display pid of parent & child 
#include<stdio.h> 
#include<dirent.h> 
main(int argc,char **argv) 
{ 
int pid,i; 
for(i=0;i<atoi(argv[1]);i++) 
{ 
pid=fork(); 
if(pid==0) 
{ 
printf("child process id %d    Parent process id %d\n",getpid(),getppid()); 
}}} 


// 11. Program to rename a directory. 
#include<stdio.h> 
main() 
{ 
char s[10],d[10]; 
printf("Enter source Dir Name:\n"); 
scanf("%s",s); 
printf("Enter New Dir Name:\n"); 
scanf("%s",d); 
if(rename(s,d)==-1) 
perror("Can't be changed\n"); 
else 
printf("%s is changed to %s\n\n",s,d); 
}

// 1. Write a program to open , read and write files using system calls. 
#include<stdio.h> 
#include<fcntl.h> 
main() 
{ 
char buff[100],fn[10]; 
int fd,n; 
printf("Enter file name\n"); 
scanf("%s",fn); 
fd=open(fn,O_RDONLY); 
n=read(fd,buff,100); 
n=write(1,buff,n); 
close(fd); 
} 


// 2. Using system calls write line of texts in a file 
#include<stdio.h> 
#include<fcntl.h> 
#include<string.h> 
main() 
{ 
char *buff,fn[10]; 
int fd,n,i; 
printf("\nEnter file name "); 
scanf("%s",fn); 
printf("\nEnter text "); 
scanf("%s",buff); 
//fgets(buff,100,stdin); 
fd=open(fn,O_CREAT|O_WRONLY); 
n=write(fd,buff,strlen(buff)); 
close(fd); 
} 


// 3. Write a program to open, read and write files and perform file copy operation. 
#include<stdio.h> 
#include<fcntl.h> 
main() 
{ 
char buff[1000],fn1[10],fn2[10]; 
int fd1,fd2,n; 
printf("Enter source filename\n"); 
scanf("%s",fn1); 
printf("Enter destination file name\n"); 
scanf("%s",fn2); 
fd1=open(fn1,O_RDONLY); 
n=read(fd1,buff,1000); 
fd2=open(fn2,O_CREAT|O_WRONLY); 
n=write(fd2,buff,n); 
close(fd1); 
close(fd2); 
} 


// 4. Write a program to remove a directory. 
#include<stdio.h> 
#include<fcntl.h> 
main() 
{ 
char fn[10]; 
printf("Enter source filename\n"); 
scanf("%s",fn); 
if(remove(fn)==0) 
printf("File removed\n"); 
else 
printf("File cannot be removed\n"); 
}


// 3.SIMULATION OF UNIX COMMANDS 


// 1. Write a program for the simulation of ls command. 
#include<stdio.h> 
#include<dirent.h> 
main() 
{ 
char dirname[10]; 
DIR*p; 
struct dirent *d; 
printf("Enter directory name\n"); 
scanf("%s",dirname); 
p=opendir(dirname); 
if(p==NULL) 
{ 
perror("Cannot find directory"); 
exit(-1); 
} 
while(d=readdir(p)) 
printf("%s\n",d->d_name); 
} 


// 2. Write a program for the simulation for grep command. 
#include<stdio.h> 
#include<string.h> 
main() 
{ 
char fn[10],pat[10],temp[200]; 
FILE *fp; 
printf("Enter file name\n"); 
scanf("%s",fn); 
printf("Enter pattern to be searched\n"); 
scanf("%s",pat); 
fp=fopen(fn,"r"); 
while(!feof(fp)) 
{ 
fgets(temp,1000,fp); 
if(strstr(temp,pat)) 
printf("%s",temp); 
} 
fclose(fp); 
}

 
