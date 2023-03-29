#include <iostream>

/*
Реализуйте шаблонный класс для описания матриц (в частном случае, векторов). Предусмотрите 3 шаблонных параметра: тип элемента, размеры матрицы N и M (N, M <= 3)
	В составе класса должны быть:
1.	Конструктор копирования
2.	Оператор присваивания копированием
3.	Оператор ввода и вывода
4.	Операторы +, +=, *, *=
5.	Оператор ++, который увеличивает все элементы матрицы на 1
6.	Метод вычисления определителя
7.	Метод или оператор для получения и изменения элемента матрицы по индексу

*/


template <typename T> 
class Matrix
{
private:

	size_t m_i = 0;
	size_t m_j = 0;
	T m_mx[2][2];

public:

	friend std::ostream& operator << (std::ostream& out, const Matrix& str);
	friend std::istream& operator >> (std::istream& in, Matrix<T>& str);

	Matrix(size_t i1, size_t j1)
	{
		m_i = i1;
		m_j = j1;

		for (int i = 0; i < i1; i++)
		{
			for (int j = 0; j < j1; j++)
			{
				m_mx[i][j] = 0;
			}
		}
	}
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& str)
{

	return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& str)
{

	return in;
}

int main()
{
	Matrix<int> m(2, 2);
}