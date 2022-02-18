#include <iostream>
#include <cmath>
#include <windows.h>

int sqr(int a) { return a * a; };
int eqRedCirculo(int raio, int centro, int x, int y);
void circle(int tam, int centro, int raio);

int main()
{
	int tam = 29;
	int centro, raio = 12;

	centro = tam / 2;

	while (true)
	{
        system("cls");
		circle(tam, centro, raio);
        Sleep(100);
	}
}

int eqRedCirculo(int raio, int centro, int x, int y)
{
	return sqrt(sqr(x - centro) + sqr(y - centro));
    // sqrt(sqr(x - centro) + sqr(y - centro) - sqr(raio)) == 0
}

void circle(int tam, int centro, int raio)
{
	//static int d = 0;
	static bool maxRad = false;
	static int r = raio;
	for (int x = 0; x < tam; x++)
    {
        for (int y = 0; y < tam; y++)
        {
            if (eqRedCirculo(r, centro, x, y) <= r) std::cout << "\033[42m  \033[m";
            //else if (x == d && y == d) std::cout << "\033[47m#\033[m";
            else std::cout << "\033[44m  \033[m";
            //std::cout << ' ';
        }
        std::cout << '\n';
        //d++;
    }
		
    if (r < centro && !maxRad) r++;
    else
    {
        r--;
        maxRad = true;
        if (r == 0) maxRad = false;
    }
}
