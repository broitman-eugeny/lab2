#include "Fraction.h"
//Функция отображения меню
void ShowMenu()
{
	std::cout << std::endl << "Лабораторная работа №1 (ООП)";
	std::cout << std::endl << "[а]. Добавить объект";
	std::cout << std::endl << "[б]. Удалить объект";
	std::cout << std::endl << "[в]. Показать все объекты";
	std::cout << std::endl << "[г]. Управление объектом";
	std::cout << std::endl << "[д]. Перегрузка операторов";
	std::cout << std::endl << "[е]. Выход";
	std::cout << std::endl << "Введите букву требуемого пункта меню: ";
}
//Функция отображения подменю добавления объекта
void ShowMenu2()
{
	std::cout << std::endl << "[1]. Значения по умолчанию";
	std::cout << std::endl << "[2]. Копия уже существующего в массиве объекта";
	std::cout << std::endl << "[3]. Ввод значений числителя и знаменателя";
	std::cout << std::endl << "[4]. Выход";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция отображения подменю управления объектом
void ShowMenu3()
{
	std::cout << std::endl << "[1]. Изменение содержимого объекта с заданным номером";
	std::cout << std::endl << "[2]. Сокращение дроби объекта с заданным номером";
	std::cout << std::endl << "[3]. Умножение дроби объекта с заданным номером";
	std::cout << std::endl << "[4]. Деление дроби объекта с заданным номером";
	std::cout << std::endl << "[5]. Выход";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция отображения подменю перегрузки операторов
void ShowMenu4()
{
	std::cout << std::endl << "[1]. Операции сравнения";
	std::cout << std::endl << "[2]. Сложение";
	std::cout << std::endl << "[3]. Приведение типа к double";
	std::cout << std::endl << "[4]. Выход";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция отображения подподменю операций сравнения
void ShowMenu5()
{
	std::cout << std::endl << "[1]. ==";
	std::cout << std::endl << "[2]. !=";
	std::cout << std::endl << "[3]. >";
	std::cout << std::endl << "[4]. >=";
	std::cout << std::endl << "[5]. <";
	std::cout << std::endl << "[6]. <=";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция меню
//PFraction - массив указателей на объекты типа Fraction, состоящий из FractionDimSize элементов
void Menu(Fraction **PFraction)
{
	char C = -1;
	int C3 = -1;
	int i, c;
	int Count;
	while (C != 'е')//д - выход
	{
		ShowMenu();
		std::cin >> C;
		while (C<'а' || C>'е' || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
			std::cout << std::endl << "Неверно введен символ, введите еще раз: ";
			std::cin >> C;
		}
		switch (C)
		{
		case 'а'://Добавить объект
			if (Fraction::GetCount() == FractionDimSize)//Если массив заполнен
			{
				std::cout << "Извините, массив заполнен" << std::endl;
			}
			else
			{
				int C2 = -1;
				while (C2 != 4)//4 - выход
				{
					ShowMenu2();
					std::cin >> C2;
					while (C2<1 || C2>4 || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
						std::cout << std::endl << "Неверно введен номер, введите еще раз: ";
						std::cin >> C2;
					}
					int Index, IndexOfCopy;
					switch (C2)
					{
					case 1://Значения по умолчанию
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction();
						std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
						break;
					case 2://Копия уже существующего в массиве объекта
						if (Fraction::GetCount() == 0)
						{
							std::cout << "Сначала добвьте объекты!";
							break;
						}
						std::cout << "Введите индекс копируемого объекта: ";
						std::cin >> IndexOfCopy;
						Count = Fraction::GetCount();
						while (IndexOfCopy<0 || IndexOfCopy >= Count || std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
							std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
							std::cin >> IndexOfCopy;
						}
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction(*PFraction[IndexOfCopy]);
						std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
						break;
					case 3://Ввод значений числителя и знаменателя
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction();
						std::cin >> *(PFraction[Index]);
						std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
						break;
					}//switch (C)
				}//while (C2 != 4)//4 - выход
			}//case 'а'://Добавить объект
			break;
		case 'б'://Удалить объект
			if (Fraction::GetCount() == 0)
			{
				std::cout << "Сначала добвьте объекты!";
				break;
			}
			std::cout << "Введите индекс удаляемого объекта: ";
			int Index;
			std::cin >> Index;
			Count = Fraction::GetCount();
			while (Index<0 || Index>= Count || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
				std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
				std::cin >> Index;
			}
			c = Fraction::GetCount() - 1;
			for (i = Index; i < c; i++)
			{
				PFraction[i]->SetNumerator(PFraction[i+1]->GetNumerator());
				PFraction[i]->SetDenominator(PFraction[i + 1]->GetDenominator());
			}
			delete PFraction[i];
			std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
			break;
		case 'в'://Показать все объекты
			Fraction::PrintAll(PFraction);
			break;
		case 'г'://Управление объектом
			if (Fraction::GetCount() == 0)
			{
				std::cout << "Сначала добвьте объекты!";
				break;
			}
			Fraction::PrintAll(PFraction);
			std::cout << "Введите индекс управляемого объекта: ";
			std::cin >> Index;
			Count = Fraction::GetCount();
			while (Index<0 || Index >= Count || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
				std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
				std::cin >> Index;
			}
			while (C3 != 5)//5- выход
			{
				Fraction::PrintAll(PFraction);
				ShowMenu3();
				std::cin >> C3;
				while (C3 < 1 || C3>5 || std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
					std::cout << std::endl << "Неверно введен номер, введите еще раз: ";
					std::cin >> C3;
				}
				Fraction *F = new Fraction();//Создание объекта и инкремент Count;
				switch (C3)
				{
				case 1://Изменение содержимого объекта с заданным номером
					std::cin >> *(PFraction[Index]);
					break;
				case 2://Сокращение дроби объекта с заданным номером
					PFraction[Index]->Reduction();
					break;
				case 3://Умножение дроби объекта с заданным номером
					std::cout << "Множитель:";
					std::cin >> *F;
					PFraction[Index]->Mul(*F);
					break;
				case 4://Деление дроби объекта с заданным номером
					std::cout << "Делитель:";
					std::cin >> *F;
					PFraction[Index]->Div(*F);
					break;
				}//switch (C3)
				delete F;//Удаление объекта и декремент Count
			}//while (C3 != 5)//5- выход
			break;
		case 'д'://Перегрузка операторов
			if (Fraction::GetCount() == 0)
			{
				std::cout << "Сначала добвьте объекты!";
				break;
			}
			Fraction::PrintAll(PFraction);
			int C4 = -1;
			int C5 = -1;
			char *Compare = "", *CompareResult = "";
			while (C4 != 4)//4- выход
			{
				ShowMenu4();
				std::cin >> C4;
				while (C4 < 1 || C4>4 || std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
					std::cout << std::endl << "Неверно введен номер, введите еще раз: ";
					std::cin >> C4;
				}
				Fraction::PrintAll(PFraction);
				Count = Fraction::GetCount();
				Fraction *F = new Fraction();//Создание объекта и инкремент Count;
				switch (C4)
				{
				case 1://[1]. Операции сравнения
					std::cout << std::endl << "Индекс эталонного объекта: ";
					std::cin >> Index;
					while (Index<0 || Index >= Count || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
						std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
						std::cin >> Index;
					}
					ShowMenu5();
					std::cin >> C5;
					while (C5 < 1 || C5>6 || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
						std::cout << std::endl << "Неверно введен номер, введите еще раз: ";
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
				case 2://[2]. Сложение
					std::cout << std::endl << "Индекс эталонного объекта: ";
					std::cin >> Index;
					while (Index<0 || Index >= Count || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
						std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
						std::cin >> Index;
					}
					for (i = 0; i < Count; i++)
					{
						*F = *(PFraction[Index]) + *(PFraction[i]);
						std::cout << "[" << i + 1 << "] " << *(PFraction[Index]) << " + " << *(PFraction[i]) << "\t== " << *F << std::endl;
					}
					break;
				case 3://[3]. Приведение типа к double
					for (i = 0; i < Count; i++)
					{
						std::cout << "[" << i + 1 << "] " << "(double)" << *(PFraction[i]) << "\t== " << (double)(*(PFraction[i])) << std::endl;
					}
					break;
				}//switch (C4)
				delete F;//Удаление объекта и декремент Count
			}//while (C4 != 4)//4- выход
			break;
		}//switch (C)
	}//while (C != 'е')//е - выход
	//Очистка динамической памяти
	for (i = 0, c = Fraction::GetCount(); i < c; i++)
	{
		delete PFraction[i];
	}
}