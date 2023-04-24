#include<iostream>							//for input and output
#include<string>							//to use string functions
#include<fstream>							//to use file input and output
#include<stdlib.h>							//to use system("clear")
using namespace std;
class diary{							//class Diary
string date,line[101];							//two data members , 1)date & 2)lines of diary
public:
void new_p(){
system("clear");
cout<<"\nPersonal Diary\n";
ada:cout<<"Enter todays date(YYYY.MM.DD):";
cin>>date;							//date input , which should be in YYYY.MM.DD format
try{								//Exception handling if the date is not in YYYY.MM.DD format
if(date.length()!=10){
throw 0;								//Throwing an exception
}
}
catch(int a){							//Exception caught
cout<<"wrong date.";
goto ada;
}
const char *c=date.c_str();						//conversion of date from string to const char * , to use it as filename
ofstream f;							//object of ofstream to input the date and lines.
f.open(c);								//opening/creating new file named as YYYY.MM.DD
ofstream f1;							//another object to input the date in a index file. 
f1.open("index.txt",ios::binary|ios::app);
f<<" DATE:"<<date<<"|\n\n";						//date overwritten in new file named as YYYY.MM.DD adding | in the end of 										date to differentiate ahead
f1<<date<<" | "<<"\n";						//date appended in file named index.txt adding | in the end of 										date to differentiate ahead
f1.close();
cout<<"\nEnter Your Text (Press DONE and  hit enter to stop):\n";
for(int i=0;i<101;i++){
cin>>line[i];							//string input word by word into the object
if(line[i]=="DONE"){
break;
}
f<<line[i]<<"*";							//string input of the object is given as input to new file YYYY.MM.DD adding 										* in the end of every word to differentiate ahead
}
cout<<"\n\npress any key and press enter ... ";
char any;cin>>any;
f.close();
}
void index(){
cout<<"\nPersonal Diary\n";
char ch;
ifstream f;								//object of ifstream to read from the file 
f.open("index.txt",ios::binary);						//index.txt which contains the date inputs 
if(!f){								//checking if there exists a file named index.txt
cout<<"Unable to open the file.";
}
while(f>>ch){
if(ch=='|'){cout<<"\n";}						//if we encounter any | we move one line down
else{cout<<ch;}							//else we print the date
}
cout<<"\n\npress any key and press enter ... ";
char any;cin>>any;
}
void go_to(){
cout<<"\nPersonal Diary\n";
string a;
cout<<"Enter the date : (YYYY.MM.DD)";
cin>>a;								//taking a date input 
const char *c = a.c_str();						//converting to const char * to use in file output
char ch;								//to take file output character by character
ifstream f;								//object of ifstream to read from file
f.open(c);								//opening file of date YYYY.MM.DD
if(!f){								//checks if file is not found
cout<<"Unable to open the file.";
}
while(f>>ch){							//else output of file is given into character 
if(ch=='|'){cout<<"\n";}						//if output is | we skip the line
else if(ch=='*'){cout<<" ";}						//if output is * we skip a space
else{cout<<ch;}							//else we print the output of the file
}
cout<<"\n\npress any key and press enter ... ";
char any;cin>>any;
}
};
int main(){
cout<<"\nPersonal Diary\n";
int choice;
a1:system("clear");
cout<<"Enter choice\n1.new page\n2.Index\n3.Go to date\n4.Exit\n:";
cin>>choice;							//choice is taken 1.to create new page in the diary 2.to see the index of 										datewise entries 3.to go to a specified date of the diary. 4.To leave the 										personal diary management system.
diary ob;								//object of class diary is created to create data members of date and lines 										and to call different functions of diary
if(choice==1){							//checking if choice entered by user is 1
system("clear");							//clears the screen
ob.new_p();							//class member function new_p to create a new page 
goto a1;								//go back to choice after clearing the  screen
}
else if(choice==2){							//checking if choice entered by user is 2
system("clear");							//clears the screen
ob.index();							//calls member function index to show the index of the diary
goto a1;								//go back to choice after clearing the screen
}
else if(choice==3){							//checking if choice entered y user is 3
system("clear");							//clears the screen 
ob.go_to();							//callls member function go_to to go to any page of the diary 
goto a1;								//go back to choice after clearing the screen
}
else if(choice==4){							//checking if choice entered by user is 4
system("clear");							//clears the screen
cout<<"\nPersonal Diary\n";
cout<<"Thank You for coming.\n";
}
else{								//if user enters wrong choice
cout<<"Wrong input please enter again";
goto a1;								//go back to choice after clearing the screen
}
}
