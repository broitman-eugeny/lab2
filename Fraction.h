#pragma once
#include <iostream>
#include <Windows.h>
const int FractionDimSize = 10;
//Класс дроби
class Fraction
{
	int Numerator;		//Числитель
	int Denominator;	//Знаменатель
	static int Count;	//Счетчик объектов
	static int Evklid(int N, int D);	//Определение НОД по алгоритму Евклида	
public:
	Fraction();							//Конструктор по умолчанию
	Fraction(int N, int D);				//Конструктор с параметрами
	Fraction(Fraction &F);				//Конструктор копирования
	~Fraction();						//Деструктор
	void Reduction();					//Сокращение дроби
	void Mul(Fraction &F);				//Умножение дроби
	void Div(Fraction &F);				//Деление дроби
	void SetNumerator(int N);			//Установка значения числителя
	void SetDenominator(int D);			//Установка значения знаменателя
	int GetNumerator();					//Извлечение значения числителя
	int GetDenominator();				//Извлечение значения знаменателя
	static int GetCount();				//Извлечение количества созданных объектов
	void Print();						//Вывод на экран
	static void PrintAll(Fraction **PFraction);//Вывод на экран все объекты, указатели на которые находятся в PFraction
	int Sign()const;					//Возвращает 1, если числитель и знаменатель имеют одинаковые знаки, и -1, если разные
	Fraction Abs()const;				//Возвращает дробь с числителем и знаменателем без знака 
	//Перегрузка операторов
	Fraction operator+(Fraction &Addendum);			//Сложение 2-х объектов
	Fraction operator*(Fraction &Multiplier);		//Умножение 2-х объектов
	Fraction operator/(Fraction &Divider);			//Деление 2-х объектов
	bool operator==(Fraction &FractionRight)const;	//Равенство 2-х объектов
	bool operator!=(Fraction &FractionRight)const;	//Неравенство 2-х объектов
	bool operator>(Fraction &FractionRight)const;	//Первый объект больше второго
	bool operator>=(Fraction &FractionRight)const;	//Первый объект больше или равен второму
	bool operator<(Fraction &FractionRight)const;	//Первый объект меньше второго
	bool operator<=(Fraction &FractionRight)const;	//Первый объект меньше или равен второму
	Fraction & operator=(Fraction &FractionRight);	//Присваивание
	operator double();						//Преобразование к типу double
	friend std::ostream& operator<<(std::ostream &out, Fraction &FractionOut);//Вывод в поток
	friend std::istream& operator >> (std::istream &in, Fraction &FractionIn);//Ввод из потока
};
//Функция меню
//PFraction - массив указателей на объекты типа Fraction, состоящий из FractionDimSize элементов
void Menu(Fraction **PFraction);