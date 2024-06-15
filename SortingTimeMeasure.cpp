
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define SIZE 50000
int data[SIZE];

void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

void WriteToConsole(){
    for(int i = 0; i < SIZE; i++){
        printf("%10d", data[i]);
    }
}

int TestFunction(){
    int c = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(i > j){
                c++;
            }
        }
    }
    return c;
}

int main(){
    clock_t start, end;;
    int i, ans;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    //WriteToConsole();


    start = clock();
    ans = TestFunction();
    end = clock();

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nTest Function took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);

}
