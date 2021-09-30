#include <iostream>
#include <cstdio>
#include <string>
#include <cwchar>
#include <climits>

int main() {
	printf("Введите ключ для шифрования: (число, положительное или отрицательное)\n");
	int key = 0;
	std::wcin >> key;
	std::wcin.ignore(INT_MAX,'\n'); //clearing input buffer
	key %= 26; //make sure key wraps back around the latin alphabet
	std::wstring str;
	printf("Введите текст для шифрования: (только ASCII - латиница и символы)\n");
	std::getline(std::wcin, str);
	printf("\n");
	for (std::wstring::iterator it=str.begin(); it!=str.end(); ++it) {
		if ( (*it) < 91 && (*it) > 64 ) { //if character is latin uppercase
			if ( ((*it)+key) < 65 ) { //wrapping from A to Z
				std::wcout << (wchar_t)( 91 - (65 - ((*it)+key)));
			} else if ( ((*it)+key) > 90 ) { //wrapping from Z to A
				std::wcout << (wchar_t)( 64 + ( ((*it)+key) - 90));
			} else std::wcout << (wchar_t)((*it)+key); //no wrapping
		} else if ( (*it) < 123 && (*it) > 96 ) { //if character is latin lowercase
			if ( ((*it)+key) < 97 ) { //wrapping from a to z
				std::wcout << (wchar_t)( 123 - (97 - ((*it)+key)));
			} else if ( ((*it)+key) > 122 ) { //wrapping from z to a
				std::wcout << (wchar_t)( 96 + ( ((*it)+key) - 122));
			} else std::wcout << (wchar_t)((*it)+key); //no wrapping
		} else std::wcout << (wchar_t)(*it); //if character is something else
	}
	std::wcout << std::endl;
	return 0;
}
