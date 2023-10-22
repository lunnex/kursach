#pragma once
#include <iostream>
#include <vector>

class MorphologyTransformationOMP
{
public:

	std::vector<std::vector<int>> _matrix;
	std::vector<std::vector<int>> _transformed;
	static int _n;
	int _m;
	const int WHITE = 1;
	const int BLACK = 0;

	MorphologyTransformationOMP(std::vector<std::vector<int>>& matrix)
	{
		_matrix = matrix;
		_transformed = MakeDeepCopy();
		_n = _matrix.size();
		_m = _matrix.front().size();
	}

	std::vector<std::vector<int>> MakeDeepCopy()
	{
		std::vector<std::vector<int>> v(_matrix);
		return v;
	}

	int Erode(int kernel)
	{
		for (int i = 0; i < _n; i++) {
			for (int j = 0; j < _m; j++) {
				if (_matrix[i][j] == BLACK) {
					Transformation(i, j, kernel / 2, WHITE);
				}
			}
		}

		return 0;
	}

	int Dilatation(int kernel)
	{
		for (int i = 0; i < _n; i++) {
			for (int j = 0; j < _m; j++) {
				if (_matrix[i][j] == WHITE) {
					Transformation(i, j, kernel / 2, BLACK);
				}
			}
		}

		return 0;
	}

	int Transformation(int x, int y, int regionSize, int changeTo)
	{
		if (_matrix[x][y] != changeTo)
		{
			for (int i = x - regionSize; i < x + regionSize; i++)
			{
				for (int j = y - regionSize; j < y + regionSize; j++)
				{
					if (i >= 0 && j >= 0 && x + regionSize < _n && y + regionSize < _m && IsTransformable(x, y, regionSize, changeTo))
						_transformed[i][j] = changeTo;
				}
			}
		}

		return 0;
	}

	bool IsTransformable(int x, int y, int regionSize, int changeTo)
	{
		bool result = false;

		for (int i = x - regionSize; i < x + regionSize; i++)
		{
			for (int j = y - regionSize; j < y + regionSize; j++)
			{
				if (i >= 0 && j >= 0 && x + regionSize < _n && y + regionSize < _m)
					result |= _matrix[i][j] == changeTo;
			}
		}

		return result;
	}

	int Print() {
		for (int i = 0; i < _n; i++) {
			for (int j = 0; j < _m; j++) {
				std::cout << _transformed[i][j];
			}
			std::cout << "\n";
		}

		return 0;
	}


};