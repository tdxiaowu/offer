#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct arrayInfo{
	int *pointer;
	int length;
}arrInfo;


arrInfo create_array(int array_size, int value, int seed)
{
	int i, size = 0;
	int *arr = NULL;
	arrInfo arr_info;

	srand((int)time(NULL) + seed);

	do{
		size = rand() % array_size;
	}while(size == 0);
	
	arr = (int *)malloc(sizeof(int) * size);

	if (!arr)
	{
		printf("array malloc failed!\n");
		exit(1);
	}

	for(i = 0; i < size; i++)
	{
		do{
			*(arr + i) = rand() % value;
		}while(arr[i] == 0);
		
	}

	arr_info.pointer = arr;
	arr_info.length = size;

	return arr_info;

}


void display(int arr[], int len)
{
	printf("display the array:\n");
	int i;

	for(i = 0; i < len; i++)
	{
		printf("%d\t", arr[i]);
	}

	printf("\n");
}

void bubble_sort(int arr[], int len)
{
	int i, j;
	int temp;

	for(i = 0; i < len - 1; i++)
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


void insert_sort(int arr[], int len)
{
	int i, preindex;
	int key;

	for(i = 1; i < len; i++)
	{
		key = arr[i];
		preindex = i - 1;

		while(preindex >= 0 && key < arr[preindex])
		{
			arr[preindex + 1] = arr[preindex];
			preindex -= 1;
		}

		arr[preindex + 1] = key;
	}
}

void selection_sort(int arr[], int len)
{
	int i,j;
	int temp;
	int min;

	for(i = 0; i < len-1; i++)
	{
		min = i;
		for(j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}

		}

		if(min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void shell_sort(int arr[], int len)
{
	int i,gap;
	int key, preindex;

	for(gap = len / 2; gap > 0; gap /= 2)
	{
		for(i = gap; i < len; i++)
		{
			key = arr[i];
			preindex = i - gap;

			while(preindex >= 0 && key < arr[preindex])
			{
				arr[preindex + gap] = arr[preindex];
				preindex -= gap;
			}

			arr[preindex + gap] = key;
		}
	}
}


void quick_sort(int arr[], int left, int right)
{
	if(left >= right)
	{
		return;
	}

	int key = arr[left];
	int i = left;
	int j = right;
	

	while(i < j)
	{
		while(i < j && arr[j] >= key)
		{
			j--;
		}
		arr[i] = arr[j];

		while(i < j && key >= arr[i])
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = key;

	quick_sort(arr,left,i - 1);
	quick_sort(arr,i + 1,right);
}

int main(int argc, char const *argv[])
{
	int max_arr_size = 10;
	int max_arr_value = 30;
	int seed, test_time = 2;
	arrInfo arr;

	for(seed = 0; seed < test_time; seed++)
	{
		arr = create_array(max_arr_size, max_arr_value, seed);


		display(arr.pointer,arr.length);

		// bubble_sort(arr.pointer,arr.length);
		// insert_sort(arr.pointer,arr.length);
		// selection_sort(arr.pointer,arr.length);
		// shell_sort(arr.pointer,arr.length);
		quick_sort(arr.pointer, 0,arr.length - 1);




		printf("sorted:");
		display(arr.pointer,arr.length);


		free(arr.pointer);
	}
	return 0;
}