#include "../include/basicIO.h"

class q3
{

private:

    char name[100];
    int age;

public:

    void inputName(){
        io.outputstring("Enter your name:");
        io.inputstring(name, 100);
    }

    void inputAge(){
        io.outputstring("Enter your age:");
        age = io.inputint();
    }

    bool isValidAge() const{
        return age > 0 && age <150;
    }
    void display() const{
        io.outputstring("Name:");
        io.outputstring(name);
        io.outputstring("\nAge:");
        io.outputint(age);
        io.terminate();
    }
};
int main(){
    q3 p;
    p.inputName();
    p.inputAge();

    if(!p.isValidAge()){
        io.outputstring("Invalid age");
        io.terminate();
        return 0;
    }
    p.display();

    io.outputstring("Is this correct age? (y/n):");
    char response[8];
    io.inputstring(response, 8);

    if((response[0]=='y')||( response[0]=='Y')){
    io.outputstring("Confirmed");
    }

    else{
    io.outputstring("Not Confirmed");
    }

    io.terminate();

    return 0;
}



