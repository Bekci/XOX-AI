#include <iostream>
#include <vector>
#define TABLESIZE 3
#define X_TYPE 1
#define O_TYPE 0
#define GAME_DRAW (-1)
#define GAME_CONTINUES (-2)



void printTable(int  arr[][TABLESIZE]);
int determineWinner(int arr[][TABLESIZE]);




int main() {

    int arr[TABLESIZE][TABLESIZE] = {{0,1,1} ,{1,2,0},{1,0,2}};
    printTable(arr);
    determineWinner(arr);
    return 0;
}



/*
 * Function to find and return the type of winner if there is a winner.
 */
int determineWinner(int arr[][TABLESIZE]){

    int currentType;
    bool isWin = true;
    int moveCount = 0;
    //Traverse Rows to find a winner.
    for(int i = 0 ; i< TABLESIZE ;i++){
        currentType =  arr[i][0];
        for(int j = 1  ; j < TABLESIZE ;j++){
            if(currentType != arr[i][j]){
                isWin = false;
                break;
            }
        }
        if(isWin) return currentType;
        isWin = true;
    }
    //Traverse Columns to find a winner.
    for(int i = 0 ; i< TABLESIZE ;i++){
        currentType =  arr[0][i];
        for(int j = 1  ; j < TABLESIZE ;j++){
            if(currentType != arr[j][i]){
                isWin = false;
                break;
            }
        }
        if(isWin) return currentType;
        isWin = true;
    }
/*
 * Traverse diagonals to find a winner.
 */
    isWin = true;
    currentType =  arr[0][0];
    for (int i = 1; i < TABLESIZE; ++i){
        if(currentType != arr[i][i]){
            isWin = false;
            break;
        }
    }
    if(isWin) return currentType;
    //Other diagonal
    isWin = true;
    currentType =  arr[TABLESIZE-1][TABLESIZE-1];
    for (int i = TABLESIZE - 2 ; i > -1; --i){
        if(currentType != arr[i][i]){
            isWin = false;
            break;
        }
    }
    if(isWin) return currentType;
    //There is not any winner. Either draw or game has not finished.
    else{
        for(int i = 0 ; i< TABLESIZE;i++){
            for (int j = 0; j < TABLESIZE; ++j) {
                if(arr[i][j] == X_TYPE ||arr[i][j] == O_TYPE){
                    moveCount++;
                }
            }
        }
        if(moveCount == TABLESIZE * TABLESIZE)
            return GAME_DRAW;
        else return GAME_CONTINUES;
    }
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

