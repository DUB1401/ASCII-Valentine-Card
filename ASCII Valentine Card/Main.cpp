#include <Windows.h>
#include <iostream>
#include <vector>

// Стандартные цвета, доступные для установки в консоль Windows.
enum class CMD_Colors { clBlack = 0, clBlue, clGreen, clCyan, clRed, clMagenta, clBrown, clLightGray, clDarkGrey, clLightBlue, clLightGreen, clLightCyan, clLightRed, clLightMagenta, clYellow, clWhite };

// Вектор, хранящий ASCII сердце.
std::vector<std::wstring> Hurt = {
	L"",
	L"                       @@@@@@           @@@@@@",
	L"                     @@@@@@@@@@       @@@@@@@@@@",
	L"                   @@@@@@@@@@@@@@   @@@@@@@@@@@@@@",
	L"                 @@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@",
	L"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"                     @@@@@@@@@@@@@@@@@@@@@@@@@@@",
	L"                       @@@@@@@@@@@@@@@@@@@@@@@",
	L"                         @@@@@@@@@@@@@@@@@@@",
	L"                           @@@@@@@@@@@@@@@",
	L"                             @@@@@@@@@@@",
	L"                               @@@@@@@",
	L"                                 @@@",
	L"                                  @"
};

// Вектор, хранящий подпись.
std::vector<std::wstring> Label = {
	L"                            I",
	L"LOVE",
	L"YOU!!!"
};

// Главная функция: точка входа.
int main(int argc, char* argv[]) {
	// Получение Handle окна консоли.
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Циклический вывод сердца и подписи.
	while (true) {
		// Установка красного цвета текста.
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | static_cast<unsigned>(CMD_Colors::clLightRed)));

		// Вывод сердца.
		for (unsigned int i = 0; i < Hurt.size(); i++) { 
			Sleep(30);
			std::wcout << Hurt[i] << std::endl;
		}

		// Установка белого цвета текста.
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | static_cast<unsigned>(CMD_Colors::clLightGray)));

		// Отступ двух строк.
		std::wcout << std::endl << std::endl;

		// Вывод подписи.
		for (unsigned int i = 0; i < Label.size(); i++) {
			Sleep(750);
			std::wcout << Label[i] << L" ";

			// Если выведена последняя часть, перейти на новую строку.
			if (i == Label.size() - 1) std::wcout << std::endl;
		}

		// Интервал анимации сердца.
		Sleep(3000);
		// Очистка терминала.
		system("cls");
	}

	return 0;
}