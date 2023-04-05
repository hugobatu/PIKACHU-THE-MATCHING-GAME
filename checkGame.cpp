#include "checkGame.h"


bool CheckSelectedAndMatched(pokemon **map, int x1, int y1, int x2, int y2)
{
	if (map[y1][x1].selected == 1 && map[y1][x1].matched == 0 && map[y2][x2].selected == 1 && map[y2][x2].matched == 0)
	{	
		return true;
	}
	
	return false;
}

void selectedCell(pokemon **&map, int x1, int y1, int x2, int y2)
{
	map[y1][x1].selected = 1;
	map[y2][x2].selected = 1;
}

void unselectedCell(pokemon**& map, int x1, int y1, int x2, int y2)
{
	map[y1][x1].selected = 0;
	map[y2][x2].selected = 0;
}

void matchedCell(pokemon**& map, int x1, int y1, int x2, int y2)
{
	map[y1][x1].matched = 1;
	map[y2][x2].matched = 1;
}

bool checkTwoCharacter(pokemon** map, int x1, int y1, int x2, int y2)
{
	if (map[y1][x1].chr ==  map[y2][x2].chr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int findMin(int x, int y)
{
	return (x < y) ? x : y;
}

int findMax(int x, int y)
{
	return (x > y) ? x : y;
}

bool checkLineX(pokemon** map, int y1, int y2, int x)
{
	int min = findMin(y1, y2);
	int max = findMax(y1, y2);

	int dem = 0;

	for (int i = min + 1; i < max; i++)
	{
		if (map[i][x].matched == 0)
			dem++;
	}

	if (dem != 0)
		return false;
	return true;
}
bool checkLineY(pokemon** map, int x1, int x2, int y) 
{
	int min = findMin(x1, x2);
	int max = findMax(x1, x2);
	int dem = 0;
	for (int i = min + 1; i < max; i++)
	{
		if (map[y][i].matched == 0)
			dem++;
	}
	if (dem != 0)
		return false;
	return true;
}


bool Icheck(pokemon** map, int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		int x = findMin(y1, y2), y = findMax(y1, y2);
		for (int i = x + 1; i < y; i++)
			if (map[i][x1].matched == 0)
				return false;
		return true;
	}
	else if (y1 == y2)
	{
		int x = findMin(x1, x2), y = findMax(x1, x2);
		for (int i = x + 1; i < y; i++)
			if (map[y1][i].matched == 0)
				return false;
		return true;
	}
	return false;
}

bool Lcheck(pokemon** map, int x1, int y1, int x2, int y2)
{	
	if (y1 == y2 || x1 == x2)
		return false;
	if (y1 > y2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	int dem = 0, count = 0;
	int x = findMin(x1, x2), y = findMax(x1, x2);
	// doc
	for (int i = y1; i <= y2; i++)
	{
		if (map[i][x1].matched == 0)
			dem++;
	}
	if (dem == 1)
	{
		for (int i = x; i <= y; i++)
		{
			if (map[y2][i].matched == 0)
				count++;
		}
		if (count == 1)
			return true;
	}
	// ngang
	dem = 0;
	count = 0;
	for (int i = x; i <= y; i++)
	{
		if (map[y1][i].matched == 0)
			dem++;
	}
	if (dem == 1)
	{

		for (int i = y1; i <= y2; i++)
		{
			if (map[i][x2].matched == 0)
				count++;
		}
		if (count == 1)
			return true;
	}
	return false;
}

bool Zcheck(pokemon** map, int x1, int y1, int x2, int y2)
{
	if (y1 > y2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	int x = findMin(x1, x2), y = findMax(x1, x2);
	
	int count1 = 0; int count2 = 0;
	if (x1 < x2)
	{
		// Z nam doc
		for (int i = x1 + 1; i < x2; i++)
		{	
			count1 = 0, count2 = 0;
			if (map[y1][i].matched == 1)
			{
				for (int j = y1; j < y2; j++)
				{
					if (map[j][i].matched == 0)
						count1++;
				}
				for (int j = i; j < x2; j++)
				{
					if (map[y2][i].matched == 0)
						count2++;
				}

				if (count1 == 0 && count2 == 0)
					return true;
			}
			else
				break;
		}

		// Z nam ngang
		for (int i = y1 + 1; i < y2; i++)
		{	
			count1 = 0, count2 = 0;
			if (map[i][x1].matched == 1)
			{
				for (int j = x1; j < x2; j++)
				{
					if (map[i][j].matched == 0)
						count1++;
				}
				for (int j = i; j < y2; j++)
				{
					if (map[j][x2].matched == 0)
						count2++;
				}

				if (count1 == 0 && count2 == 0)
					return true;
			}
			else
				break;
		}
	}

	else if (x1 > x2)
	{
		// Z nam doc 
		for (int i = x2 + 1; i < x1; i++)
		{
			count1 = 0, count2 = 0;
			if (map[y2][i].matched == 1)
			{
				for (int j = y1; j < y2; j++)
				{
					if (map[j][i].matched == 0)
						count1++;
				}
				for (int j = i; j < x1; j++)
				{
					if (map[y1][j].matched == 0)
						count2++;
				}

				if (count1 == 0 && count2 == 0)
					return true;
			}
			else
				break;
		}	
		// Z nam ngang
		for (int i = y1 + 1; i < y2; i++)
		{
			count1 = 0, count2 = 0;
			if (map[i][x1].matched == 1)
			{
				for (int j = x2; j < x1; j++)
				{
					if (map[i][j].matched == 0)
						count1++;
				}
				for (int j = i; j < y2; j++)
				{
					if (map[j][x2].matched == 0)
						count2++;
				}

				if (count1 == 0 && count2 == 0)
					return true;
			}
			else
				break;
		}
	}

	return false;
}

bool Ucheck(pokemon** map, int x1, int y1, int x2, int y2)
{
	int m = findMin(y1, y2), n = findMax(y1, y2);
	int x = findMin(x1, x2), y = findMax(x1, x2);
	//U sang trai
	for (int i = y + 1; i < 10; i++) {
		if (map[y1][i].matched == 1) {
			int dem = 0, count1 = 0, count2 = 0;
			for (int j = m; j <= n; j++) {
				if (map[j][i].matched == 0)
					dem++;
			}
			if (dem == 0) {
				for (int k = x1 + 1; k <= i; k++) {
					if (map[y1][k].matched == 0)
						count1++;
				}
				for (int k = x2 + 1; k <= i; k++) {
					if (map[y2][k].matched == 0)
						count2++;
				}
				if (count1 == 0 && count2 == 0) return true;
			}
		}
	}
	//U sang phai
	for (int i = x - 1; i >= 0; i--) {
		if (map[y1][i].matched == 1) {
			int dem = 0, count1 = 0, count2 = 0;
			for (int j = m; j <= n; j++) {
				if (map[j][i].matched == 0)
					dem++;
			}
			if (dem == 0) {
				for (int k = x1 - 1; k >= i; k--) {
					if (map[y1][k].matched == 0)
						count1++;
				}
				for (int k = x2 - 1; k >= i; k--) {
					if (map[y2][k].matched == 0)
						count2++;
				}
				if (count1 == 0 && count2 == 0) return true;
			}
		}
	}
	// u xuong
	for (int i = n + 1; i < 7; i++)
	{
		if (map[i][x2].matched == 1)
		{
			int dem = 0, count1 = 0, count2 = 0;
			for (int j = x; j <= y; j++)
			{
				if (map[i][j].matched == 0)
					dem++;
			}
			if (dem == 0)
			{
				for (int k = y1 + 1; k <= i; k++)
				{
					if (map[k][x1].matched == 0)
						count1++;
				}
				for (int k = y2 + 1; k <= i; k++)
				{
					if (map[k][x2].matched == 0)
						count2++;
				}
				if (count1 == 0 && count2 == 0)
					return true;
			}
		}
	}
	// U len
	for (int i = m - 1; i >= 0; i--)
	{
		if (map[i][x1].matched == 1)
		{
			int dem = 0, count1 = 0, count2 = 0;
			for (int j = x; j <= y; j++)
			{
				if (map[i][j].matched == 0)
					dem++;
			}
			if (dem == 0)
			{
				for (int k = y1 - 1; k >= i; k--)
				{
					if (map[k][x1].matched == 0)
						count1++;
				}
				for (int k = y2 - 1; k >= i; k--)
				{
					if (map[k][x2].matched == 0)
						count2++;
				}
				if (count1 == 0 && count2 == 0)
					return true;
			}
		}
	}
	return false;
}

bool allCheck(pokemon** map, int x1, int y1, int x2, int y2)
{
	if (checkTwoCharacter(map, x1, y1, x2, y2) && CheckSelectedAndMatched(map, x1, y1, x2, y2))
	{
		if (Icheck(map, x1, y1, x2, y2) == true)
		{

			cout << "Icheck";
			return true;
		}
		else if (Lcheck(map, x1, y1, x2, y2) == true)

		{
			cout << "Lcheck";
			return true;
		}
		else if (Zcheck(map, x1, y1, x2, y2) == true)

		{
			cout << "Zcheck";
			return true;
		}
		else if (Ucheck(map, x1, y1, x2, y2) == true)
		{
			cout << "Ucheck";
			return true;
		}

	}
		return false;
}