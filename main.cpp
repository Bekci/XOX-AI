#include <iostream>
#include <vector>
#define TABLESIZE 3
#define X_TYPE 1
#define O_TYPE 2



void printTable(int  arr[][TABLESIZE]);


int main() {

    int arr[TABLESIZE][TABLESIZE] = {{0,1,1} ,{1,2,0},{1,0,2}};
    printTable(arr);
    makeMove(0,0,arr);
    return 0;
}


/*
 * Function to print the current table.
 */
void printTable(int  arr[][TABLESIZE]){
    for(int i = 0 ; i< TABLESIZE ;i++){
        for(int j = 0 ; j< TABLESIZE ;j++){
            switch(arr[i][j]){
                case X_TYPE:
                    std::cout << "X" <<" ";
                    break;
                case O_TYPE:
                    std::cout << "O" <<" ";
                    break;
                default:
                    std::cout <<" "<<" ";
                    break;
            }
            std::cout << "|"<< " ";
        }
        std::cout<<std::endl;
    }
}

