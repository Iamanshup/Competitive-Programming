int BIT[2000][2000];

// void update(int x, int y, int val)
// {
// 	while (x <= max_x)
// 	{
// 		updatey(x, y, val);
// 		x += (x & -x);
// 	}
// }

// void updatey(int x, int y, int val)
// {
// 	while (y <= max_y)
// 	{
// 		BIT[x][y] += val;
// 		y += (y & -y);
// 	}
// }

void update(int x, int y, int val)
{
	while (x <= max_x)
	{
		int y1 = y;
		while (y1 <= max_y)
		{
			BIT[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x, int y)
{
	int sum = 0;
	while (x)
	{
		int y1 = y;
		while (y1)
		{
			sum += BIT[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
}