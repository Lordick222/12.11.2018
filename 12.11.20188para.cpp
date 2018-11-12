#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <cmath>
#include <fstream>
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// ðàâíîìåðíî ðàñïðåäåëÿåì ðàíäîìíîå ÷èñëî â íàøåì äèàïàçîíå
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	getRandomNumber(1, 100);
	int a, b, c, d;
	std::cout << "shirina 1 mas   ";
	std::cin >> a;
	std::cout << "dlina 1 mas   ";
	std::cin >> b;
	int **ptrarray1 = new int*[a];
	int **ptrarray2 = new int*[a];
	for (int count = 0; count < a; count++)
	{
		ptrarray1[count] = new int[b];
	}  // 1 massiv
	for (int count = 0; count < a; count++)
	{
		ptrarray2[count] = new int[b];
	}  // 1 massiv
	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			ptrarray1[count_row][count_column] = getRandomNumber(0, 20); //zapolnenie1
		}
	}
	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			std::cout << ptrarray1[count_row][count_column] << "\t";
		}
		std::cout << "\n";
	}
	std::ofstream out("F:\\smendiag.txt");                                      // WRITE TO FILE DISK F
	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			out << ptrarray1[count_row][count_column] << "\t";
		}
		out << "\n";
	}
	out << "\n";
	std::cout << " \n\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n ";
	std::vector<int> glavn;
	std::vector<int> pob;
	std::vector<int> glavn1;
	std::vector<int> pob1;
	int z{ 0 };
	for (int i{ 0 }; i < a; i++)
	{
		if (i < (a / 2))
		{
			glavn.push_back(ptrarray1[i][i]);
			std::cout << " i: " << glavn[i] << "   ";
		}
		if ((a % 2) > 0)
		{
			if (i > (a / 2))
			{
				glavn1.push_back(ptrarray1[i][i]);
				std::cout << " i: " << glavn1[z] << "   ";
				z++;
			}
		}
		else
		{
			if ((i > (a / 2))||(i== (a / 2)))
			{
				glavn1.push_back(ptrarray1[i][i]);
				std::cout << " i: " << glavn1[z] << "   ";
				z++;
			}
		}
	}
	std::cout << " \nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n ";
	c = a - 1;
	int v{ 0 };
	z = 0;
	for (int i{ c }; i > -1; i--)
	{
		if ((a % 2) > 0)
		{
			if (i > (a / 2))
			{
				pob.push_back(ptrarray1[v][i]);
				std::cout << "  " << i << ": " << pob[v] << "   ";
				v++;
			}
			if (i == (a / 2))
			{
				v++;
			}
		}
		else 
		{
			if ((i > (a / 2))|| (i ==(a / 2)))
			{
				pob.push_back(ptrarray1[v][i]);
				std::cout << "  " << i << ": " << pob[v] << "   ";
				v++;
			}
		}
		if (i < (a / 2))
		{
			pob1.push_back(ptrarray1[v][i]);
			std::cout << "  " << i << ": " << pob1[z] << "   ";
			v++;
			z++;
		}
	}
	std::cout << " \nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n ";
	z = 0;




	for (int i{ 0 }; i < a; i++)
	{
		if (i < (a / 2))
		{
			ptrarray1[i][i] = pob[i];
		}
		if ((a % 2) > 0)
		{
			if (i > (a / 2))
			{
				ptrarray1[i][i] = pob1[z];
				z++;
			}
		}
		else
		{
			if ((i > (a / 2))|| (i == (a / 2)))
			{
				ptrarray1[i][i] = pob1[z];
				z++;
			}
		}
	}
	z = 0;
	int u{ 0 };
	v = 0;
	std::reverse(glavn1.begin(), glavn1.end());
	std::reverse(glavn.begin(), glavn.end());
	for (int i{ c }; i > -1; i--)
	{
		if ((a % 2) > 0)
		{
			if (i > (a / 2))
			{
				ptrarray1[v][i] = glavn1[z];
				z++;
				v++;
			}
			if (i == (a / 2))
			{
				v++;
			}
		}
		else
		{
			if ((i > (a / 2))||(i == (a / 2)))
			{
				ptrarray1[v][i] = glavn1[z];
				z++;
				v++;
			}
		}
		if (i < (a / 2))
		{
			ptrarray1[v][i] = glavn[u];
			u++;
			v++;
		}
	}




	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			std::cout << ptrarray1[count_row][count_column] << "\t";
		}
		std::cout << "\n";
	}




	for (int count_row = 0; count_row < a; count_row++)
	{
		for (int count_column = 0; count_column < b; count_column++)
		{
			out << ptrarray1[count_row][count_column] << "\t";
		}
		out << "\n";
	}
	out.close();
	system("pause");
	return 0;
}