#include "extend.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student *x = new Student;
	readFile(ifstream(path));
	_getch();
	return 0;
}
void prompt() {
	std::cout << std::endl << "Retry?? " << "ESC - exit" << std::endl;
	_getch();
	if (GetAsyncKeyState(VK_ESCAPE)) exit(0);
	else main();
}
void prompt(int x) {
	if (x) main();
}