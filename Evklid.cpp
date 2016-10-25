int Evklid(int a, int b)//Определение НОД по алгоритму Евклида
{
	int k;

	while (0 != (k = a%b))
	{
		a = b;
		b = k;
	}
	return (b>0)?b:-b;
}