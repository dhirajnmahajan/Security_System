#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a,i=0;
    string name,text,old,password0,password1,password2,pass,age,user ,word,word1;
    string creds[2],cp[2];

    cout<<"********************"<<endl;
    cout<< " - SECURITY SYSYTEM - "<<endl;
    cout<<"********************"<<endl<<endl;

    cout<< "1. Register "<<endl;
    cout<< "2. Login"<<endl;
    cout<< "3. Change Password "<<endl;
    cout<< "4. Exit "<<endl<<endl;

   do{
     cout<<endl<<endl;
     cout<<" Enter your Choice: ";
     cin>>a;

     switch (a)
     {
   
     case 1:
     {
        cout<<"\n ###  Register ###"<<endl<<endl;
        cout<<" Please enter the Username:- ";
        cin>>name;
        cout<<"\n Please enter the Password:- ";
        cin>>password0;
        cout<<"\n Enter your Age:-";
        cin>>age;

        ofstream of1;    // creating the object of ofstream class.
        of1.open("file.txt");
        if(of1.is_open()){
           of1<<name<<"\n";
           of1<<password0;
           cout<<" Registeration SuccessFull !! "<<endl;
        }
      break;  
      }
      
      case 2:
      {
           i=0;

           cout<<"\n ### Log-In ### "<<endl<<endl;

           ifstream of2;   // creating object of ifstream class
           of2.open("file.txt");
           cout<<" Enter the Username: ";
           cin>>user;
           cout<<" Enter the Password: ";
           cin>>pass;

           if(of2.is_open())
           {
             while (!of2.eof())  // eof() - end of file function
             {
                while (getline(of2,text)) // getline() - is used to read the file line by  line.
                 {
                    istringstream iss(text);  // istringstream - used to parsing input
                    iss>>word;
                    creds[i]=word;
                    i++;
                  }
                 if(user==creds[0] && pass==creds[1]) 
                 {
                    cout<<"  Login Successfull !!"<<endl<<endl;
                    cout<<" Details:"<<endl;
                    
                    cout<<" Username: "+ name<<endl;
                    cout<<" Username: "+ pass<<endl;
                    cout<<" Age: " + age<<endl;    
                 }
                 else{
                    cout<<endl<<endl;
                    cout<<" * Invalid Username or Password ! *"<<endl;
                    cout<<" Press [2] to Login "<<endl;
                    cout<<" Press [3] to Change Password "<<endl;
                     break;
                 }
              }
           }
        break; 
      }
        
     case 3:
    {
       i=0;
       cout<<"\n ### Change PassWord ### "<<endl;

       ifstream of0;
       of0.open("file.txt");
       cout<<" Enter the old password: ";
       cin>>old;

       if(of0.is_open())
       {
        while (of0.eof())
        {
          while (getline(of0,text))
          {
            istringstream iss(text);
            iss>>word1;
            cp[i]=word1;
            i++;
          }
           
           if(old==cp[1]){
           
             of0.close();

             ofstream of1;
             if(of1.is_open()){
                cout<<"Enter your new Password:"<<endl;
                cin>>password1;
                cout<<"Enter your Password Again:"<<endl;
                cin>>password2;

                if(password1==password2)
                {
                    of1<<cp[0]<<"\n";
                    of1<<password1;
                    cout<<" PassWord change SuccessFully !! "<<endl;
                }
                else{
                    of1<<cp[0]<<"\n";
                    of1<<old;
                    cout<<" *PassWord do not Match "<<endl;
                }
             }
            }
            else{
                cout<<" * Please Enter Valid Password !"<<endl;
                break;

           }
        }
        
       }
    break;   
    }
    
     case 4:
    {
       cout<<"\n________ THANK YOU ! ________";
       break;       
    }

     default:
        cout<<"Please enter a valid Choice. "<<endl;
        break;
     }
   }
     
 while (a!=4);    

 return 0;
     
}