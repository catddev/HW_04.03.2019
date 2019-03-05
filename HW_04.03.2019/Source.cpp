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
	
	char* word = str1;
	//cout << strlen(str1) << " " << strlen(str2) << endl;
	int n = 0;
	while(word <= str1 + strlen(str1) - strlen(str2))
	{
		//cout << word << endl; //// test
		n = strncmp(word, str2, strlen(str2)); //!!!!!!!!!!!!! здксь обязательно сравнивать не str1, str2,
		// а именно смещающийся word с str2, ведь str1 не меняется, бегает только вспомогательный указатель
		//cout << n << endl;
		if (n == 0)
		{
			//cout << "found" << endl;
			return word;
		}
		word++;
	}
	//cout << endl << "test" << word << endl;
	if (word == str1 + strlen(str1) - strlen(str2) +1) word = nullptr;
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
			char str1[100] = "Hello World!";
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