#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, input, i, num = 1, result;

	while(true)
	{
		scanf("%d", &n);
		if(n == 0) break;
		
		i = 1;
		while(n-- > 0)
		{
			scanf("%d", &input);
			if(input == i)
				result = input;
			i++;
		}
		printf("Teste %d\n%d\n\n", num++, result);
	}
	return 0;
}
