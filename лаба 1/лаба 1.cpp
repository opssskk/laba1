#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	//Задача 1
	{
		cout << "Программа выводит обьем памяти, отводящийся под различные типы данных\n";
		cout << "int " << (sizeof(int)) << " байта\n";
		cout << "short int " << (sizeof(short int)) << " байта\n";
		cout << "long int " << (sizeof(long long)) << " байт\n";
		cout << "float " << (sizeof(float)) << " байта\n";
		cout << "double " << (sizeof(double)) << " байт\n";
		cout << "long double " << (sizeof(long double)) << " байт\n";
		cout << "char " << (sizeof(char)) << " байт\n";
		cout << "bool " << (sizeof(bool)) << " байт\n";
	}
	cout << endl << endl << endl;

	//Задача 2
	{
		int integerNumber;
		unsigned int mask = 1 << (sizeof(int) * 8 - 1);

		cout << "Введите число типа integer: ";
		cin >> integerNumber;
		cout << "Двоичное представление введенного числа в памяти компьютера: ";
		for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';
			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << endl;
		//ИДЗ 2
		int shift;

		cout << "Введите количество битов для сдвига влево: ";
		cin >> shift;
		cout << "Ввееденное число после сдвига влево на " << shift << " бит(а) ";

		integerNumber = integerNumber << shift;
		mask = 1 << (sizeof(int) * 8 - 1);
		for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';

			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << "\nПредставление сдвинутого числа в десятичной системе: " << integerNumber;

		cout << endl << endl << endl;
		

	}
	cout << '\n';

	//Задача 3
	{
		union {
			int integerNumber;
			float floatNumber;
		};
		cout << "Введите число типа float: ";
		cin >> floatNumber;
		cout << "Двоичное представление введенного числа в памяти компьютера ";

		unsigned int mask = 1 << (sizeof(float) * 8 - 1);

		for (int i = 1; i < sizeof(float) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';
			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << endl;

		//ИДЗ 2
		int shift;

		cout << "Введите количество битов для сдвига влево: ";
		cin >> shift;
		cout << "Ввееденное число после сдвига влево на " << shift << " бит(а) ";

		integerNumber = integerNumber << shift;

		mask = 1 << (sizeof(int) * 8 - 1);
		for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
			if (mask & integerNumber)
				cout << '1';
			else
				cout << '0';

			if (i == 1 || i % 8 == 0)
				cout << ' ';
		}
		cout << "\nПредставление сдвинутого числа в десятичной системе: " << floatNumber;
		cout << endl << endl << endl;

	}
	
	

	//Задача 4
	{
		union {
			double numberDouble;
			unsigned int splitDouble[2];

		};
		cout << "Введите число типа double: ";
		cin >> numberDouble;
		cout << "Двоичное представление введенного числа в памяти компьютера ";

		unsigned int mask = 1 << (sizeof(int) * 8 - 1);
		for (int n = 1; n >= 0; --n) {
			for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
				if (mask & splitDouble[n])
					cout << '1';
				else
					cout << '0';
				if (i == 1 || i % 8 == 0)
					cout << ' ';
			}
			mask = 1 << (sizeof(int) * 8 - 1);
		}
		cout << endl;

		//ИДЗ 2
		int shift;
		cout << "Введите количество битов для сдвига влево: ";
		cin >> shift;
		cout << "Ввееденное число после сдвига влево на " << shift << " бит(а): ";

		for (int n = 1; n >= 0; --n) {
			splitDouble[n] = splitDouble[n] << shift;
			mask = 1 << (sizeof(int) * 8 - 1);
			for (int i = 1; i < sizeof(int) * 8 + 1; ++i, mask >>= 1) {
				if (mask & splitDouble[n])
					cout << '1';
				else
					cout << '0';

				if (i == 1 || i % 8 == 0)
					cout << ' ';
			}

		}
		cout << "\nПредставление сдвинутого числа в десятичной системе: " << numberDouble;
	}
	
return 0;
}