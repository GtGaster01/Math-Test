#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//Function declarations

int addition(int number1, int number2);
int subtraction(int number1, int number2);
int multiplication(int number1, int number2);
int division(int number1, int number2);
void test(int level, int *point);

int main(){
	int level=1, point=0;
	char nextLevel;
	
	srand(time(NULL));
	
	// Get the starting level from the user
	
	printf("Enter the level you want to start from. (1-10)\n");
	scanf("%d", &level);
	
	if(level<1||level>10){
		printf("Invalid level! Starting from level 1 by default.\n");
		level=1;
	}
	while(1){
		printf("Level %d is starting....\n", level);
		test(level, &point);
		printf("Your score: %d\n", point);
		
		printf("Do you want to proceed to the next level? (y/n)\n");
		nextLevel=getch();
		if(nextLevel=='y'){
			level++;
		}
		else if(nextLevel=='n'){
			printf("Game over! Your final score: %d", point);
			break;
		}
		else{
			printf("Incorrect entry! Game over! Final score: %d", point);
			break;
		}		
	}
	getch();
	return 0;	
}

// Arithmetic functions

int addition(int number1, int number2){
	return number1 + number2;
}
int subtraction(int number1, int number2){
	return number1 - number2;
}
int multiplication(int number1, int number2){
	return number1 * number2;
}
int division(int number1, int number2){
	return number1 / number2;
}

// Test function

void test(int level, int *point){
	int operation, result, answer, number1, number2;
	for(int i=0; i<10; i++){
		// Determine the range of numbers based on the level
		
		int max= 10 + (level*10);
		number1 = rand() % max+1;
		number2 = rand() % max+1;
		
		 // Randomly select an operation
		 
		operation = rand() %4+1;
		switch(operation){
			case 1:
				result = addition(number1, number2);
				printf("%d + %d=?\n", number1, number2);
				break;
			case 2:
				result = subtraction(number1, number2);
				printf("%d - %d=?\n", number1, number2);
				break;
			case 3:
				result = multiplication(number1, number2);
				printf("%d * %d=?\n", number1, number2);
				break;
			case 4:
				
				// Check for division by zero and ensure perfect division
				
				while(number2==0||number1 % number2!=0){
					number1 = rand() %max+1;
					number2 = rand() %max+1;
				}
				result = division(number1, number2);
				printf("%d / %d=?\n", number1, number2);
				break;
			
		}
		
		// User's answer
		
		scanf("%d", &answer);
		if(result == answer){
			printf("Correct! +%d points!\n", 10*level);
			*point += 10*level;
		}else{
			printf("Wrong! -%d points!\n", 10*level);
			*point -= 10*level;
		}
	}
}
