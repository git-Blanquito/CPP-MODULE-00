
#include <iostream>
#include <math.h>
using namespace std;


int main(int argc, char **argv)
{
	float medium_amount;
	float high_amount;
	float medium_price;
	float high_price;
	int	  iva;
	float price;

	medium_amount = 0;
	high_amount = 0;
	medium_price = 35.5;
	high_price = 55.3;
	iva = 21;

	if (argc > 1 && argc < 4)
	{
		medium_amount = atof(argv[1]);
		high_amount = atof(argv[2]);
	} else if (argc == 1)
	{
		std::cout << "Enter how much medium amount you want" << endl;
		std::cin >> medium_amount;
		std::cout << "Enter how much medium amount you want" << endl;
		std::cin >> high_amount;
	}
	if (argc >= 1 && argc < 4)
	{
		price = (medium_amount * medium_price) + (high_amount * high_price);
		price = price + ((iva * price) / 100);
		price = (roundf(price * 100)) / 100;
		std::cout << price << "€ avaliable for 30 days" << endl;
	} else
		std::cout << "Enter 2 parameters: [float medium_amount] and [float high_amount]" << endl;
	return (0);
}
