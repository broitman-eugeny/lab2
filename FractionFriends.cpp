#include "Fraction.h"
//����� � �����
std::ostream & operator<<(std::ostream & out, Fraction & FractionOut)
{
	out << FractionOut.Numerator << "/" << FractionOut.Denominator;
	return out;
}
//���� �� ������
std::istream & operator >> (std::istream & in, Fraction & FractionIn)
{
	std::cout << std::endl << "���������: ";
	in >> FractionIn.Numerator;
	while (in.fail())
	{
		in.clear();
		in.ignore(in.rdbuf()->in_avail());//������� ������
		std::cout << std::endl << "������� ������� �����, ������� ��� ���: ";
		in >> FractionIn.Numerator;
	}
	std::cout << std::endl << "�����������: ";
	in >> FractionIn.Denominator;
	while (FractionIn.Denominator == 0 || in.fail())
	{
		in.clear();
		in.ignore(in.rdbuf()->in_avail());//������� ������
		std::cout << std::endl << "������� ������� �����, ������� ��� ���: ";
		in >> FractionIn.Denominator;
	}
	return in;
}
