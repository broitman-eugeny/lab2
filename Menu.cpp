#include "Fraction.h"
//������� ����������� ����
void ShowMenu()
{
	std::cout << std::endl << "������������ ������ �1 (���)";
	std::cout << std::endl << "[�]. �������� ������";
	std::cout << std::endl << "[�]. ������� ������";
	std::cout << std::endl << "[�]. �������� ��� �������";
	std::cout << std::endl << "[�]. ���������� ��������";
	std::cout << std::endl << "[�]. ���������� ����������";
	std::cout << std::endl << "[�]. �����";
	std::cout << std::endl << "������� ����� ���������� ������ ����: ";
}
//������� ����������� ������� ���������� �������
void ShowMenu2()
{
	std::cout << std::endl << "[1]. �������� �� ���������";
	std::cout << std::endl << "[2]. ����� ��� ������������� � ������� �������";
	std::cout << std::endl << "[3]. ���� �������� ��������� � �����������";
	std::cout << std::endl << "[4]. �����";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� ����������� ������� ���������� ��������
void ShowMenu3()
{
	std::cout << std::endl << "[1]. ��������� ����������� ������� � �������� �������";
	std::cout << std::endl << "[2]. ���������� ����� ������� � �������� �������";
	std::cout << std::endl << "[3]. ��������� ����� ������� � �������� �������";
	std::cout << std::endl << "[4]. ������� ����� ������� � �������� �������";
	std::cout << std::endl << "[5]. �����";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� ����������� ������� ���������� ����������
void ShowMenu4()
{
	std::cout << std::endl << "[1]. �������� ���������";
	std::cout << std::endl << "[2]. ��������";
	std::cout << std::endl << "[3]. ���������� ���� � double";
	std::cout << std::endl << "[4]. �����";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� ����������� ���������� �������� ���������
void ShowMenu5()
{
	std::cout << std::endl << "[1]. ==";
	std::cout << std::endl << "[2]. !=";
	std::cout << std::endl << "[3]. >";
	std::cout << std::endl << "[4]. >=";
	std::cout << std::endl << "[5]. <";
	std::cout << std::endl << "[6]. <=";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� ����
//PFraction - ������ ���������� �� ������� ���� Fraction, ��������� �� FractionDimSize ���������
void Menu(Fraction **PFraction)
{
	char C = -1;
	int C3 = -1;
	int i, c;
	int Count;
	while (C != '�')//� - �����
	{
		ShowMenu();
		std::cin >> C;
		while (C<'�' || C>'�' || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
			std::cout << std::endl << "������� ������ ������, ������� ��� ���: ";
			std::cin >> C;
		}
		switch (C)
		{
		case '�'://�������� ������
			if (Fraction::GetCount() == FractionDimSize)//���� ������ ��������
			{
				std::cout << "��������, ������ ��������" << std::endl;
			}
			else
			{
				int C2 = -1;
				while (C2 != 4)//4 - �����
				{
					ShowMenu2();
					std::cin >> C2;
					while (C2<1 || C2>4 || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
						std::cout << std::endl << "������� ������ �����, ������� ��� ���: ";
						std::cin >> C2;
					}
					int Index, IndexOfCopy;
					switch (C2)
					{
					case 1://�������� �� ���������
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction();
						std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
						break;
					case 2://����� ��� ������������� � ������� �������
						if (Fraction::GetCount() == 0)
						{
							std::cout << "������� ������� �������!";
							break;
						}
						std::cout << "������� ������ ����������� �������: ";
						std::cin >> IndexOfCopy;
						Count = Fraction::GetCount();
						while (IndexOfCopy<0 || IndexOfCopy >= Count || std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
							std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
							std::cin >> IndexOfCopy;
						}
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction(*PFraction[IndexOfCopy]);
						std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
						break;
					case 3://���� �������� ��������� � �����������
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction();
						std::cin >> *(PFraction[Index]);
						std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
						break;
					}//switch (C)
				}//while (C2 != 4)//4 - �����
			}//case '�'://�������� ������
			break;
		case '�'://������� ������
			if (Fraction::GetCount() == 0)
			{
				std::cout << "������� ������� �������!";
				break;
			}
			std::cout << "������� ������ ���������� �������: ";
			int Index;
			std::cin >> Index;
			Count = Fraction::GetCount();
			while (Index<0 || Index>= Count || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
				std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
				std::cin >> Index;
			}
			c = Fraction::GetCount() - 1;
			for (i = Index; i < c; i++)
			{
				PFraction[i]->SetNumerator(PFraction[i+1]->GetNumerator());
				PFraction[i]->SetDenominator(PFraction[i + 1]->GetDenominator());
			}
			delete PFraction[i];
			std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
			break;
		case '�'://�������� ��� �������
			Fraction::PrintAll(PFraction);
			break;
		case '�'://���������� ��������
			if (Fraction::GetCount() == 0)
			{
				std::cout << "������� ������� �������!";
				break;
			}
			Fraction::PrintAll(PFraction);
			std::cout << "������� ������ ������������ �������: ";
			std::cin >> Index;
			Count = Fraction::GetCount();
			while (Index<0 || Index >= Count || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
				std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
				std::cin >> Index;
			}
			while (C3 != 5)//5- �����
			{
				Fraction::PrintAll(PFraction);
				ShowMenu3();
				std::cin >> C3;
				while (C3 < 1 || C3>5 || std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
					std::cout << std::endl << "������� ������ �����, ������� ��� ���: ";
					std::cin >> C3;
				}
				Fraction *F = new Fraction();//�������� ������� � ��������� Count;
				switch (C3)
				{
				case 1://��������� ����������� ������� � �������� �������
					std::cin >> *(PFraction[Index]);
					break;
				case 2://���������� ����� ������� � �������� �������
					PFraction[Index]->Reduction();
					break;
				case 3://��������� ����� ������� � �������� �������
					std::cout << "���������:";
					std::cin >> *F;
					PFraction[Index]->Mul(*F);
					break;
				case 4://������� ����� ������� � �������� �������
					std::cout << "��������:";
					std::cin >> *F;
					PFraction[Index]->Div(*F);
					break;
				}//switch (C3)
				delete F;//�������� ������� � ��������� Count
			}//while (C3 != 5)//5- �����
			break;
		case '�'://���������� ����������
			if (Fraction::GetCount() == 0)
			{
				std::cout << "������� ������� �������!";
				break;
			}
			Fraction::PrintAll(PFraction);
			int C4 = -1;
			int C5 = -1;
			char *Compare = "", *CompareResult = "";
			while (C4 != 4)//4- �����
			{
				ShowMenu4();
				std::cin >> C4;
				while (C4 < 1 || C4>4 || std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
					std::cout << std::endl << "������� ������ �����, ������� ��� ���: ";
					std::cin >> C4;
				}
				Fraction::PrintAll(PFraction);
				Count = Fraction::GetCount();
				Fraction *F = new Fraction();//�������� ������� � ��������� Count;
				switch (C4)
				{
				case 1://[1]. �������� ���������
					std::cout << std::endl << "������ ���������� �������: ";
					std::cin >> Index;
					while (Index<0 || Index >= Count || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
						std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
						std::cin >> Index;
					}
					ShowMenu5();
					std::cin >> C5;
					while (C5 < 1 || C5>6 || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
						std::cout << std::endl << "������� ������ �����, ������� ��� ���: ";
						std::cin >> C5;
					}
					for (i = 0; i < Count; i++)
					{
						switch (C5)
						{
						case 1:
							Compare = " == ";
							CompareResult = (*(PFraction[Index])== *(PFraction[i])) ?"\t= true" :"\t= false" ;
							break;
						case 2:
							Compare = " != ";
							CompareResult = (*(PFraction[Index]) != *(PFraction[i])) ? "\t= true" : "\t= false";
							break;
						case 3:
							Compare = " > ";
							CompareResult = (*(PFraction[Index]) > *(PFraction[i])) ? "\t= true" : "\t= false";
							break;
						case 4:
							Compare = " >= ";
							CompareResult = (*(PFraction[Index]) >= *(PFraction[i])) ? "\t= true" : "\t= false";
							break;
						case 5:
							Compare = " < ";
							CompareResult = (*(PFraction[Index]) < *(PFraction[i])) ? "\t= true" : "\t= false";
							break;
						case 6:
							Compare = " <= ";
							CompareResult = (*(PFraction[Index]) <= *(PFraction[i])) ? "\t= true" : "\t= false";
							break;
						}
						std::cout << "[" << i+1 << "] " << *(PFraction[Index]) << Compare << *(PFraction[i]) << CompareResult << std::endl;
					}
					break;
				case 2://[2]. ��������
					std::cout << std::endl << "������ ���������� �������: ";
					std::cin >> Index;
					while (Index<0 || Index >= Count || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
						std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
						std::cin >> Index;
					}
					for (i = 0; i < Count; i++)
					{
						*F = *(PFraction[Index]) + *(PFraction[i]);
						std::cout << "[" << i + 1 << "] " << *(PFraction[Index]) << " + " << *(PFraction[i]) << "\t== " << *F << std::endl;
					}
					break;
				case 3://[3]. ���������� ���� � double
					for (i = 0; i < Count; i++)
					{
						std::cout << "[" << i + 1 << "] " << "(double)" << *(PFraction[i]) << "\t== " << (double)(*(PFraction[i])) << std::endl;
					}
					break;
				}//switch (C4)
				delete F;//�������� ������� � ��������� Count
			}//while (C4 != 4)//4- �����
			break;
		}//switch (C)
	}//while (C != '�')//� - �����
	//������� ������������ ������
	for (i = 0, c = Fraction::GetCount(); i < c; i++)
	{
		delete PFraction[i];
	}
}