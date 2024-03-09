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
bool checkreverse(char bf2[],char bf1[],long long sb)
{
for(int i=0;i<sb;i++)
{
    if(bf2[i]!=bf1[sb-i-1])
    return false;   
}
  return true;   
}
int main(int argc, char* argv[]) 
{
  int i,n,revn;
  struct stat ds,fs1,fs2;
   char *arr=(char*)malloc(strlen(argv[3])+1);
   strcpy(arr,argv[3]);
   char * fl2=new char [strlen(arr)+strlen(argv[1])+1];
   strcpy(fl2,arr);
   strcpy(fl2,argv[1]);
   
  if(stat(argv[3],&ds)<0)
  {
    perror("Directory Can't find");
    cout<<"Directory is Created: No"<<endl;
    return 0;
  }
cout<<"Directory is Created: Yes"<<endl;
stat(argv[2],&fs1);
stat(fl2,&fs2);
int fd1 = open(argv[2], O_RDONLY);
   if(fd1==-1)
{
    perror("error File Not Opened ");
return 0;
}  
int fd2 = open(fl2, O_RDONLY);
   if(fd2==-1)
{
    perror("error File Not Opened ");
return 0;
}
char bf1[1024];
char bf2[1024];

long long sb=sizeof(bf2);
long long s1=fs1.st_size;
long long s2=fs2.st_size;
int flag=1;
long long j =s1/sb +1;

for(i=1;i<j;i++)
{
  revn=read(fd2,bf2,sb);
  lseek(fd1,-sb*i-1,SEEK_END);
  n=read(fd1,bf1,sb);
  if((checkreverse(bf2,bf1,sb))==0)
  {
    flag=0;
    break;
  }
}
revn=read(fd2,bf2,sb);
int size=s1-(sb*j-1);
lseek(fd1,0,SEEK_SET);
n=read(fd1,bf1,size);
if(i-j!=1 && checkreverse(bf2,bf1,size))
    flag=0;
if(flag==1)
cout<<"Whether file contents are reversed in newfile: Yes "<<endl;
else
cout<<"Whether file contents are reversed in newfile: No"<<endl;



if(fs2.st_mode & S_IRUSR)
cout<<"User has read permissions on newfile: Yes"<<endl;
else
cout<<"User has read permissions on newfile: No"<<endl;
if(fs2.st_mode & S_IWUSR)
cout<<"User has write permission on newfile: Yes"<<endl;
else
cout<<"User has write permission on newfile: No"<<endl;
if(fs2.st_mode & S_IXUSR)
cout<<"User has execute permission on newfile: Yes"<<endl;
else
cout<<"User has execute permission on newfile: No"<<endl;

if(fs2.st_mode & S_IRGRP)
cout<<"Group has read permissions on newfile: Yes"<<endl;
else
cout<<"Group has read permissions on newfile: No"<<endl;
if(fs2.st_mode & S_IWGRP)
cout<<"Group has write permissions on newfile: Yes"<<endl;
else
cout<<"Group has write permissions on newfile: No"<<endl;
if(fs2.st_mode & S_IXGRP)
cout<<"Group has execute permissions on newfile: Yes"<<endl;
else
cout<<"Group has execute permissions on newfile: No"<<endl;

if(fs2.st_mode & S_IROTH)
cout<<"Others has read permissions on newfile: Yes"<<endl;
else
cout<<"Others has read permissions on newfile: No"<<endl;
if(fs2.st_mode & S_IWOTH)
cout<<"Others has write permissions on newfile: Yes"<<endl;
else
cout<<"Others has write permissions on newfile: No"<<endl;
if(fs2.st_mode & S_IXOTH)
cout<<"Others has execute permissions on newfile: Yes"<<endl;
else
cout<<"Others has execute permissions on newfile: No"<<endl;





if(fs1.st_mode & S_IRUSR)
cout<<"User has read permissions on oldfile: Yes"<<endl;
else
cout<<"User has read permissions on oldfile: No"<<endl;
if(fs1.st_mode & S_IWUSR)
cout<<"User has write permissions on oldfile: Yes"<<endl;
else
cout<<"User has write permissions on oldfile: No"<<endl;
if(fs1.st_mode & S_IXUSR)
cout<<"User has execute permissions on oldfile: Yes"<<endl;
else
cout<<"User has execute permissions on oldfile: No"<<endl;

if(fs1.st_mode & S_IRGRP)
cout<<"Group has read permissions on oldfile: Yes"<<endl;
else
cout<<"Group has read permissions on oldfile: No"<<endl;
if(fs1.st_mode & S_IWGRP)
cout<<"Group has write permissions on oldfile: Yes"<<endl;
else
cout<<"Group has write permissions on oldfile: No"<<endl;
if(fs1.st_mode & S_IXGRP)
cout<<"Group has execute permissions on oldfile: Yes"<<endl;
else
cout<<"Group has execute permissions on oldfile: No"<<endl;

if(fs1.st_mode & S_IROTH)
cout<<"Others has read permissions on oldfile: Yes"<<endl;
else
cout<<"Others has read permissions on oldfile: No"<<endl;
if(fs1.st_mode & S_IWOTH)
cout<<"Others has write permissions on oldfile: Yes"<<endl;
else
cout<<"Others has write permissions on oldfile: No"<<endl;
if(fs1.st_mode & S_IXOTH)
cout<<"Others has execute permissions on oldfile: Yes"<<endl;
else
cout<<"Others has execute permissions on oldfile: No"<<endl;




if(ds.st_mode & S_IRUSR)
cout<<"User has read permissions on Directory: Yes"<<endl;
else
cout<<"User has read permissions on Directory: No"<<endl;
if(ds.st_mode & S_IWUSR)
cout<<"User has write permission on Directory: Yes"<<endl;
else
cout<<"User has write permission on Directory: No"<<endl;
if(ds.st_mode & S_IXUSR)
cout<<"User has execute permission on Directory: Yes"<<endl;
else
cout<<"User has execute permission on Directory: No"<<endl;

if(ds.st_mode & S_IRGRP)
cout<<"Group has read permissions on Directory: Yes"<<endl;
else
cout<<"Group has read permissions on Directory: No"<<endl;
if(ds.st_mode & S_IWGRP)
cout<<"Group has write permissions on Directory: Yes"<<endl;
else
cout<<"Group has write permissions on Directory: No"<<endl;
if(ds.st_mode & S_IXGRP)
cout<<"Group has execute permissions on Directory: Yes"<<endl;
else
cout<<"Group has execute permissions on Directory: No"<<endl;

if(ds.st_mode & S_IROTH)
cout<<"Others has read permissions on Directory: Yes"<<endl;
else
cout<<"Others has read permissions on Directory: No"<<endl;
if(ds.st_mode & S_IWOTH)
cout<<"Others has write permissions on Directory: Yes"<<endl;
else
cout<<"Others has write permissions on Directory: No"<<endl;
if(ds.st_mode & S_IXOTH)
cout<<"Others has execute permissions on Directory: Yes"<<endl;
else
cout<<"Others has execute permissions on Directory: No"<<endl;


  close(fd1);
    close(fd2);
    return 0;
}
