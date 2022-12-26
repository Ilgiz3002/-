#include <iostream>
#include <windows.h>
using namespace std;
bool* visits;
bool** adjacencyMatrix;
void Generator(bool** _matrix0, int _SIZE0)
{
	for (int row = 0; row < _SIZE0; ++row)
	{
		_matrix0[row] = new bool[_SIZE0];
	}
	for (int row = 0; row < _SIZE0; ++row)
	{
		for (int col = 0; col < _SIZE0; ++col)
		{
			_matrix0[row][col] = 0;
		}
	}
	cout << "Введите элементы массива"<< endl;
	for (int row = 0; row < _SIZE0; ++row)
	{
		for (int col = 0; col < _SIZE0; ++col)
		{
			if (row < col)
			{
				cin >> _matrix0[row][col];
				_matrix0[col][row] = _matrix0[row][col];
			}
		}
	}
	for (int counter = 0; counter < _SIZE0; ++counter)
	{
		_matrix0[counter][counter] = 0;
	}
}

void Generatorrand(bool** _matrix, int _SIZE)
{
	for (int row = 0; row < _SIZE; ++row)
	{
		_matrix[row] = new bool[_SIZE];
	}
	for (int row = 0; row < _SIZE; ++row)
	{
		for (int col = 0; col < _SIZE; ++col)
		{
			_matrix[row][col] = 0;
		}
	}
	bool buffer = 0;
	for (int row = 0; row < _SIZE; ++row)
	{
		for (int col = 0; col < _SIZE; ++col)
		{
			buffer = rand() % 2;
			_matrix[row][col] = buffer;
			_matrix[col][row] = buffer;
		}
	}
	for (int counter = 0; counter < _SIZE; ++counter)
	{
		_matrix[counter][counter] = 0;
	}
}

void Output(bool** _matrix, int _SIZE)
{
	for (int row = 0; row < _SIZE; ++row)
	{
		for (int col = 0; col < _SIZE; ++col)
		{
			cout << _matrix[row][col] << ' ';
		}
		cout << endl;
	}
}

void Zero(bool* _matrix, int _SIZE)
{
	for (int counter = 0; counter < _SIZE; ++counter)
	{
		_matrix[counter] = 0;
	}
}

void Pass(int _num, bool* _visits, bool** _matrix, int _SIZE)
{
	_visits[_num] = 1;
	cout << _num << "  ";
	for (int i = 0; i < _SIZE; ++i)
	{
		if (_matrix[_num][i] == 1 && _visits[i] == 0)
		{
			Pass(i, _visits, _matrix, _SIZE);
		}
	}
}

int main()
{
	setlocale(0, "rus");
	cout << "Меню:" << endl;
	int input;
	cout << "Сгенерировать матрицу автоматически (1)" << endl;
	cout << "Ввести матрицу (2)" << endl;
	cout << "Выход (3)" << endl;
	cin >> input;
	if (input == 1) {
		cout << "Введите размер матрицы" << endl;
		int SIZE;
		cin >> SIZE;
		adjacencyMatrix = new bool* [SIZE];
		visits = new bool[SIZE];
		Zero(visits, SIZE);
		Generatorrand(adjacencyMatrix, SIZE);
		Output(adjacencyMatrix, SIZE);
		int ver;
		cout << "Введите вершину обхода" << endl;
		cin >> ver;
		cout << endl << "Пройденные вершины: " << endl;
		Pass(ver, visits, adjacencyMatrix, SIZE);

	}
	if (input == 2) {
		cout << "Введите размер матрицы" << endl;
		int sizee;
		cin >> sizee;
		adjacencyMatrix = new bool* [sizee];
		visits = new bool[sizee];
		Zero(visits, sizee);
		Generator(adjacencyMatrix, sizee);
		Output(adjacencyMatrix, sizee);
		int ver;
		cout << "Введите вершину обхода" << endl;
		cin >> ver;
		cout << endl << "Пройденные вершины: " << endl;
		Pass(ver, visits, adjacencyMatrix, sizee);
	}
	if (input == 3) {
		exit(0);
	}
	delete[] adjacencyMatrix;
	delete[] visits;
}
