#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Arr[8][8]; 
int User1, User2; // variables which means counts of each user's stone
int total;

void printM(); // print Matrix
void initialize(); // initialize variables 
void game();
int checkNchange(int row, int col, int User);
int isPass(int User);

int main(void){
	
	int row, col;
	
	initialize();		
	game();

}

void check(){
	
	User1=0, User2=0;
	for(int x=0; x<8; x++){
		for(int y=0; y<8; y++){
			if(Arr[x][y]==2) User1++;
			if(Arr[x][y]==1) User2++;
		}
	}
	
}

void game(){
	
	

	
}

int isPass(int User){
	
	int isit=0, i, j;
	for(int row=0; row<8; row++){
		for(int col=0; col<8; col++){
			if(Arr[row][col]==0){
				
				i=col-1;
				while(i>=0){
					if(Arr[row][i]==0 ) break;
					if(i==col-1 && Arr[row][i]==User) break;
					
					if(i!= col-1 && Arr[row][i]==User){
						isit=1;
						break;
					}
					i--;
			 	}
			 	i=col+1;
			 	while(i<8){
			 		if(Arr[row][i]==0) break;
			 		if(i==col+1 && Arr[row][i]==User) break;
			 		
					if(i!=col+1 &&  Arr[row][i]==User){
						isit=1;
						break;
					}
					i++;
			 	}
			 	
			 	i=row-1;
			 	while(i>=0){
			 		if(Arr[i][col]==0) break;
			 		if(i==row-1 && Arr[i][col]==User) break;
			 		
			 		if(i!=row-1 && Arr[i][col]==User ){
			 			isit=1;
			 			break;
			 		}
			 		i--;
			 	}
				i=row+1;
				while(i<8){
					if(Arr[i][col]==0) break;
					if(i==row+1 && Arr[i][col]==User) break;
					
					if(i!=row+1 && Arr[i][col]==User){
						isit=1;
			 			break;
					}
					i++;
				}
			 	
			 	i=1;
			 	while(row-i>=0 && col-i>=0){
			 		if(Arr[row-i][col-i]==0) break;
			 		if(i==1 && Arr[row-i][col-i]==User) break;			 		
			 		
			 		if(i!=1 && Arr[row-i][col-i]==User){
			 			isit=1;
			 			break;
			 		}
			 		i++;
			 	}
			 	i=1;
			 	while(row+i<8 && col+i<8){
			 		if(Arr[row+i][col+i]==0) break;
			 		if(i==1 && Arr[row+i][col+i]==User) break;
			 		
			 		if(i!=1 && Arr[row+i][col+i]==User){
			 			isit=1;
			 			break;
			 		}
			 		i++;
			 	}
			 	
			 	i=1;
			 	while(row+i<8 && col-i>=0){
			 		if(Arr[row+i][col-i]==0) break;
			 		if(i==1 && Arr[row+i][col-i]==User) break;
			 		
			 		if(i!=1 && Arr[row+i][col-i]==User){
			 			isit=1;
			 			break;
			 		}
			 		i++;
			 	}
			 	i=1;
			 	while(row-i>=0 && col+i<8){
			 		if(Arr[row-i][col+i]==0 ) break;
			 		if(i==1 && Arr[row-i][col+i]==User) break;
			 		
			 		if(i!=1 && Arr[row-i][col+i]==User){
			 			isit=1;
			 			break;
			 		}
			 		i++;
			 	}	
			}
		}
	}
	
	if (isit==0) return 0;
	return 1;
}



int checkNchange(int row, int col, int User){

}


void initialize(){
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			Arr[i][j]=0;
		}
	}
	Arr[3][3]=Arr[4][4]=1;
	Arr[3][4]=Arr[4][3]=-1;		

	User1= User2=2;
	total= 4;
}

void printM(){
	int i;
	for(i=0; i<35; i++) printf("#");
	printf("\n\n\t OTHELLO GAME\n\n");
	for(i=0; i<35; i++) printf("#");
	printf("\n\n");
	
	printf("\t  ");
	for(int j=0; j<8; j++) printf("%d ", j);
	printf("\n");
	
	for(i=0; i<8; i++){
		printf("\t");
		printf("%d ", i);
		for(int j=0; j<8; j++){
			if(Arr[i][j]==0) printf(". ");
			else if(Arr[i][j]==-1) printf("O ");
			else printf("X ");		
		}
		printf("\n");
	}
	printf("\n\n");
	printf("\tWhite User: %d\n", User1);
	printf("\tBlack User: %d\n", User2);
	printf("\n\n");
	
}	



//예외케이스
/*	
	//흰돌 -1 
	for(int i=2; i<6; i++){
		for(int j=0; j<=5; j++){
			if(i==3 && j==1) Arr[i][j]=0;
			else if(i==3 && j==3) Arr[i][j]=1;
			else Arr[i][j]=-1;
		}
	}
	Arr[6][0]=-1;
	Arr[6][2]=-1;
	Arr[6][3]=-1;
	Arr[1][3]=-1;
	Arr[1][4]=-1;
	Arr[0][2]=-1;
	Arr[4][6]=-1;
	//검은돌 1 
	for(int i=3; i<6; i++) Arr[7][i]=1;
	for(int i=4; i<8; i++) Arr[0][i]=1;
	for(int i=5; i<8; i++) Arr[1][i]=1;
	for(int i=6; i<8; i++) Arr[2][i]=1;
	for(int i=3; i<6; i++) Arr[i][7]=1;
	
	printM();
	getch();
	
	printf("\nHERE : %d %d\n", isPass(-1),Arr[3][1] );
	checkNchange(3,1,1);
	printM();
*/ 

