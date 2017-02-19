#include <fstream> 
#include <iostream> 
#include <math.h> 
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

void prompt();
double** readFile();
double length(double*x) {
	double res=0;
	for (int i = 0; i < 3;i++) res+= pow(x[i],2);
	return sqrt(res);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	double **x = readFile();


	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cout << x[i][j]<<" ";
		} cout << endl;
	}

	double min=length(x[0]);
	int index;
	for (int i = 1; i < 6; i++) {
		double chk = length(x[i]);
		if (chk < min) {
			min = chk;
			 index = i+1;
		}
	}
	cout << endl << "������ ����� " << index << " �� �������� �������";
	cout <<endl<< min<<endl;

	prompt();
	return 0;
}
void prompt() {
	std::cout << std::endl << "�� ���?? " << "ESC - �����" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}

double** readFile() {

	std::ifstream ars("C:\\Users\\MaxRev\\Desktop\\MyArs3.txt");

	if (ars.is_open())
	{
		int i = 0, n = 0, non = 0, arr = 0, spacer;
		// DO YOU BELIEVE IN 3D ARRAY???
		// n -> char
		// non -> it's position in array
		// arr -> number of array

		char sym;

		char ***arrsOfNums = new char**[6];
		for (int i = 0; i < 6; i++) arrsOfNums[i] = new char*[50];

		for (int i = 0; i < 6; i++) {
			for (int ii = 0; ii < 50; ii++) {
				arrsOfNums[i][ii] = new char[10];
			}
		}

		while (!ars.eof()) {
			ars.get(sym);
			if (sym == '-' || sym == '.' || isdigit(sym)) {
				arrsOfNums[arr][non][n] = sym;
				n++;
				spacer = 0;
			}
			else if (sym == ' ') {
				if (spacer == 0) {
					non++; n = 0; spacer++;
				}
			}
			else if (sym == '\n') {
				arr++; non = 0; n = 0;
			}
		}

		//convert array... to double nums
		int k = 6, l = 3;
		double **x = new double*[k];
		for (int i = 0; i < k; i++) x[i] = new double[10];
		std::cout << std::endl << "������ � �����..." << std::endl;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < l; j++) {
				x[i][j] = strtold(arrsOfNums[i][j], NULL);
			}
		}
	


		ars.close();
		return x;
	}
	else
	{
		std::cout << "���� �� ��������.";
		return nullptr;
	}

}