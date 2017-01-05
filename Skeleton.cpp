#include <stdio.h>
#include <stdlib.h>

int x, y;
int map[8][8]; 
int total; // total = User1 + User2
int user = 2;
int userval = 1;
int User1, User2;


void printM(); //��ü ��� ����
void initialize(); // ������ ���� 
void game();	// ���� ���� ���� ���
int userplay(); //������ ���� �ٵ��� ����
int turn();//�� ����
int checkNchange(int x, int y, int userval, int user); //�� ��ȭ ���

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

void game(){ //���� ���
	
}

int checkNchange(int x, int y, int userval, int user)//�� �� ����
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


void initialize(){ // ������ ������
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			map[i][j]=0;
		}
	}
	map[3][3]=map[4][4]=1;
	map[3][4]=map[4][3]=2;		

	total= 4;
}

void printM(){// ��ü ��� ����
	int i;
	for(i=0; i<35; i++) printf("#");  //���� Ÿ��Ʋ ��º�
	printf("\n\t OTHELLO GAME\n");
	for(i=0; i<35; i++) printf("#");
	printf("\n\n");
	
	printf("\t  ");
	for(int j=0; j<8; j++) printf("%d ", j);
	printf("\n");
	
	for(i=0; i<8; i++){
		printf("\t");
		printf("%d ", i);
		for(int j=0; j<8; j++){					//������ ��º�
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
	printf("��ǥ�� �Է��ϼ���(x, y)\n�Է�:");
	scanf("%d %d", &x, &y);
	
	map[y][x] = user;
}
int turn(){
	printf("\n\n\n\n\n\n**************���� ��ȯ�մϴ�**************\n\n\n\n\n\n"); // ���⼭ �� ��ȯ �κ� �ڵ�
	if (user == 1){
		user = 2;
		userval = 1;
	}
	else if(user == 2) {
		user = 1;
		userval =2;
	}
}

