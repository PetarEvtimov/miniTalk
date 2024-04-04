#include <unistd.h>

int main(void)
{
	char one = 1;
	char arr[] = "Hello world";
	int i = 0;
	int j = 0;
	char c;

	while(arr[i])
	{
		c = arr[i];
		j = 7;
		while(j)
		{
			j--;
		}
		i++;
	}
	return(0);
}