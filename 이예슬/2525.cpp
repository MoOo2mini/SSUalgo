#include <iostream>

using namespace std;

int main(void)
{
	int start_hour;
	int start_min;
	int time;
	int end_hour, end_min;

	cin >> start_hour;
	cin >> start_min;
	cin >> time;
	end_hour = start_hour + time / 60;
	end_min = start_min + time % 60;

	if (end_min >= 60)
	{
		end_min -= 60;
		end_hour++;
	}
	if (end_hour >= 24)
		end_hour -= 24;

	cout << end_hour << " " << end_min;
	return (0);
}