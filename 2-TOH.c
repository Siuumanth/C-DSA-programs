
#include<stdio.h> 
#include<conio.h> 
 
void main() 
{ 
 int n; 
 printf("Enter the number of disks\n"); 
 scanf("%d",&n); 
 tower(n,'src','dest','temp'); 
 getch(); 
} 
tower(int n,char source,char dest,char temp) 
{ 
 if(n>0) 
 { 
 tower(n-1,source,temp,dest); 
 printf("Move disks %d from %c to %c\n",n,source,dest); 
 tower(n-1,temp,dest,source); 
 } 
 return; 
} 