#include<iostream>
#include<string>
#include<fstream>

int Registration()

 {
    std::string username , password , name , pass;
    std::cout<<"Enter the username for login  :";
    std::cin>>username;
    std::cout<<"Enter the password for login  : ";
    std::cin>>password;

    std::ifstream read;
    read.open("database.txt");
    std::getline(read , name);
    std::getline(read , pass);

    read.close();

    if(username == name && password == pass) 
    {
        
        return 1;

    }
    else{
        
        return 0;
    }
 }



 int main()
 {
    int choice;
    std::cout<<"1. Register\n ";
    std::cout<<"2. Login\n ";
    std::cout<<"3. Exit\n ";
    std::cout<<"Enter your choice :";
    std::cin>>choice;

    if(choice == 1)
    {
        std::cout<<".............Please enter your credentials for registration......\n";
        std::string name , pass;
        std::cout<<"Enter the username :";
        std::cin>>name;
        std::cout<<"Enter the password : ";
        std::cin>>pass;

        std::ofstream file;
        file.open("database.txt");

        file<<name<<"\n";
        file<<pass<<"\n";
        file.close();

        main();  

    }

    else if(choice == 2)
    {
        bool check = Registration();

        if(!check)
        {
            std::cout<<"Wrong credentials. \n";
            return 0;
        }
        else{
            std::cout<<"You have sucessfully Loged in. \n";
            return 1;
        }

    }

 }



