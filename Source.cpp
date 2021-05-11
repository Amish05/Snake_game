#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include<conio.h>

using namespace std;

void gotoxy(int x, int y);

void print_Box(int weidth,int height) {
	char box = 219;
	for (int i = 0; i < height; i++) {
		gotoxy(0, i);
		cout << box;
		gotoxy(weidth, i);
		cout << box;
	}
	for (int i = 0; i < weidth+1; i++) {
		gotoxy(i, 0);
		cout << box;
		gotoxy(i, height);
		cout << box;
	}
}

struct snake_loc {
	int x;
	int y;
};

struct heardles {
	int x;
	int y;
};

void Displaysnake(int length,snake_loc point[]) {
	char snake = 240;
	for (int index = 0; index < length; index++) {
		if (point[index].x != 0 && point[index].y != 0) {
			gotoxy(point[index].x, point[index].y);
			cout << snake;
		}
	}
}

void Displayheardels(int length, heardles heradle[]) {
	char ch = 178;
	for (int index = 0; index < length; index++) {
		gotoxy(heradle[index].x, heradle[index].y);
		cout <<ch;
	}
}

void Removesnake(int length, snake_loc point[]) {
	for (int index = 0; index < length; index++) {
		if (point[index].x != 0 && point[index].y != 0) {
			gotoxy(point[index].x, point[index].y);
			cout << " ";
		}
	}
}

void Movementup(int length, snake_loc point[]) {
	int index;
	for (index = length; index > 0; index--) {
		point[index].x = point[index - 1].x;
		point[index].y = point[index - 1].y;
	}
	point[index].y = point[index].y-1;
}

void Movementdown(int length, snake_loc point[]) {
	int index;
	for (index = length; index > 0; index--) {
		point[index].x = point[index - 1].x;
		point[index].y = point[index - 1].y;
	}
	point[index].y = point[index].y + 1;

}

void Movementleft(int length, snake_loc point[]) {
	int index;
	for (index = length; index > 0; index--) {
		point[index].x = point[index - 1].x;
		point[index].y = point[index - 1].y;
	}
	point[index].x = point[index].x - 1;

}

void Movementright(int length, snake_loc point[]) {
	int index;
	for (index = length; index > 0; index--) {
		point[index].x = point[index - 1].x;
		point[index].y = point[index - 1].y;
	}
	point[index].x = point[index].x + 1;

}

char Movement(int length, char move, snake_loc point[], char stop_to_move_reverse) {
// KEY_UP 72

// KEY_DOWN 80

// KEY_LEFT 75

// KEY_RIGHT 77
	if (move == 72 && stop_to_move_reverse != 80) {
		Movementup(length, point);
		stop_to_move_reverse = move;
	}
	
	else if (move == 80 && stop_to_move_reverse != 72) {
		Movementdown(length, point);
		stop_to_move_reverse = move;
	}
	
	else if (move == 75 && stop_to_move_reverse != 77) {
		Movementleft(length, point);
		stop_to_move_reverse = move;
	}
	
	else if (move == 77 && stop_to_move_reverse != 75) {
		Movementright(length, point);
		stop_to_move_reverse = move;
	}
	else if (stop_to_move_reverse == 72 ) {
		Movementup(length, point);
			}
	else if (stop_to_move_reverse == 80 ) {
		Movementdown(length, point);
			}
	
	else if (stop_to_move_reverse == 75) {
		Movementleft(length, point);
		
	}
	
	else if (stop_to_move_reverse == 77) {
		Movementright(length, point);
		
	}
	
	return  stop_to_move_reverse;
}

int check_wall(int weidth,int height, snake_loc point[]) {
	if (point[0].x > 79) {
		return 0;
	}
	if (point[0].x <1) {
		return 0;
	}
	if (point[0].y > 28) {
		return 0;
	}
	if (point[0].y < 1) {
		return 0;
	}

}

int food_on_heardle(int length, int food_index[],heardles heardle[]) {
	for (int index = 0; index < length; index++) {
		if (food_index[0] == heardle[index].x && food_index[1] == heardle[index].y) {
			return 1;
		}
	}
	return 0;
}

void print_food(int food_index[], heardles heardle1[9], heardles heardle2[9], heardles heardle3[10], heardles heardle4[10]) {
	char food = 233;
	int food_on_heardle_val;
	int x=  rand() % 79;
	int y = rand() % 28;
	food_index[0] = x;
	food_index[1] = y;
	food_on_heardle_val = food_on_heardle(9, food_index, heardle1);
	food_on_heardle_val = food_on_heardle(9, food_index, heardle2);
	food_on_heardle_val = food_on_heardle(10, food_index, heardle3);
	food_on_heardle_val = food_on_heardle(10, food_index, heardle4);
	if (food_on_heardle_val == 1) {
		print_food(food_index, heardle1, heardle2, heardle3, heardle4);
	}
	gotoxy(x, y);
	cout << food;
	}

