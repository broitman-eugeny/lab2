#pragma once
#include <iostream>
#include <Windows.h>
const int FractionDimSize = 10;
//����� �����
class Fraction
{
	int Numerator;		//���������
	int Denominator;	//�����������
	static int Count;	//������� ��������
	static int Evklid(int N, int D);	//����������� ��� �� ��������� �������	
public:
	Fraction();							//����������� �� ���������
	Fraction(int N, int D);				//����������� � �����������
	Fraction(Fraction &F);				//����������� �����������
	~Fraction();						//����������
	void Reduction();					//���������� �����
	void Mul(Fraction &F);				//��������� �����
	void Div(Fraction &F);				//������� �����
	void SetNumerator(int N);			//��������� �������� ���������
	void SetDenominator(int D);			//��������� �������� �����������
	int GetNumerator();					//���������� �������� ���������
	int GetDenominator();				//���������� �������� �����������
	static int GetCount();				//���������� ���������� ��������� ��������
	void Print();						//����� �� �����
	static void PrintAll(Fraction **PFraction);//����� �� ����� ��� �������, ��������� �� ������� ��������� � PFraction
	int Sign()const;					//���������� 1, ���� ��������� � ����������� ����� ���������� �����, � -1, ���� ������
	Fraction Abs()const;				//���������� ����� � ���������� � ������������ ��� ����� 
	//���������� ����������
	Fraction operator+(Fraction &Addendum);			//�������� 2-� ��������
	Fraction operator*(Fraction &Multiplier);		//��������� 2-� ��������
	Fraction operator/(Fraction &Divider);			//������� 2-� ��������
	bool operator==(Fraction &FractionRight)const;	//��������� 2-� ��������
	bool operator!=(Fraction &FractionRight)const;	//����������� 2-� ��������
	bool operator>(Fraction &FractionRight)const;	//������ ������ ������ �������
	bool operator>=(Fraction &FractionRight)const;	//������ ������ ������ ��� ����� �������
	bool operator<(Fraction &FractionRight)const;	//������ ������ ������ �������
	bool operator<=(Fraction &FractionRight)const;	//������ ������ ������ ��� ����� �������
	Fraction & operator=(Fraction &FractionRight);	//������������
	operator double();						//�������������� � ���� double
	friend std::ostream& operator<<(std::ostream &out, Fraction &FractionOut);//����� � �����
	friend std::istream& operator >> (std::istream &in, Fraction &FractionIn);//���� �� ������
};
//������� ����
//PFraction - ������ ���������� �� ������� ���� Fraction, ��������� �� FractionDimSize ���������
void Menu(Fraction **PFraction);