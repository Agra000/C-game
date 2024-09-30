#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

char board[4][4];
char symbols[] = {'H', 'H', 'H', 'H', // 4 hati 
                  'D', 'D', 'D', 'D', 'D', 'D', // 6 diamond 
                  'S', 'S', 'S', 'S', // 4 sekop
                  'W', 'W'}; // 2 wajik 

void random();
int kosong();
void printBoard();
void resetBoard();
int playerMove(int);
char cekWin();

int main(){
	char winner = ' ', ch, u;
    int life = 3;
	
	resetBoard();
	random();
	
		do{
		    printBoard();
		    // Menunggu pengguna menekan Enter
		    printf("\n");
	        printf("Tekan Enter untuk melanjutkan...\n");
	        
	        // Menggunakan _getch() untuk menunggu input dari pengguna
	        ch = _getch();  // Hanya untuk Windows
	        
			if (ch == '\r') { // '\r' adalah karakter untuk Enter
	            system("cls"); // Bersihkan layar (Windows)
	            u = 'n';
	        }
		}while (u != 'n');
	
	while(life != 0){
        system("cls");
        printBoard();
		        
		if(playerMove(life) == true){
        	if(cekWin() == 16){
        		system("cls");
        		printBoard();
        		printf("<----- KAMU MENANG !! ----->\n");
        		break;
			}
		}else{
			life--;
			printf("\n");
			printf("<----- KAMU KALAH !! ----->\n");
		}
	}
}

void random(){
    srand(time(NULL));
    int n = sizeof(symbols) / sizeof(symbols[0]), x, y;

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
    
    for (int i = 0; i < n; i++) { //urutin nilai baru
        if(kosong() > 0){
            do{
                x = rand() % 4;
                y = rand() % 4;
            }while(board[x][y] != ' ');
            board[x][y] = symbols[i]; //masukkan random ke koordinat baru
        }
    }
}

void printBoard(){
    printf("4 | %c | %c | %C | %C ", board[3][0], board[3][1], board[3][2], board[3][3]);
    printf("\n   ---|---|---|---\n");
    printf("3 | %c | %c | %C | %C ", board[2][0], board[2][1], board[2][2], board[2][3]);
    printf("\n   ---|---|---|---\n");
    printf("2 | %c | %c | %C | %C ", board[1][0], board[1][1], board[1][2], board[1][3]);
    printf("\n   ---|---|---|---\n");
    printf("1 | %c | %c | %C | %C ", board[0][0], board[0][1], board[0][2], board[0][3]);
    printf("\n    1   2   3   4\n");
    printf("\n");
}

void resetBoard(){
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++){
            board[i][j] = ' ';
        }
    }
}

int playerMove(int life){
    int x1, y1, x2, y2, u;

        system("cls");
       	printBoard();
        do{
        	printf("Life : %d\n\n", life);
        	u = 'n';
            printf("Masukkan koordinat X pertama (1-4) : ");
            scanf("%d", &x1);
            x1--;
            printf("\n");
            
            printf("Masukkan koordinat Y pertama (1-4) : ");
            scanf("%d", &y1);
            y1--;
		
            if(x1 > 3 || y1 > 3 || x1 < 0 || y1 < 0){
            	printf("Masukkan Angka 1-4 aja!!\n\n");
            	u = 'y';
			}else if(board[x1][y1] == '*'){
				printf("Bagian ini telah di eliminasi\n\n");
				u = 'y';
			}
        }while(u == 'y');
        
        
       	system("cls");
        printBoard();
        printf("Life : %d  ||  Pilihan sebelumnya: %c\n\n", life, board[x1][y1]);
        do{
            u = 'n';
            printf("Masukkan koordinat X Kedua (1-4) : ");
            scanf("%d", &x2);
            x2--;
            printf("\n");
            
            printf("Masukkan koordinat Y Kedua (1-4) : ");
            scanf("%d", &y2);
            y2--;
            
            if(x2 > 3 || y2 > 3|| x2 < 0 || y2 < 0){
            	printf("Masukkan Angka 1-4 aja!!\n\n");
            	u = 'y';
			}else if(board[x2][y2] == '*'){
				printf("Bagian ini telah di eliminasi\n\n");
				u = 'y';
			}else if(x1 == x2 and y1 == y2 ){
				printf("Tidak boleh di baris dan kolom yang sama\n\n");
				u = 'y';
			}else if(board[x1][y1] == board[x2][y2]){
				board[x1][y1] = '*';
				board[x2][y2] = '*';
				return true;
			}else{
				return false;
			}
			
        } while (u == 'y');
       
}

char cekWin(){
	int win = 0;
	for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++){
            if(board[i][j] == '*'){
                win++;
            }
        }
    }
    
    return win;
}

int kosong(){
    int kosong = 16;

    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++){
            if(board[i][j] != ' '){
                kosong--;
            }
        }
    }

    return kosong;
}