void heardles_arr1(heardles heardle1[]) {
		/*

	@@@@@@@@
		   @
		   @
		   @
		   @

	*/
	int x = 68;
	int y = 3;
	heardle1[0].x = x;
	heardle1[0].y = y;
	for (int index = 1; index < 5; index++) {
		heardle1[index].x = x++;		
		heardle1[index].y = y;
	}
	for (int index = 1; index < 5; index++) {
		heardle1[index + 4].x = x;
		heardle1[index + 4].y = y++;
		
	}

}

void heardles_arr2(heardles heardle2[]) {
	/*

	@@@@@@@@
	@
	@
	@
	@

	*/
	int x = 12;
	int y = 3;
	heardle2[0].x = x;
	heardle2[0].y = y;
	for (int index = 1; index < 5; index++) {
		heardle2[index].x = x--;
		heardle2[index].y = y;
	}
	for (int index = 1; index < 5; index++) {
		heardle2[index + 4].x = x;
		heardle2[index + 4].y = y++;

	}
}

void heardles_arr3(heardles heardle3[]) {
	/*

		   @
		   @
		   @
		   @
	@@@@@@@@

	*/
	int x =72;
	int y = 20;
	heardle3[0].x = x;
	heardle3[0].y = y;
	for (int index = 1; index < 5; index++) {
		heardle3[index].x = x;
		heardle3[index].y = y++;
	}
	
	for (int index = 1; index < 6; index++) {
		heardle3[index + 4].y = y-1;
		heardle3[index + 4].x = x--;
	}
}

void heardles_arr4(heardles heardle4[]) {
	/*

	@
	@
	@
	@
	@@@@@@@@

	*/
	int x = 8;
	int y = 20;
	heardle4[0].x = x;
	heardle4[0].y = y;
		for (int index = 1; index < 5; index++) {
		heardle4[index + 4].y = y++;
		heardle4[index + 4].x = x;
	}
		for (int index = 1; index < 6; index++) {
			heardle4[index].x = x++;
			heardle4[index].y = y-1;
		}

}

int food_action(int food_index[], int food_value, snake_loc point[], heardles heardle1[9], heardles heardle2[9], heardles heardle3[10], heardles heardle4[10]) {
	string level;
	if (food_index[0] == point[0].x && food_index[1] == point[0].y) {
		print_food(food_index, heardle1, heardle2, heardle3, heardle4);
		food_value++;
		
	}
	if (food_value <= 10) {
		 level = "Easy";
		
	}
	if (food_value <= 20 && food_value>10) {
		level = { 'I','n','t','e','r','m','e','d','i','a','t','e' };
		
	}
	if (food_value <= 30&& food_value>20) {
		level = { 'P','r','e','m','i','e','r' };
		
	}
	if (food_value > 30) {
		level = { 'S','n','a','k','e',' ','M','a','S','t','e','r' };
		
	}
	gotoxy(83, 2);
	cout << "Score : " << food_value;
	gotoxy(83, 3);
	cout << "level : ";
	cout << level;
	gotoxy(83, 4);
	cout << " Press any arrow key to start game.";
	return food_value;
}

int snake_touch_heardles(snake_loc point[], heardles heardle[],int lenght ) {
	for (int index = 0; index < lenght; index++) {
		if (point[0].x == heardle[index].x && point[0].y == heardle[index].y) {
			return 1;
		}
	}
	return 0;
}

int check_heardles(snake_loc point[], heardles heardle1[9], heardles heardle2[9], heardles heardle3[10], heardles heardle4[10],int food_value) {
	int check_heardles_value=0;
	if (food_value <= 10) {
		Displayheardels(9, heardle1);
		check_heardles_value = snake_touch_heardles(point, heardle1, 9);
		if (check_heardles_value == 1) {
			return check_heardles_value;
		}
	}
	if (food_value <= 20 && food_value > 10) {
		Displayheardels(9, heardle2);
		check_heardles_value = snake_touch_heardles(point, heardle2, 9);
		if (check_heardles_value == 1) {
			return check_heardles_value;
		}
	}
	if (food_value <= 30 && food_value > 20) {
		Displayheardels(10, heardle3);
		check_heardles_value = snake_touch_heardles(point, heardle3, 10);
		if (check_heardles_value == 1) {
			return check_heardles_value;
		}
	}
	if (food_value > 30) {
		Displayheardels(10, heardle4);
		check_heardles_value = snake_touch_heardles(point, heardle4, 10);
		if (check_heardles_value == 1) {
			return check_heardles_value;
		}
		
	}

}

void game_over() {
	gotoxy(40, 15);
	cout << "you loss!";
	}

int speed_action(int speed,int food_value) {
	
	if (food_value <= 10) {
		speed = 500;
	}
	if (food_value <= 20 && food_value > 10) {
		speed = 400;
	}
	if (food_value <= 30 && food_value > 20) {
		speed = 300;
	}
	if (food_value >= 30) {
		speed = 200;
	}
	if (food_value > 40) {
		speed = 100;
	}
	return speed;
}

