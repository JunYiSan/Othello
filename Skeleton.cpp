#include <stdio.h>

int x, y;
int map[8][8]; 
int total; // total = User1 + User2
int user = 2;
int userval = 1;
int User1, User2;


void printM(); //전체 출력 관장
void initialize(); // 게임판 생성 
void game();	// 게임 종료 조건 계산
int userplay(); //유저가 놓을 바둑판 변경
int turn();//턴 변경
int checkNchange(int x, int y, int userval, int user); //판 변화 출력

int main(){		
	initialize();
	while(1){
		printM();
		userplay();
		checkNchange(x, y, userval, user);
		turn();
	}
	
}

void check(){
	
	User1=0, User2=0;
	if(map[x][y]==1) User1++;
	if(map[x][y]==2) User2++;	
}

void game(){ //종료 계산
	
}

int checkNchange(int x, int y, int userval, int user)//돌 색 변경
{
if(map[x-1][y] == userval){                               
	if(map[x+1][y] == userval){                           
		if(map[x][y-1] == userval){                       
			if(map[x][y+1] == userval){                   
				if(map[x+1][y+1] == userval){             
					if(map[x+1][y-1] == userval){         
						if(map[x-1][y+1] == userval){     
							if(map[x-1][y-1] == userval){ 
								if(map[x-2][y-2] == user) map[x-1][y-1] = user;
							}
						if(map[x-2][y+2] == user) map[x-1][y+1] = user;
						}
					if(map[x+2][y-2] == user) map[x+1][y-1] = user;
					}
				if(map[x+2][y+2] == user) map[x+1][y+1] = user;
				}
			if(map[x][y+2] == user) map[x][y+1] = user;
			}
		if(map[x][y-2] == user) map[x][y-1] = user;
		}
	if(map[x+2][y] == user) map[x+1][y] = user;
	}
if(map[x-2][y] == user) map[x-1][y] = user;
}
}


void initialize(){ // 게임판 생성부
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			map[i][j]=0;
		}
	}
	map[3][3]=map[4][4]=1;
	map[3][4]=map[4][3]=2;		

	total= 4;
}

void printM(){// 전체 출력 관장
	int i;
	for(i=0; i<35; i++) printf("#");  //게임 타이틀 출력부
	printf("\n\t OTHELLO GAME\n");
	for(i=0; i<35; i++) printf("#");
	printf("\n\n");
	
	printf("\t  ");
	for(int j=0; j<8; j++) printf("%d ", j);
	printf("\n");
	
	for(i=0; i<8; i++){
		printf("\t");
		printf("%d ", i);
		for(int j=0; j<8; j++){					//게임판 출력부
			if(map[i][j] == 0) printf(". ");		  // change '0' if you want
			else if(map[i][j] == 1) printf("O ");   // change '1' if you want
			else if(map[i][j] == 2) printf("X ");	// change '2' if you want
		}
		printf("\n");
	}
		printf("\n\n");
	printf("\tWhite User: %d\n", User1);
	printf("\tBlack User: %d\n", User2);
	printf("\n\n");
}
	
	
int userplay(){
	printf("좌표를 입력하세요(x, y)\n입력:");
	scanf("%d %d", &x, &y);
	
	map[y][x] = user;
}
int turn(){
	printf("\n\n\n\n\n\n**************턴을 전환합니다**************\n\n\n\n\n\n"); // 여기서 턴 전환 부분 코딩
	if (user == 1){
		user = 2;
		userval = 1;
	}
	else if(user == 2) {
		user = 1;
		userval =2;
	}
}

