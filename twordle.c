//Michael Carine
#include<stdio.h>
#define STRINGSIZE 5
#define GUESS 6
#define WORDFILE "word.txt"

//function prototype:
int charactercheck(int* rowindex, int column, char guess[][column],char answer[]);
void saveanswerfunction(FILE* Wordfile, int column, char answer[]);
void saveguessfunction(int* rowindex, int column, char guess[][column]);
int comparisonfunction(int* partial,int column, int rowindex, char answer[], char guess[][row]);
void turnlowercase(int* rowindex, int column, char singleguess[]);
void misplacedletter(int *rowindex, int column, char guess[][column],char answer[]);
void correctletter(int *rowindex, int column, char guess[][column],char answer[]);
//main 
int main(){
FILE* wordfile; 
char Answer[STRINGSIZE]; 
char Guess[GUESS][STRINGSIZE];
int* PartiallyCorrect; 

//file section
wordfile = fopen(WORDFILE,"r");
	if(wordfile == NULL){
	printf("file did not open");
	return 0; 
	}
saveanswerfunction(wordfile,STRINGSIZE,Answer);
	fclose(wordfile);

for(int *rowindex = 0; *rowindex < GUESS; *rowindex++){
  printf("Guess the Word:");
  scanf("%s", Guess[*rowindex]);
  saveguessfunction(&rowindex, STRINGSIZE, Guess[STRINGSIZE]);
  turnlowercase(&rowindex, STRINGSIZE, Guess[STRINGSIZE]);
  charactercheck(&rowindex, STRINGSIZE, Guess[STRINGSIZE], Answer);
 if(charactercheck > 0){
 printf("invalid characters");
 return 0; 
 }
  comparisonfunction(&PartiallyCorrect, STRINGSIZE, &rowindex, Answer, Guess[STRINGSIZE]); 
  
 else if(comparisonfunction(&PartiallyCorrect, STRINGSIZE, &rowindex, Answer, Guess[STRINGSIZE])== 5){
correctletter(&rowindex, STRINGSIZE, Answer[], Guess[STRINGSIZE]);
printf("you win"); 
 }
 else if (comparisonfunction(&PartiallyCorrect, STRINGSIZE, &rowindex, Answer, Guess[STRINGSIZE]) >= 1 && *PartiallyCorrect => 1){
 correctletter(&rowindex, STRINGSIZE, Answer, Guess[STRINGSIZE]);
 printf("%c",Guess); 
 misplacedletter(&rowindex, STRINGSIZE, Answer, Guess[STRINGSIZE]);
 }
 else if (comparisonfunction(&PartiallyCorrect, STRINGSIZE, &rowindex, Answer, Guess[STRINGSIZE])  == 0 &&*PartiallyCorrect >= 1){
 printf("%c",Guess); 
 misplacedletter(&rowindex, STRINGSIZE, Answer, Guess[STRINGSIZE]);
 }
 else if (comparisonfunction(&PartiallyCorrect, STRINGSIZE, &rowindex, Answer, Guess[STRINGSIZE])  >= 1 && *PartiallyCorrect == 0){
 correctletter(&rowindex, STRINGSIZE, Answer, Guess[STRINGSIZE]);
 printf("%c",Guess); 
 }
return 0; 
}
//function Definitions: 
void saveanswerfunction(FILE* Wordfile,int column, char answer[]){
 int columnindex; 
 	for(columnindex = 0; columnindex < column; colmunindex++){
 	fscanf(answer,"%c", answer[columnindex])
 	}
}
void saveguessfunction(int* rowindex, int column, char guess[][column]){
 int columnindex; 
       for(columnindex = 0; columnindex < column; columnindex++){
       scanf("%s",guess[*rowindex][columnindex])
       }
}

int comparisonfunction(int* partial, int column, int* rowindex, char answer[], char guess[][column]){
 int columnindex; 
int numcorrect = 0; 
int partiallycorrect = 0; 
  for(columnindex = 0; columnindex < column; columnindex++){
		if(guess[rowindex][columnindex] == answer[columnindex]){
	numcorrect++; 
	}
		else if(guess[rowindex][columnindex] == answer[columnindex]||guess[*rowindex][columnindex+2] == answer[0]||guess[*rowindex][columnindex+1] == answer[columnindex+3]|| 
		guess[*rowindex][columnindex+4] == answer[columnindex]||guess[*rowindex][columnindex+5] == answer[columnindex]){
	partiallycorrect++; 	
		}
  }
*partial = partiallycorrect; 
return numcorrect;
}

void turnlowercase(int column,int* rowindex, char guess[][row]){
 int columnindex; 
 for(columnindex = 0; columnindex < column; columnindex++){
 if(guess <= 132 && guess >= 101){
 guess[*rowindex][columnindex] + 32; 
 }
 else;
 }
}
void misplacedletter(int* rowindex, int column, char guess[][column], char answer[]){
  int columnindex;
  printf("\n"); 
  for(columnindex = 0; columnindex < column; columnindex++){
   if(guess[*rowindex][columnindex]== answer[columnindex]||guess[*rowindex][columnindex] == answer[columnindex]||guess[*rowindex][columnindex+2] == answer[0]||guess[*rowindex][columnindex+1] == answer[columnindex+3]||guess[*rowindex][columnindex+4] == answer[columnindex]||guess[*rowindex][columnindex+5] == answer[columnindex]){
   printf("^"); 
   }
  }
}
void correctletter(int* rowindex, int column, char guess[][column], char answer[]){
 int columnindex; 
 for(columnindex = 0; columnindex < column; columnindex++){
	if(guess[*rowindex][columnindex]== answer[columnindex]||guess[*rowindex][columnindex] == answer[columnindex]||guess[*rowindex][columnindex+2] == answer[0]||guess[*rowindex][columnindex+1] == answer[columnindex+3]||guess[*rowindex][columnindex+4] == answer[columnindex]||guess[*rowindex][columnindex+5] == answer[columnindex]){
   guess[*rowindex][columnindex] - 32; 
   }
  }
}
int charactercheck(int* rowindex, int column, char guess[][column],char answer[]){
int columnindex;
int num = 0; 
  for(columnindex = 0; columnindex < column; columnindex++){
	if(guess[*rowindex][columnindex] >= 141 && guess[*rowindex][columnindex] <= 172){
	num++;
	}
	}
return num; 
}

