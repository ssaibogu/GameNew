#include "NOVELBETA.h"


struct location_ 
{

	string name; 
	string descr; 

};

location_ location[4]; 


void InitGame() {
	location[0].name = "���� �����"; 
	location[0].descr = "����� ������������ ������������ � ������������ �������. ������������ ������� ��� �������";
	location[1].name = "�������";
	location[1].descr = "������� ���������� �������";







}

int main() {
	setlocale(LC_ALL, "Russian");
	/*int temp[5] = { 1,6,-5,4,-9 };
	temp[0] = 7;*/

	// ��: ������� ����� �� ������� temp � ������� ����������� (����������� �����)
	// ��������� �������, ��������� ��������
	// ���������� - ������, �������� � ���������
	InitGame();

	for (int i = 0; i < 2; i++) {

		cout << location[i].name; cout << endl;

	
	}
		
		
	
	



}