int snake_touch_body(snake_loc point[],int length) {
	for (int i = 1; i < length; i++) {
		if (point[0].x == point[i].x && point[0].y == point[i].y) {
			return 1;
		}
	}
	return 0;
}


void intro() {
	cout << "       $$$$    NN       N        A         K      K   EEEEEE    \n";
	cout << "     $      $  N N      N       A A        K     K    E         \n";
	cout << "    $          N  N     N      A   A       K    K     E         \n";
	cout << "       $       N   N    N     A     A      K  K       E         \n";
	cout << "           $   N    N   N    AAAAAAAAA     KKK        EEEEEE    \n";
	cout << "            $  N     N  N   A         A    K   K      E         \n";
	cout << "   $      $    N      N N  A           A   K     K    E         \n";
	cout << "     $$$$      N       NN A             A  K       K  EEEEEE    \n";
	cout << "                                                                                        \n";
	Sleep(500);
	cout << "   GGGGGGGGG           A         M         M  EEEEEE \n";
	cout << "   G        G         A A        MM       MM  E          \n";
	cout << "   G                 A   A       M M     M M  E            \n";
	cout << "   G                A     A      M  M   M  M  E              \n";
	cout << "   G     GGG       AAAAAAAAA     M   M M   M  EEEEEE       \n";
	cout << "   G   G    G     A         A    M    M    M  E                  \n";
	cout << "   G        G    A           A   M         M  E                    \n";
	cout << "   GGGGGGGGGG   A             A  M         M  EEEEEE             \n";
	cout << "                                                                                        ";
	Sleep(500);
	system("CLS");
	cout << endl;
	cout << endl;
	cout << "                                Powerd By:                                                      \n";
	Sleep(300);
	cout << "                                          AMISH ALI(BSSE/053/FA20)                              ";
	Sleep(500);
	system("CLS");
	Sleep(300);
	cout << "\n\n                                Powerd By:                                                      \n";
	cout << "                                          AMISH ALI(BSSE/053/FA20)                              ";
	Sleep(500);
	system("CLS");
	Sleep(300);
	cout << "\n\n                                Powerd By:                                                      \n";
	cout << "                                          AMISH ALI(BSSE/053/FA20)                              "; 
	Sleep(500);
	system("CLS");
	Sleep(300);
	cout << "\n\n                                Powerd By:                                                      \n";
	cout << "                                          AMISH ALI(BSSE/053/FA20)                              ";
	Sleep(500);
	system("CLS");
	Sleep(300);
	cout << "\n\n                                         3                                               ";
	Sleep(500);
	system("CLS");
	Sleep(300);
	cout << "\n\n                                         2                                               ";
	Sleep(500);
	system("CLS");
	Sleep(300);
	cout << "\n\n                                         1                                               ";
	Sleep(500);
	system("CLS");
}

int main(){
	intro();
	heardles heardle1[9], heardle2[9], heardle3[10], heardle4[10];
	snake_loc  point[100];
	int food_index[2],food_value=0,eat_food=0,level=0;
	int speed = 500;
	int height = 29;
	int weidth = 80;
	int length =5;
	char ch = 'r',food=233;
	char stop_to_move_reverse = 'r';
	int snake_x[100] = { 20,20,20,20,20 };
	int snake_y[100] = { 20,21,22,23,24 };
	for (int i = 0; i < length; i++) {
		point[i].x = snake_x[i];
		point[i].y = snake_y[i];
	}
	print_food(food_index, heardle1, heardle2, heardle3, heardle4);
	print_Box(weidth, height);
	heardles_arr1(heardle1);
	heardles_arr2(heardle2);
	heardles_arr3(heardle3);
	heardles_arr4(heardle4);
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			ch = _getch();
		}
		gotoxy(food_index[0], food_index[1]);
		
		cout << food;
		// snake length
		if (food_value == eat_food + 1) {
				length++;
				eat_food++;
		}
		//snake length end
		Displaysnake(length,point);
				
		Sleep(speed);
				
		Removesnake(length, point);
		
		stop_to_move_reverse=Movement(length, ch, point,stop_to_move_reverse);

		food_value=food_action(food_index,food_value,point, heardle1, heardle2, heardle3, heardle4);

		speed=speed_action(speed,food_value);
		
		Displaysnake(length, point);
		
		if (snake_touch_body(point, length) == 1) {
			game_over();
			break;
		}
		int heardle_check=check_heardles(point, heardle1, heardle2, heardle3, heardle4,food_value);
		
		if (heardle_check == 1) {
			game_over();
			break;
		}
		
		if (check_wall(height,weidth,point) == 0) {
			game_over();
			break;
		}
		
		
	}	
	gotoxy(81, 31);

}
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 