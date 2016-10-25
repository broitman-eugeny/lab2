#include "Fraction.h"
int Fraction::Count = 0;
int Fraction::Evklid(int N, int D)//Определение НОД по алгоритму Евклида
{
	int K;

	while (0 != (K = N%D))
	{
		N = D;
		D = K;
	}
	return (D>0) ? D : -D;
}
//Конструктор по умолчанию
Fraction::Fraction():Numerator(1), Denominator(1)
{
	Count++;
}
//Конструктор с параметрами
Fraction::Fraction(int N, int D) : Numerator(N), Denominator(D)
{
	Count++;
}
//Конструктор копирования
Fraction::Fraction(Fraction & F) : Numerator(F.Numerator), Denominator(F.Denominator)
{
	Count++;
}
//Деструктор
Fraction::~Fraction()
{
	Count--;
}
//Сокращение дроби
void Fraction::Reduction()
{
	int CommonDevider= Evklid(Numerator, Denominator);//наибольший общий делитель по алгоритму Евклида
	Numerator /= CommonDevider;
	Denominator /= CommonDevider;
}
//Умножение дроби
void Fraction::Mul(Fraction & F)
{
	Numerator *= F.Numerator;
	Denominator *= F.Denominator;
}
//Деление дроби
void Fraction::Div(Fraction & F)
{
	Numerator *= F.Denominator;
	Denominator *= F.Numerator;
}
//Установка значения числителя
void Fraction::SetNumerator(int N)
{
	Numerator = N;
}
//Установка значения знаменателя
void Fraction::SetDenominator(int D)
{
	Denominator = D;
}
//Извлечение значения числителя
int Fraction::GetNumerator()
{
	return Numerator;
}
//Извлечение значения знаменателя
int Fraction::GetDenominator()
{
	return Denominator;
}
//Извлечение количества созданных объектов
int Fraction::GetCount()
{
	return Count;
}
//Вывод на экран
void Fraction::Print()
{
	std::cout << Numerator << "\t\t" << Denominator << std::endl;
}
void Fraction::PrintAll(Fraction ** PFraction)
{
	std::cout << std::endl << "№" << "\t" << "Числитель" << "\t" << "Знаменатель" << std::endl;
	for (int i = 0, c = Fraction::GetCount(); i < c; i++)
	{
		std::cout << i << "\t";
		PFraction[i]->Print();
	}
}
//Возвращает 1, если числитель и знаменатель имеют одинаковые знаки, и -1, если разные
int Fraction::Sign()const
{
	if (Numerator < 0 && Denominator < 0 || Numerator >= 0 && Denominator>0)
	{
		return 1;
	}
	else
	{
		return -1;
	}	
}
Fraction Fraction::Abs()const
{
	Fraction Temp;
	Temp.Numerator = (Numerator < 0) ? -Numerator : Numerator;
	Temp.Denominator = (Denominator < 0) ? -Denominator : Denominator;
	return Temp;
}
//Сложение 2-х объектов
Fraction Fraction::operator+(Fraction & Addendum)
{
	Fraction Temp;
	Temp.Numerator = Numerator*Addendum.Denominator + Addendum.Numerator*Denominator;
	Temp.Denominator = Denominator * Addendum.Denominator;
	Temp.Reduction();
	return Temp;
}
//Умножение 2-х объектов
Fraction Fraction::operator*(Fraction & Multiplier)
{
	Fraction Temp = *this;
	Temp.Mul(Multiplier);
	Temp.Reduction();
	return Temp;
}
//Деление 2-х объектов
Fraction Fraction::operator/(Fraction & Divider)
{
	Fraction Temp = *this;
	Temp.Div(Divider);
	Temp.Reduction();
	return Temp;
}
//Равенство 2-х объектов
bool Fraction::operator==(Fraction & FractionRight)const
{	
		return Sign()*(Abs().Numerator)*(FractionRight.Abs().Denominator)==(FractionRight.Sign())*(FractionRight.Abs().Numerator)*(Abs().Denominator);
}
//Неравенство 2-х объектов
bool Fraction::operator!=(Fraction & FractionRight)const
{
	return !(*this == FractionRight);
}
//Первый объект больше второго
bool Fraction::operator>(Fraction & FractionRight)const
{
	return Sign()*(Abs().Numerator)*(FractionRight.Abs().Denominator)>(FractionRight.Sign())*(FractionRight.Abs().Numerator)*(Abs().Denominator);
}
//Первый объект больше или равен второму
bool Fraction::operator>=(Fraction & FractionRight)const
{
	return Sign()*(Abs().Numerator)*(FractionRight.Abs().Denominator)>=(FractionRight.Sign())*(FractionRight.Abs().Numerator)*(Abs().Denominator);
}
//Первый объект меньше второго
bool Fraction::operator<(Fraction & FractionRight)const
{
	return !(operator>=(FractionRight));
}
//Первый объект меньше или равен второму
bool Fraction::operator<=(Fraction & FractionRight)const
{
	return !(operator>(FractionRight));
}
//Присваивание
Fraction & Fraction::operator=(Fraction & FractionRight)
{
	Numerator = FractionRight.Numerator;
	Denominator = FractionRight.Denominator;
	return *this;
}
//Преобразование к типу double
Fraction::operator double()
{
	return (double)Numerator / (double)Denominator;
}
