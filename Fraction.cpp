#include "Fraction.h"
int Fraction::Count = 0;
int Fraction::Evklid(int N, int D)//����������� ��� �� ��������� �������
{
	int K;

	while (0 != (K = N%D))
	{
		N = D;
		D = K;
	}
	return (D>0) ? D : -D;
}
//����������� �� ���������
Fraction::Fraction():Numerator(1), Denominator(1)
{
	Count++;
}
//����������� � �����������
Fraction::Fraction(int N, int D) : Numerator(N), Denominator(D)
{
	Count++;
}
//����������� �����������
Fraction::Fraction(Fraction & F) : Numerator(F.Numerator), Denominator(F.Denominator)
{
	Count++;
}
//����������
Fraction::~Fraction()
{
	Count--;
}
//���������� �����
void Fraction::Reduction()
{
	int CommonDevider= Evklid(Numerator, Denominator);//���������� ����� �������� �� ��������� �������
	Numerator /= CommonDevider;
	Denominator /= CommonDevider;
}
//��������� �����
void Fraction::Mul(Fraction & F)
{
	Numerator *= F.Numerator;
	Denominator *= F.Denominator;
}
//������� �����
void Fraction::Div(Fraction & F)
{
	Numerator *= F.Denominator;
	Denominator *= F.Numerator;
}
//��������� �������� ���������
void Fraction::SetNumerator(int N)
{
	Numerator = N;
}
//��������� �������� �����������
void Fraction::SetDenominator(int D)
{
	Denominator = D;
}
//���������� �������� ���������
int Fraction::GetNumerator()
{
	return Numerator;
}
//���������� �������� �����������
int Fraction::GetDenominator()
{
	return Denominator;
}
//���������� ���������� ��������� ��������
int Fraction::GetCount()
{
	return Count;
}
//����� �� �����
void Fraction::Print()
{
	std::cout << Numerator << "\t\t" << Denominator << std::endl;
}
void Fraction::PrintAll(Fraction ** PFraction)
{
	std::cout << std::endl << "�" << "\t" << "���������" << "\t" << "�����������" << std::endl;
	for (int i = 0, c = Fraction::GetCount(); i < c; i++)
	{
		std::cout << i << "\t";
		PFraction[i]->Print();
	}
}
//���������� 1, ���� ��������� � ����������� ����� ���������� �����, � -1, ���� ������
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
//�������� 2-� ��������
Fraction Fraction::operator+(Fraction & Addendum)
{
	Fraction Temp;
	Temp.Numerator = Numerator*Addendum.Denominator + Addendum.Numerator*Denominator;
	Temp.Denominator = Denominator * Addendum.Denominator;
	Temp.Reduction();
	return Temp;
}
//��������� 2-� ��������
Fraction Fraction::operator*(Fraction & Multiplier)
{
	Fraction Temp = *this;
	Temp.Mul(Multiplier);
	Temp.Reduction();
	return Temp;
}
//������� 2-� ��������
Fraction Fraction::operator/(Fraction & Divider)
{
	Fraction Temp = *this;
	Temp.Div(Divider);
	Temp.Reduction();
	return Temp;
}
//��������� 2-� ��������
bool Fraction::operator==(Fraction & FractionRight)const
{	
		return Sign()*(Abs().Numerator)*(FractionRight.Abs().Denominator)==(FractionRight.Sign())*(FractionRight.Abs().Numerator)*(Abs().Denominator);
}
//����������� 2-� ��������
bool Fraction::operator!=(Fraction & FractionRight)const
{
	return !(*this == FractionRight);
}
//������ ������ ������ �������
bool Fraction::operator>(Fraction & FractionRight)const
{
	return Sign()*(Abs().Numerator)*(FractionRight.Abs().Denominator)>(FractionRight.Sign())*(FractionRight.Abs().Numerator)*(Abs().Denominator);
}
//������ ������ ������ ��� ����� �������
bool Fraction::operator>=(Fraction & FractionRight)const
{
	return Sign()*(Abs().Numerator)*(FractionRight.Abs().Denominator)>=(FractionRight.Sign())*(FractionRight.Abs().Numerator)*(Abs().Denominator);
}
//������ ������ ������ �������
bool Fraction::operator<(Fraction & FractionRight)const
{
	return !(operator>=(FractionRight));
}
//������ ������ ������ ��� ����� �������
bool Fraction::operator<=(Fraction & FractionRight)const
{
	return !(operator>(FractionRight));
}
//������������
Fraction & Fraction::operator=(Fraction & FractionRight)
{
	Numerator = FractionRight.Numerator;
	Denominator = FractionRight.Denominator;
	return *this;
}
//�������������� � ���� double
Fraction::operator double()
{
	return (double)Numerator / (double)Denominator;
}
