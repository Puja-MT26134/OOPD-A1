#include "../include/basicIO.h"

//declare syscall6
extern "C" long syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

extern "C" long syscall3(long number, long arg1, long arg2, long arg3);

class q5
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
        }

        void resizeNames(){
            io.outputstring("Do you want to change number of names? (y/n): ");
            char choice[8];
            io.inputstring(choice, 8);

            if (choice[0] != 'y' && choice[0] != 'Y') {
                return;   
                 }

            io.outputstring("Enter new number of names: ");
            int newCount = io.inputint();

            if (newCount <= 0 || newCount > 100) {
                io.outputstring("Invalid count. No changes made.\n");
                return;
            }
                
            long newsize = (long)newCount * Name_size;
            char* newname = (char*) syscall6(9, 0, newsize, 3, 0x22, -1, 0);

            int copyCount = (totalnames < newCount)? totalnames : newCount;
            long bytesToCopy = (long)copyCount * Name_size;
            
            for (long i = 0; i < bytesToCopy; i++) {
                newname[i] = name[i];
            }

            long oldSize = (long)totalnames * Name_size;
            syscall3(11, (long)name, oldSize, 0);

            name = newname;
            int oldCount = totalnames;
            totalnames = newCount;

            if (newCount > oldCount) {
                for (int i = oldCount; i < newCount; i++) {
                    io.outputstring("Enter name: ");
                    io.inputstring(name + i * Name_size, Name_size);
        }
    }
    }



        //io.outputstring("\nAge:");
        //io.outputint(age);
        //io.terminate();
    
};

int main(){
    q5 p;
    p.allocateNames();
    p.resizeNames();
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




