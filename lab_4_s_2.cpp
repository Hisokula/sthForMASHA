#include <iostream>

/*Реализуйте шаблонный класс для описания матриц (в частном случае, векторов). Предусмотрите 3 шаблонных параметра: тип элемента, размеры матрицы N и M (N, M <= 3)
	В составе класса должны быть:
1.	Конструктор копирования ++++++++++
2.	Оператор присваивания копированием ++++++
3.	Оператор ввода и вывода +++++++++++++++++++++
4.	Операторы +, +=, *, *=
5.	Оператор ++, который увеличивает все элементы матрицы на 1
6.	Метод вычисления определителя
7.	Метод или оператор для получения и изменения элемента матрицы по индексу
*/

template <typename m_type>

class Matrix
{
private:
	int m_line = 1;
	int m_column = 1;
	m_type m_mas_matrix[3][3];
	template <typename m_type>
	friend std::ostream& operator<< (std::ostream& out, const Matrix <m_type>& x);
	template <typename m_type>
	friend std::istream& operator>> (std::istream& in, Matrix<m_type>& p);
public:
	Matrix(int lines, int columns)
	{
		m_line = lines;
		m_column = columns;
	};

	/// rull of 3
	Matrix(const Matrix& other) : Matrix(other.m_line, other.m_column) //copy constr (!) + delig constr
	{
		std::cout << "Copy Constuctor!" << std::endl;
	}

	Matrix& operator= (const Matrix other) // copy assigment operator
	{
		Matrix temp = other;
		std::swap(this->m_line, temp.m_line);
		std::swap(this->m_column, temp.m_column);
		return *this;
	};
	~Matrix() // destructor
	{
		std::cout << "Destructor!" << std::endl;
	}

	///
	Matrix& operator += (const Matrix& other)
	{
		Matrix tempy = other;
		tempy.m_line += this->m_line;
		tempy.m_column += this->m_column;
		std::swap(tempy.m_line, this->m_line);
		std::swap(tempy.m_column, this->m_column);
		return *this;
	}






















	/// 
	
    void SetMatrix ()
	{
		for (int i = 0; i < m_line; i++)
		{
			for (int j = 0; j < m_column; j++)
			{
				std::cin >> m_mas_matrix[i][j];
			}
		}
	}
	void ShowMatrix()
	{
		for (int i = 0; i < m_line; i++)
		{
			for (int j = 0; j < m_column; j++)
			{
				std::cout << ' ' << m_mas_matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}



};

template <typename m_type>
std::ostream& operator<< (std::ostream& out, const Matrix<m_type>& p)
{
	for (int i = 0; i < p.m_line; i++)
	{
		for (int j = 0; j < p.m_column; j++)
		{
			out << ' ' << p.m_mas_matrix[i][j] << ' ';
		}
		out << std::endl;
	}
	return out;
};

template <typename m_type>
std::istream& operator>> (std::istream& in, Matrix<m_type>& p)
{
	for (int i = 0; i < p.m_line; i++)
	{
		for (int j = 0; j < p.m_column; j++)
		{
			in >> p.m_mas_matrix[i][j];
		}
	}

	return in;
};

int main()
{
	int r = 3;
	int y = 8;
	Matrix<int> non(2, 3);
	std::cin >> non;
	std::cout << non;
	
}

