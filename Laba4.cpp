#include <iostream>

using namespace std;

struct TreeElement
{
	int value;
	TreeElement* right;
	TreeElement* left;
	TreeElement()
	{
		value = 0;
		right = NULL;
		left = NULL;
	}
};
struct ListElement
{
	int value;
	ListElement* pointer;
	ListElement()
	{
		value = -1;
		pointer = NULL;
	}
};
void Input(TreeElement*& el, int v)
{
	if (el == NULL)
	{
		el = new TreeElement();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
void Output(TreeElement* el)
{
	if (el != NULL)
	{

		Output(el->left);
		cout << el->value << " ";
		Output(el->right);

	}
}
void Detach(TreeElement* root, TreeElement* el)
{
	if (root == NULL || el == NULL)
	{
		return;
	}
	else if (root->left == el)
	{
		root->left = NULL;
	}
	else if (root->right == el)
	{
		root->right = NULL;
	}
	{
		Detach(root->left, el);
		Detach(root->right, el);
	}
}
void Remove(TreeElement* el)
{
	if (el != NULL)
	{
		Remove(el->left);
		Remove(el->right);
		delete el;
	}
}
TreeElement* Find(TreeElement* el, int v)
{
	TreeElement* result = NULL;
	if (el == NULL)
	{
		result = NULL;
	}
	else if (el->value == v)
	{
		result = el;
	}
	else
	{
		result = Find(el->left, v);
		if (result == NULL)
		{
			result = Find(el->right, v);
		}
	}
	return result;
}
void Spisok(ListElement*& one, TreeElement* el, ListElement*& p)
{
	if (el != NULL)
	{
		Spisok(one, el->left, p);
		ListElement* p1 = new ListElement();
		p1->value = el->value;
		if (p == NULL) {
			one = p1;
			p = p1;
		}
		else {
			p->pointer = p1;
			p = p1;
		}
		Spisok(one, el->right, p);
	}
}
void OutputList(ListElement* l) {
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	TreeElement* root = NULL;
	ListElement* first = NULL;
	int n = 0, s;
	cout << "Введите длину элементов = ";
	cin >> n;
	cout << "Введите элементы = " << endl;
	for (int i = 0; i < n; i++) {
		cin >> s;
		Input(root, s);
	}
	Output(root);
	cout << endl;
	int kr;
	cout << "Введите элемент, поддерево которого вы хотите удалить = ";
	cin >> kr;

	TreeElement* e = Find(root, kr);
	Detach(root, e);
	Remove(e);
	Output(root);
	cout << endl;

	cout << "Список ";
	ListElement* l = NULL;
	Spisok(first, root, l);
	OutputList(first);
	return 0;
}