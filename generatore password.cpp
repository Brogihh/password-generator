#include <iostream>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 
#include <ctime>
#include <fstream>
//per il tempo
#ifdef _WIN32
#include <Windows.h>
#else
#include <algorithm>
#include <unistd.h>
#endif 
using namespace std;
int main (){
  string ext= ".txt";
  char alph[65] = {'A', 'B', 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z','!', '"', '#', '$', '%','&', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '>', '=', '?', '@', '[', ']', '^', '_', '`', '{', '}', '|', '~', '1','2', '3', '4', '5', '6', '7', '8', '9'};
  int iSecret=0;	
  int n_psw=0;
  int opzione=0;
  string save_file;
  string file_name="text.txt";
  do{                                                                                                      
  cout << "-----------------PASSWORD GENERATOR-----------------"<<endl;
  cout<<"- How many character? (min 8) ";
  cin>>n_psw;
  if(n_psw<8){
  	do{
  		 cout<<"- ERROR: How many character? (min 8) ";
  		 cin>>n_psw;
	  }while(n_psw<8);
  }
  char psw[n_psw];
  srand (time(NULL));
  cout<<"PASSWORD = ";
  for(int i=0; i<n_psw; i++){
    iSecret = rand() % 64 + 1;
	cout<<alph[iSecret];
	psw[i]=alph[iSecret];
  }
  //END PASSWORD GENERATIONW

 cout<<endl<<endl<<"1 - SAVE THE PASSWORD INTO A FILE "<<endl;
 cout<<endl<<"2 - SAVE INTO AN EXISTENT FILE (this option will remove the old password if it already exists)"<<endl;
 cout<<endl<<"3 - EXIT "<<endl<<endl;
 cin>>opzione;
 switch(opzione){
	case 1:{
			cout<<"enter the file name =>";
			cin>>file_name;
			fstream New_File((file_name + ".txt").c_str());
			if(New_File.is_open()){
				New_File<<psw;
				New_File.close();
				cout<<"DONE!";
				Sleep(3000);
				system("CLS");
			}else{
				cerr<<"Something went wrong. ";
				Sleep(3000);
				system("CLS");
			}
			break;}
	case 2:{
			time_t now = time(0);
			char* dt = ctime(&now);
			cout<<"enter the file name =>";
			cin>>file_name;
			fstream File((file_name + ".txt").c_str());
			if(File.is_open()){
				File<<endl<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<"PASSWORD "<<dt<<" => "<<psw<<endl<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
				File.close();
				cout<<"DONE!";
				Sleep(3000);
				system("CLS");
			}else{
				cerr<<"Something went wrong, the file may not exist. ";
				Sleep(3000);
				system("CLS");
			}
		break;
	}
 }
}while(opzione!=3);

cout<<"Script made by searchme thanks for used it! Bye!";

}
