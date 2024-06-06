#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

bool polindrome(std::string str) {
	bool pol = true;

	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	for (int i = 0; i < str.length() / 2; i++)
		if (str[i] != str[str.length() - i - 1])
			pol = false;
	return pol;
}

int marks(std::string str) {
	int counter = 0;
	const int size = 5;
	const char sym[size]{
		'!',
		'?',
		'.',
		',',
		' '
	};

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < size; j++)
			if (str[i] == sym[j])
				counter++;
	}
	return counter;
}

std::string search(std::string str, char sym) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] == sym)
			return str.substr(str.rfind(sym));
	str.erase();
	return str;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	/*
	Задача 1
	Дана строка str. Пользователь вводит символ sym. Программа создаёт новую строку, которая состоит из символа sym. 
	Длина новой строки равна количеству совпадений введённого символа с элементами изначальной строки str.
	*/

	std::cout << "Задача 1.\n";
	std::string str = "Hello world!";
	std::cout << "Введите любой символ из фразы " << str << ", и программа выведет только его -> ";
	char sym;
	std::cin >> sym;
	std::string new_str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == sym)
			new_str += sym;
	}
	std::cout << "Обновленная строка:" << new_str << "\n\n";
	
	
	/*
	Задача 2
	Создайте функцию, которая принимает слово и возвращает true, если оно является палиндромом. В противном случае
	возвращается false. Функция должна быть нерегистрозависимой.
	*/

	std::cin.ignore();
	std::cout << "Задание 2.\nВведите слово любое слово (en) -> ";
	std::string str1;
	std::getline(std::cin, str1);

	if (polindrome(str1))
		std::cout << "Слово " << str1 << " - является полиндромом!\n\n";
	else
		std::cout << "Слово " << str1 << " - не является полиндромом!\n\n";
	
	/*
	Задача 3
	Создайте функцию, которая принимает строку. Функция считает все пробелы, точки, запятые, восклицательные и
	вопросительные знаки, которые есть в переданной строке и возвращает их общее количество.
	*/

	std::cout << "Задача 3.\nВведите строку, а программа посчитает в ней все знаки припенания и пробелы -> ";
	std::string str2;
	std::getline(std::cin, str2);
	std::cout << "В строке " << str2 << " - " << marks(str2) << " знаков препинания или пробелов.\n\n";

	/*
	Задача 4
	Создайте функцию, которая принимает строку и символ. Функция ищет последнее вхождение символа в переданную
	строку и возвращает подстроку, начинающуюся с этого символа и заканчивающуюся концом строки. Если символа в 
	строке нет, то функция возвращает пустую строку
	*/

	std::cout << "Задача 4.\nВведите строку -> ";
	std::string str3;
	std::getline(std::cin, str3);
	std::cout << "Введите символ -> ";
	char sym1;
	std::cin >> sym1;
	std::cout << "Обновленая строка: " << search(str3, sym1) << std::endl;

	return 0;
}