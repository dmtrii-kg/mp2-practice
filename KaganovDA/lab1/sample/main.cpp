#include "postfix.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char Expression[80], *PolishExpression;
	cout << "Введите выражение(последний символ должен быть '=') : ";
	cin >> Expression;
	float result;
	try {
		PolishExpression = postfix::ConvertToPolish(Expression, strlen(Expression));
		cout << "Выражение в инфиксной записи: " << Expression << endl;
		cout << "Выражение в польской записи: " << PolishExpression << endl;
		result = postfix::ConvertToInfix(PolishExpression, strlen(PolishExpression));

	} 
	catch (...) {
		cout << "Ошибка! Неверные входные данные!" << endl;
		return 1;
	}
	cout << "Результат: " << result << endl;
	delete PolishExpression;
	system("pause");
    return 0;
}
