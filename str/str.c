#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void replace_blank(char string[], int length)
{
	if(string == NULL || length <= 0)
	{
		return;
	}

	int original_length = 0;
	int new_length = 0;
	int number_blank = 0;
	int i = 0;

	while(string[i] != '\0')
	{
		++original_length;

		if (string[i] == ' ')
		{
			++number_blank;
		}

		++i;
	}

	new_length = original_length + number_blank * 2;

	if(new_length > length)
	{
		return;
	}

	int index_original = original_length;
	int index_new = new_length;

	while(index_original >= 0 && index_new > index_original)
	{
		if(string[index_original] == ' ')
		{
			string[index_new --] = '0';
			string[index_new --] = '2';
			string[index_new --] = '%';
		}else
		{
			string[index_new --] = string[index_original];
		}
		index_original--;
	
	}

}

void display_string(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		printf("%c", string[i ++]);
	}
	printf("\n");
}

int main(int argc, const char *argv[])
{

	char str[100] = "chen  bing    bin";
	display_string(str);

	replace_blank(str,100);
	display_string(str);

	return 0;
}