#include <iostream>

using namespace std;

int main()
{
	char card[54][3] = { 0, }; //使用54*2的字符数组存储牌
	char newCard[54][3] = { 0, }; //使用54*2的字符数组存储牌
	char acard[4] = { 'S', 'H', 'C', 'D' };
	int index = -1;
	int cnt = 0;
	int order[54] = { 0, };
	for (int i = 0; i < 52; i++)
	{
		cnt++;
		if (i % 13 == 0)
		{
			index++;
		}
		if (cnt > 9)
		{
			card[i][0] = acard[index];
			card[i][1] = 1 + '0';
			card[i][2] = (cnt % 10) + '0';
		}
		else
		{
			card[i][0] = acard[index];
			card[i][1] = cnt + '0';
			card[i][2] = ' ';
		}
		if (cnt == 13)
			cnt = 0;
		
	}
	card[52][0] = 'J';
	card[52][1] = '1';
	card[52][2] = ' ';
	card[53][0] = 'J';
	card[53][1] = '2';
	card[53][2] = ' ';

	cin >> cnt; //读入翻转次数
	char temp[3] = { 0, };

	for (int j = 0; j < 54; j++) //读入顺序的同时进行第一次交换。
	{
		cin >> order[j];
		newCard[order[j] - 1][0] = card[j][0];
		newCard[order[j] - 1][1] = card[j][1];
		newCard[order[j] - 1][2] = card[j][2];

	}

	for (int i = 1; i < cnt; i++)
	{
		for (int j = 0; j < 54; j++) //进行顺序交换
		{
			card[j][0] = newCard[j][0];
			card[j][1] = newCard[j][1];
			card[j][2] = newCard[j][2];
		}
		for (int j = 0; j < 54; j++) //进行顺序交换
		{
			newCard[order[j] - 1][0] = card[j][0];
			newCard[order[j] - 1][1] = card[j][1];
			newCard[order[j] - 1][2] = card[j][2];
		}
	}
	for (int i = 0; i < 53; i++)
	{
		if (newCard[i][2] != ' ')
		{
			cout << newCard[i][0] << newCard[i][1] << newCard[i][2] << " ";
		}			
		else
		{
			cout << newCard[i][0] << newCard[i][1] << " ";
		}

		
	}
	if (newCard[53][2] != ' ')
	{
		cout << newCard[53][0] << newCard[53][1] << newCard[53][2];
	}
	else
	{
		cout << newCard[53][0] << newCard[53][1];
	}

	return 0;
}