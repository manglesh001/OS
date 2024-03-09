#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/stat.h>
#include<bits/stdc++.h>
using namespace std;
void reverse(char  bf[],long long sb)
{
for(long long i=0;i<sb/2;i++)
{
    char temp=bf[i];
    bf[i]=bf[sb-1-i];
    bf[sb-i-1]=temp;
}}
int main(int argc, char* argv[]) {
  mode_t dp= S_IRUSR | S_IWUSR |S_IXUSR;  //directory Permission mode RWX
  char loc[]="Assignment1_1/1_";      
  char * inputfile=new char[strlen(loc)+strlen(argv[1])+1];   
strcpy(inputfile,loc);
strcat(inputfile,argv[1]);
int d=mkdir("Assignment1_1",dp);
if(d==0)
cout<<"Directory Created Successfully"<<endl;
if(d==-1)
perror("Directory Can't Be Created");
 int fd1 = open(argv[1], O_RDONLY);     
   if(fd1==-1)
{
    perror("Error! InputFile Not Opened ");

}
 int fd2 = open(inputfile, O_RDWR |O_CREAT | O_TRUNC, 0600);
    if(fd2==-1)
{
    perror("Error! OutputFile Not Opened ");

}
 char bf[1024];    
 int n;
 long long sb=sizeof(bf);
 long long size=lseek(fd1,-1,SEEK_END);
 long long j=(size/sb)+1;
long long i=1;
lseek(fd1,-(sb*i)-1,SEEK_END);
n=read(fd1,bf,sb);

for(i=2;i<=j && n!=0;i++)
{                           
lseek(fd1,-(sb*i)-1,SEEK_END);
reverse(bf,sb);
write(fd2,bf,n);
  int per=(i*100)/j;
  cout<<" \r Percentage Completed :"<<per<<"%";
  cout.flush();
}
int t=size-(sb*(j-1)); 
lseek(fd1,0,SEEK_SET);
n=read(fd1,bf,t);
reverse(bf,t);
write(fd2,bf,n);
if(size<sb)
cout<< "File Written 100%";

    close(fd1);
    close(fd2);
    return 0;
}

