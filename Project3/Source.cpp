#include "NOVELBETA.h"


struct location_ 
{

	string name; 
	string descr; 

};

location_ location[4]; 


void InitGame() {
	location[0].name = "Зона удара"; 
	location[0].descr = "Место болезненного столкновения с поверхностью планеты. Спасательная капусла ещё дымится";
	location[1].name = "Коридор";
	location[1].descr = "Длинный запустелый коридор";







}

int main() {
	setlocale(LC_ALL, "Russian");
	/*int temp[5] = { 1,6,-5,4,-9 };
	temp[0] = 7;*/

	// ДЗ: вывести числа из массива temp в порядке возрастания (пузырьковый метод)fghfgh
	// Расписать локации, продумать механики
	// Контейнеры - вектор, операции с векторами
	InitGame();

	for (int i = 0; i < 2; i++) {

		cout << location[i].name; cout << endl;

	
	}
		
		
	
	



}