#include <iostream>
#include <algorithm>

/*
Реализуйте шаблонный класс для описания матриц (в частном случае, векторов). Предусмотрите 3 шаблонных параметра: тип элемента, размеры матрицы N и M (N, M <= 3)
	В составе класса должны быть:
1.	Конструктор копирования													+
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
	T m_mx[3][3] = {};

public:

	template <typename T>
	friend std::ostream& operator << (std::ostream& out, const Matrix<T>& mx);
	template <typename T>
	friend std::istream& operator >> (std::istream& in, Matrix<T>& mx);

	~Matrix() { };

	explicit Matrix(size_t i1, size_t j1)
	{
		m_i = i1;
		m_j = j1;
	}

	/*explicit Matrix(size_t i1, size_t j1, T mx[3][3])
	{
		m_i = i1;
		m_j = j1;

		for (int i = 0; i < i1; i++)
		{
			for (int j = 0; j < j1; j++)
			{
				m_mx[i][j] = mx[i][j];
			}
		}
	}*/

	Matrix(const Matrix& other) : Matrix(other.m_i, other.m_j) { }


	Matrix& operator = (const Matrix& other)
	{
		Matrix tmp = other;
		std::swap(this->m_i, tmp.m_i);
		std::swap(this->m_j, tmp.m_j);
		
		for (int i = 0; i < tmp.m_i; i++)
		{
			for (int j = 0; j < tmp.m_j; j++)
			{
				this->m_mx[i][j] += tmp.m_mx[i][j];
			}
		}

		return *this;
	}

};

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& mx)
{
	for (int i = 0; i < mx.m_i; i++)
	{
		out << "( ";
		for (int j = 0; j < mx.m_j; j++)
		{
			out << mx.m_mx[i][j] << " ";
		}
		out << ")" << std::endl;
	}
	return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& mx)
{
	for (int i = 0; i < mx.m_i; i++)
	{
		for (int j = 0; j < mx.m_j; j++)
		{
			in >> mx.m_mx[i][j];
		}
	}
	return in;
}

int main()
{
	Matrix<int> m(1, 1);
	std::cin >> m;
	Matrix<int> x(1, 1);
	x = m;
	std::cout << x;
}