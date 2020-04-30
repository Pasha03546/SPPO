#include<iostream>
using namespace std;

struct list
{
	int value;
	list* next;
	list()
	{
		value = 0;
		next = NULL;
	}
};
void Add_0(list*& first)
{
	int i = 1;
	list* l = first;
	list* p = l;

	while (l != NULL)
	{
		if (i % 2 != 0)
		{
			p = l;
			l = l->next;
		}
		else
		{
			list* add = new list();
			p->next = add;
			add->next = l;
		}
		i++;
	}

}
void InputList(list*& first, int n)
{
	float z;
	cout << "Введите элементы списка: " << endl;
	list* p = first;
	int i = 0;
	while (i < n)
	{
		cin >> z;
		p->value = z;
		if (i != n - 1)
		{
			p->next = new list();
			p = p->next;
		}
		i++;
	}
}
void OutputList(list* l)
{
	while (l != NULL)
	{
		cout << l->value;
		l = l->next;
		if (l != NULL)cout << ", ";
	}
	cout << endl;
}
int main()
{
	list* first = new list();
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество элементов списка: " << endl;
	cin >> n;

	InputList(first, n);
	Add_0(first);
	OutputList(first);
	system("pause");
	return 0;
}