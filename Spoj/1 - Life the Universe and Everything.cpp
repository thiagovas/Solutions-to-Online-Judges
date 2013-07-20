#include<cstdio>
using namespace std;

int main()
{
   int value;
   while(scanf("%d", &value) != EOF)
   {
      if(value == 42)
         break;
      printf("%d\n", value);
   }
   return 0;
}
