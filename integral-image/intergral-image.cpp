#include <stdio.h>
#include <cstdlib>
#include <utility>

typedef std::pair<size_t, size_t> Pos;
void print_arr2(int** arr, int row, int col);
class IntergralImage
{
	size_t m_x, m_y;
	int **m_ii;

public:
	IntergralImage(){};
	IntergralImage(int **img, int x, int y)
	{
		m_x = x;
		m_y = y;
		m_ii = (int**)malloc(m_x * sizeof(int*)); // init m_x * m_y grid

		for (int i = 0; i < m_x; i++)
		{
			m_ii[i] = (int*)calloc(0, m_y * sizeof(int)); // set all to zeros
		}

		for (int i = 0; i < m_x; i++)
		{ //calucate feature value
			int s = 0;
			for (int j = 0; j < m_y; j++)
			{
				// s(x,y) = s(x,y-1) + img(x,y)
				// ii(x,y) = ii(x-1, y) + s(x,y)
				s += img[i][j]; // we dont have extra row and column in original image
				m_ii[i][j] = (i > 0 ? m_ii[i - 1][j] : 0 ) + s;
			}
		}
	};

	int** ii() {
		return m_ii;
	}

	void print_ii() {
		print_arr2(m_ii, m_x, m_y);
	}

	/**
	 * get actual sum of <Top, Left>, <Bottom, Right> rectangle
	 */
	int s_at(Pos tl, Pos br)
	{
		if (tl.first < 0 || tl.second < 0 ||  br.first > m_x - 1 || br.second > m_y - 1)
		{
			perror("Index out of range");
			return -1;
		}
		int a = m_ii[tl.first + 1][tl.second + 1];
		int b = m_ii[tl.first + 1][br.second + 1];
		int c = m_ii[br.first + 1][tl.second + 1];
		int d = m_ii[br.first + 1][br.second + 1];
		return d + a - (b + c);
	}

	~IntergralImage() {}
};

void print_arr2(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		int j;
		for (j = 0; j < col - 1; j++)
			printf("%d ", arr[i][j]);
		printf("%d", arr[i][j]);
		printf("\n");
	}
}
