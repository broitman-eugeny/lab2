#include "Fraction.h"
//Вывод в поток
std::ostream & operator<<(std::ostream & out, Fraction & FractionOut)
{
	out << FractionOut.Numerator << "/" << FractionOut.Denominator;
	return out;
}
//Ввод из потока
std::istream & operator >> (std::istream & in, Fraction & FractionIn)
{
	std::cout << std::endl << "Числитель: ";
	in >> FractionIn.Numerator;
	while (in.fail())
	{
		in.clear();
		in.ignore(in.rdbuf()->in_avail());//Очистка буфера
		std::cout << std::endl << "Неверно введено число, введите еще раз: ";
		in >> FractionIn.Numerator;
	}
	std::cout << std::endl << "Знаменатель: ";
	in >> FractionIn.Denominator;
	while (FractionIn.Denominator == 0 || in.fail())
	{
		in.clear();
		in.ignore(in.rdbuf()->in_avail());//Очистка буфера
		std::cout << std::endl << "Неверно введено число, введите еще раз: ";
		in >> FractionIn.Denominator;
	}
	return in;
}
