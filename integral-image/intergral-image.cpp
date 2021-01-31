#include <stdio.h>
#include <cstdlib>
#include <utility>

typedef std::pair<size_t, size_t> Pos;
void print_arr2(int **arr, int row, int col);
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
		m_ii = (int **)malloc(m_x * sizeof(int *)); // init m_x * m_y grid

		for (int i = 0; i < m_x; i++)
		{
			m_ii[i] = (int *)calloc(0, m_y * sizeof(int)); // set all to zeros
		}

		for (int i = 0; i < m_x; i++)
		{ //calucate feature value
			int s = 0;
			for (int j = 0; j < m_y; j++)
			{
				// s(x,y) = s(x,y-1) + img(x,y)
				// ii(x,y) = ii(x-1, y) + s(x,y)
				s += img[i][j]; // we dont have extra row and column in original image
				m_ii[i][j] = (i > 0 ? m_ii[i - 1][j] : 0) + s;
			}
		}
	};

	int **ii()
	{
		return m_ii;
	}

	void print_ii()
	{
		print_arr2(m_ii, m_x, m_y);
	}

	/**
	 * get actual sum of <Top, Left>, <Bottom, Right> rectangle
	 */
	int sum(Pos tl, Pos br)
	{
		int a = tl.first && tl.second ? m_ii[tl.first - 1][tl.second - 1] : 0;
		int b = tl.first ? m_ii[tl.first - 1][br.second] : 0;
		int c = tl.second ? m_ii[br.first][tl.second - 1] : 0;
		int d = m_ii[br.first][br.second];

		return d + a - (b + c);
	}

	~IntergralImage() {}
};

void print_arr2(int **arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int j;
		for (j = 0; j < col - 1; j++)
			printf("%d ", arr[i][j]);
		printf("%d", arr[i][j]);
		printf("\n");
	}
}
