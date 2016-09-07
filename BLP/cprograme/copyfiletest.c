//note that the #include <unistd.h> line must come first, as it defines flags regarding POSIX compliance that may affect other include files.
#
nclude <unistd.h> //for read write
#include <stdlib.h> // for exit
#include <fcntl.h> // for open and its permissons and options



int main() {
    char buff;
    int f1,f2;

    char buffs[1024];
    int hasread;
    
    f1=open("program.c", O_RDONLY);
    f2=open("_file_copy.txt", O_WRONLY|O_CREAT, S_IWUSR|S_IRUSR);
     while(read(f1, &buff, 1) == 1){
         write(f2, &buff, 1);
     }

    // while((hasread = read(f1, buffs, sizeof(buffs))) > 0)
    //     write(f2, buffs, hasread); 
    exit(0);
}
