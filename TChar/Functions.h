#pragma once

#include <tchar.h>
#include <iostream>

using namespace std;

void space_to_slash_t(TCHAR str[]) {
	unsigned short i = 0;
	do {
		if (str[i] == ' ')
			str[i] = '\t';
	} while (str[i++] != '\0');
}

void count_of_letters_numbers_and_other(TCHAR str[]) {	//	Коротко и ясно
	unsigned short numbers = 0;
	unsigned short letters = 0;
	unsigned short other = 0;
	unsigned short i = 0;
	do {
		for (TCHAR j = 'A'; j < 'z'; j++)
			if (str[i] == j) {
				letters++;
				break;
			}
			else for (TCHAR k = 'А'; k != 'я'; k++)
					if (str[i] == k) {
						letters++;
						break;
					}
				else for (TCHAR I = '0'; I < '9'; i++) {
					if (str[i] == I) {
						numbers++;
						break;
					}
					else if (j == 'я')
						other++;
				}
	} while (str[i++] != '\0');
	cout << '\t' << letters << " - letters" << endl;
	cout << '\t' << numbers << " - numbers" << endl;
	cout << '\t' << other << " - other" << endl;
}

void counting_the_number_of_words_in_a_given_line_or_to_be_more_precise_counting_spaces_and_tabulations(TCHAR str[]) { // even clearer name than the past
	unsigned short i = 0;
	unsigned short count = 0;
	do {
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' && str[i + 1] != '\0')
			count++;
	} while (str[i++] != '\0');
	cout << "\tNumber of words = " << count << endl;
}

void function_to_count_vowels_from_a_ru_alphabet(TCHAR str[]) {
	const short SIZE = 5;
	TCHAR arr[SIZE] = { 'а', 'о', 'у', 'и', 'э' };
	unsigned short count = 0;
	unsigned short i = 0;
	do {
		for (short j = 0; j < SIZE; j++)
			if (str[i] == arr[j]) count++;
	} while (str[i++] != '\0');
	cout << count;
}

bool is_the_string_a_palindrome(TCHAR str[]) {
	unsigned short size = 0;
	{
		int i = 0;
		do {
			size++;
		} while (str[i++] != '\0');
	}
	for (int i = 0; i < size / 2; i++)
		if (str[i] != str[size - i])
			return 0;
	return 1;
}

void del(TCHAR str[], unsigned const short num){
	unsigned short size = 0;
	{
		int i = 0;
		do size++; while (str[i++] != '\0');
	}
	if (size - 1 < num) cout << "ERROR";
	else {
		TCHAR* NewStr = new TCHAR[size - 1];
		for (int i = 0; i < size - 1; i++)
			if (i != num)
				NewStr[i] = str[i];
		delete[] str;
		str = NewStr;
	}
}

void del(TCHAR str[], const TCHAR symbol) {
	unsigned short size = 0;
	unsigned short NewSize = 0;
	{
		int i = 0;
		do {
			if (str[i] != symbol) NewSize++;
			size++;
		} while (str[i++] != '\0');
		TCHAR* NewStr = new TCHAR[NewSize - 1];
		for (int i = 0; i < size - 1; i++)
			if (str[i] != symbol)
				NewStr[i] = str[i];
		delete[] str;
		str = NewStr;
	}
}

void add(TCHAR str[], unsigned const short num, const TCHAR symbol) {
	unsigned short size = 0;
	{
		int i = 0;
		do size++; while (str[i++] != '\0');
	}
		if (size - 1 < num) cout << "ERROR";
	else {
		TCHAR* NewStr = new TCHAR[size - 1];
		for (int i = 0; i < num - 1; i++)
			NewStr[i] = str[i];
		str[num] = symbol;
		for (int i = num + 1; i < size + 1; i++) {
			NewStr[i] = str[i];
		}
		delete[] str;
		str = NewStr;
	}
}