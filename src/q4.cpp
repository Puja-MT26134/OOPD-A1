#include "../include/basicIO.h"

//declare syscall6
extern "C" long syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

class q4
{

    private:

        char* name;
        int totalnames;
        static const int Name_size = 64;

    public:

        void allocateNames(){
            io.outputstring("How many names needed?");
            totalnames = io.inputint();

            if (totalnames<=0 || totalnames>100){
                io.outputstring("Number of names is out of range.");
                totalnames =0;
                name =0;
            }

            else{
                long size = (long)totalnames * Name_size;   // total bytes needed
                name = (char*) syscall6(9, 0, size, 3, 0x22, -1, 0);

                for(int i=0; i<totalnames; i++){
                    io.outputstring("Enter Name:");
                    io.inputstring(name + i * Name_size, Name_size);

                 }
            }
        }

        /* void inputAge(){
        io.outputstring("Enter your age:");
        age = io.inputint();
         }

        bool isValidAge() const{
        return age > 0 && age <150;
         }*/
  

        void display() const{
            for(int j=0; j<totalnames; j++){
                io.outputstring("Name:");
                io.outputstring(name + j*Name_size);
                io.terminate();
            }

        //io.outputstring("\nAge:");
        //io.outputint(age);
        //io.terminate();
    }
};

int main(){
    q4 p;
    p.allocateNames();
    //p.inputName();
   // p.inputAge();

   /* if(!p.isValidAge()){
        io.outputstring("Invalid age");
        io.terminate();
        return 0;
    }*/

    p.display();

    /*io.outputstring("Is this correct age? (y/n):");
    char response[3];
    io.inputstring(response, 3);

    if((response[0]=='y')||( response[0]=='Y')){
    io.outputstring("Confirmed");
    }

    else{
    io.outputstring("Not Confirmed");
    }*/

    io.terminate();

    return 0;
}




