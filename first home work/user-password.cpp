#include<iostream>
#include<stdio.h>
#include<string.h>
using  std::endl;
int main(){
	std::cout<<"Please enter your name,no longer than 12 chars"<<endl;
	char name[12];
	std::cin>>name;
	int lenth=strlen(name);
//²âÊÔÓÃ	std::cout<<lenth<<endl; 
	
	for(int i=1;i<=lenth+18;i++)	std::cout<<"*";
	std::cout<<endl<<"*";
	for(int i=1;i<=lenth+16;i++)	std::cout<<" "; std::cout<<"*"<<endl;
	std::cout<<"*    Hello, ";
	for(int i=0;i<lenth;i++)		std::cout<<name[i];
	std::cout<<"!    *"<<endl<<"*";
	for(int i=1;i<=lenth+16;i++)	std::cout<<" "; std::cout<<"*"<<endl;
	for(int i=1;i<=lenth+18;i++)	std::cout<<"*";
	return 0; 
} 
