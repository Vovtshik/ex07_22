/*ex07_22.cpp*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

//const int salesmanSize = 4;

//void addingCard(double[][salesmanSize], int, int, double);

int main()
{
   const int salesmanSize = 4;
   const int productSize = 5;

   int product, salesman;
   double amount;
   double amountProduct = 0.0;
   double amountSales = 0.0;
   double sales1 = 0.0;
   double sales2 = 0.0;
   double sales3 = 0.0;
   double sales4 = 0.0;

   double sales[productSize][salesmanSize] = {0};

   while(true)
   {
      cout << "To add a sales card, enter (separated by a space) \n"
   	   << "product number, seller number, \n"
           << "the amount for which this product was sold\n"
	   << "(enter 0 to complete the entry):\n";
      cin >> product >> salesman >> amount;
      if(!product)
         break;
      sales[product - 1][salesman - 1] += amount;
      switch(salesman)
      {
         case 1:
		 sales1 += amount;
		 break;
	 case 2:
		 sales2 += amount;
		 break;
	 case 3:
		 sales3 += amount;
		 break;
	 case 4:
		 sales4 += amount;
		 break;
      }
   }

   cout << endl << endl;
   cout << "| product number | sales 1 | sales 2 | sales 3 | sales 4 | product amount |\n";
   cout << "|________________|_________|_________|_________|_________|________________|\n";

   for(int p = 0; p < productSize; p++)
   {
      cout << '|' << setw(16) << p + 1 << '|';
      for(int s = 0; s < salesmanSize; s++)
      {
	  amountProduct += sales[p][s];
          cout << setw(9) << sales[p][s] << '|';
      }
      cout << setw(16) << amountProduct << '|' << endl;
      amountProduct = 0; 
   }
   cout << "|________________|_________|_________|_________|_________|________________|\n";
   cout << '|' << setw(16) << "sales amount" << '|' << setw(9) << sales1 << '|'
        << setw(9) << sales2 << '|' << setw(9) << sales3 << '|' << setw(9) << sales4 << '|'
      	<< endl;

   return 0;
}

/*void addingCard(double sales[][salesmanSize], int product, int salesman, double proceeds)
{
   sales[product][salesman] += proceeds;
}*/
