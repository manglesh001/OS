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
void reverse(char  bf[],long long bfs)
{
for(long long i=0;i<bfs/2;i++)
{
    char temp=bf[i];
    bf[i]=bf[bfs-i-1];
    bf[bfs-i-1]=temp;  
}}
int main(int argc, char* argv[]) {
  mode_t dp= S_IRUSR | S_IWUSR |S_IXUSR;
  char loc[]="Assignment1_1/1_";
  long long begin=strtol(argv[2],NULL,10);
  long long end=strtol(argv[3],NULL,10);
  if(begin==0 && end==0)
  {
    perror("Error Not Passed argument or not a valid argument Passed");
  }
      char * f1=new char [strlen(loc)+strlen(argv[1])+1];
strcpy(f1,loc);
strcat(f1,argv[1]);
int d=mkdir("Assignment1_1",dp);
if(d==-1)
perror("Directory Can't Be Created");
 int fd1 = open(argv[1], O_RDONLY);
   if(fd1==-1)
{
    perror("error File Not Opened ");

}
 int fd2 = open(f1, O_RDWR |O_CREAT, 0644);
    if(fd2==-1)
{
    perror("error File Not Opened ");
}

 long long size=lseek(fd1,-1,SEEK_END);
 char bf[1000];
 int n;
 long long sb=sizeof(bf);
 double per;
 long long k=(begin/sb)+1;
 long long i=1;
 lseek(fd1,begin-sb*i,SEEK_SET);
 for(i=1;i<k;i++)
 {
  lseek(fd1,begin-sb*i,SEEK_SET);
  n=read(fd1,bf,sb);
  reverse(bf,sb);
  write(fd2,bf,n);

  per=((begin-i*sb)*100)/size;
cout<<"Percentage DONE"<<per<<"%";
cout.flush();
 }
 int rem=begin-(k-1)*sb;
 lseek(fd1,0,SEEK_SET);
 n=read(fd1,bf,rem);
 reverse(bf,rem);
 write(fd2,bf,n);

 lseek(fd1,begin,SEEK_SET);
 long long mid=end-begin+1;
 long long times=mid/sb;
 long long count;
 for(count=0;count<times;count++)
 {
n=read(fd1,bf,sb);
  write(fd2,bf,n);
 
  per=((begin+sb*count)*100)/size;
cout<<"percentage-DONE"<<per<<"%";
cout.flush();
 }
 int temp2=mid-times*sb;
 n=read(fd1,bf,temp2);
 write(fd2,bf,n);
 long long j=((size-end-1)/sb);
 long long p;
 for(p=1;i<=j;i++)
 {
  lseek(fd1,-(sb*p)-1,SEEK_END);
  n=read(fd1,bf,sb);
 reverse(bf,sb);
 write(fd2,bf,n);
 per=((end+sb*(p+1))*100)/size;
cout<<"percentage-DONE"<<per<<"%";
cout.flush();
 }
 if((size-end-1)%sb!=0)
 {
int rem=size-end-sb*j-1;
lseek(fd1,end+1,SEEK_SET);
n=read(fd1,bf,rem);
 reverse(bf,rem);
 write(fd2,bf,n);
 }
 if(size<sb)
cout<< "File Written 100%";

    close(fd1);
    close(fd2);
    return 0;
}
 
 
