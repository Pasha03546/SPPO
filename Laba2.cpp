#include <iostream>

using namespace std;

void F1(double*& mas, int& n)
{
	int m = (n * 2) - 1;
	double* mas2 = new double[m];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		mas2[j] = mas[i];
		mas2[j + 1] = 0;
		j = j + 2;
	}
	n = m;
	mas = mas2;

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Ввидиьте длину массива" << " ";
	cin >> n;
	cout << "Ввидите массив" << endl;
	double* mas = new double[n];
	for (int i = 0; i < n; i++) { cin >> mas[i]; }
	F1(mas, n);
	for (int i = 0; i < n; i++) { cout << mas[i] << " "; }
	system("pause");
	return 0;
}