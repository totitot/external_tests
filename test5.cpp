#include <iostream>
#include <windows.h>

using namespace std;

int main(){
	char ch;
	while(1){
		ch = cin.get();
		cin.ignore();
		cout << static_cast<int>(ch) << endl;
		Sleep(500);
	}
}
