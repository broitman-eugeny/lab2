int Evklid(int a, int b)//����������� ��� �� ��������� �������
{
	int k;

	while (0 != (k = a%b))
	{
		a = b;
		b = k;
	}
	return (b>0)?b:-b;
}