#include "intergral-image.cpp"

int main()
{
	int row, col;

	scanf("%d %d", &row, &col);

	int **arr = (int **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++)
	{
		arr[i] = (int *)malloc(col * sizeof(int));
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	IntergralImage *ii = new IntergralImage(arr, row, col);

	ii->print_ii();

	printf("sum {0,0}, {2,2}: %d\n", ii->sum({0, 0}, {2, 2}));
	printf("sum {1,1}, {2,2}: %d\n", ii->sum({1, 1}, {2, 2}));
	printf("sum {1,1}, {3,3}: %d\n", ii->sum({1, 1}, {3, 3}));
	printf("sum {%d,%d}, {%d,%d}: %d\n",
		 row - 1, col - 1,
		 row - 1, col - 1,
		 ii->sum({row - 1, col - 1}, {row - 1, col - 1}));

	return 0;
}
