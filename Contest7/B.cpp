#include <iostream>

int main()
{
   int N;
   int length = 0;
   std::cin >> N;
   int* array = new int[N];
   for (int i = 0; i < N; i++)
   {
       std::cin >> array[i];
   }
   for (int i=0; i < N; i++)
   {
       if ( ( (array[i] % 4 == 0) && ( (array[i] / 1000 != 4) && (array[i] / 1000 != 5) ) )  ||
          (   (array[i] % 7 == 0) && ( (array[i] / 1000 != 1) && (array[i] / 1000 != 7) ) )  ||
          (   (array[i] % 9 == 0) && ( (array[i] / 1000 != 8) && (array[i] / 1000 != 9) ) ))
       {
           std::cout << array[i] << std::endl;
           length += 1;
       }
   }
   if (length == 0)
   {
       std::cout << 0 << std::endl;
   }
   delete [] array;
return 0;
}
