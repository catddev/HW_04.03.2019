#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>

using namespace std;

// 1.	*Написать программу, которая заменяет все символы точки «.» в строке, введенной пользователем,
// на символы восклицательного знака «!».
void replace1(char*str) {
	cin.getline(str, strlen(str));
	char *s = str;
	while (*s++ != '\0')
	{
		if (*s == '.') *s = '!';
	}
	cout << str << endl;
}
// 2.	*Написать программу, которая заменяет все символы вопросительного знака « ? » в строке,
// введенной пользователем, на символы «1».
void replace2(char*str) {
	cin.getline(str, strlen(str));
	char *s = str;
	while (*s++ != '\0')
	{
		if (*s == '?') *s = '1';
	}
	cout << str << endl;
}
// 3.	*Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке.
int countSym(char*str) {
	cin.getline(str, strlen(str));
	char Sym;
	cin >> Sym;
	int k = 0;
	while (*str++ != '\0')
	{
		if (*str == Sym) k++;
	}
	return k;
}
// 4.	**Пользователь вводит строку и слово.
// Осуществить в этой строке поиск заданного слова.
char *subStr(char* str1, const char* str2) {
	int k = 0;
	char* word = str1;
	int tmp = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		k = 0;
		tmp = i;
		for (int j = 0; j < strlen(str2); j++)
		{
			if (str1[i++] != str2[j]) break;
			else k++;
		}
		i = tmp;
		if (k == strlen(str2)) word=str1+i;
	}
	return word;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			char str[100];

			// replace1(str);
			// replace2(str);
			cout << countSym(str) << endl;

		}
		break;
		case 2: // 4
		{
			char str1[100] = "Hello My World!";
			char str2[100] = "World";

			char *SearchWord = subStr(str1, str2);
			cout << SearchWord << endl;
			
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}