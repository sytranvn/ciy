#include "intergral-image.cpp"

int main() {
	int row, col;

	scanf("%d %d", &row, &col);

	int **arr = (int **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++) {
		arr[i] = (int *)malloc(col * sizeof(int));
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	IntergralImage* ii = new IntergralImage(arr, row, col);

	ii->print_ii();

	return 0;
}
