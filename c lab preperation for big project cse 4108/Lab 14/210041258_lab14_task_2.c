#include<stdio.h>


int main(int a, char* argv[]){
    char ch;
    // Used to read one byte at a time
    FILE* fp = fopen(argv[1], "rb"); //Opening the file in read-binary mode
    FILE* fp2 = fopen(argv[2], "wb"); // Opening the file in write binary mode
    while(!feof(fp)){ //run the loop until reach the end of file
        fscanf(fp, "%c",&ch); // read one byte from the file
        fprintf(fp2, "%c", ch); //write one byte to a file
    }
    fclose(fp); // Closing the file
    fclose(fp2); // Closing the file
    return 0;
}
