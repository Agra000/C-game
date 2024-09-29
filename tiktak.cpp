#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char player = 'X';
const char com = 'y';

void resetBoard();
void printBoard();
int cekKosong();
void playerMove();
void comMove();
char cekWinner();
void printWinner(char);

int main(){
    char winner = ' ';

    resetBoard();

    while(winner == ' ' && cekKosong() != 0){
    	system("cls");
        printBoard();
		
        playerMove();
        winner = cekWinner();
        if(winner != ' ' || cekKosong() == 0){
            break;
        }

        comMove();
        winner = cekWinner();
        if(winner != ' ' || cekKosong() == 0){
            break;
        }
    }

    printBoard();
    printWinner(winner);

    return 0;
}

void resetBoard(){
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    printf(" %c | %c | %C ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %C ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %C ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int cekKosong(){
    int kosong = 9;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != ' '){
                kosong--;
            }
        }
    }
    return kosong; //di kembalikan ke dalam while cek kosong di main
}

void playerMove(){
    int x, y;

    do
    {
        printf("Masukkan baris #1-3: ");
        scanf("%d", &x);
        x--;
        printf("Masukkan kolom #1-3: ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move!");
        }else{
            board[x][y] = player;
            break;
        }
    } while (board[x][y] != ' ');
    
}

void comMove(){
    srand(time(0));
    int x, y;

    if(cekKosong() > 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        
        board[x][y] = com;
    }else{
        printWinner(' ');
    }
}

char cekWinner(){
    // cek horizontal
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){ //cek bagian baris(horizontal)
            return board[i][0];
        }
    }

    // cek vertikal
    for(int i=0; i<3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){ //cek bagian kolom(vertikal)
            return board[0][i];
        }
    }

    // cek diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){ //cek bagian diagonal
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){ //cek bagian diagonal
        return board[0][2];
    }

    return ' ';
    
}

void printWinner(char winner){
    if(winner == player){
        printf("Kamu menang !!");
    }else if(winner == com){
        printf("Kamu kalah !!");
    }else{
        printf("Kamu seri !!");
    }
}
