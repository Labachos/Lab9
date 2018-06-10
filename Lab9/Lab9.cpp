#include <iostream>
#include <locale.h>
#include <future>
#include <ctime>

using namespace std;

int timer(int ms) {
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC;
	while (clock() < end_time) {}
	return 1;
}

int second(int time) {
	cout << "���������: ������ �����!" << endl;
	timer(time);
	cout << "���������: �����!" << endl;
	return 1;
}

int shooter1() {
	cout << "������� 1: ������ �����!" << endl;
	cout << "������� 1: �����!" << endl;
	return 0;
}

int shooter2() {
	cout << "������� 2: ������ �����!" << endl;
	cout << "������� 2: �����!" << endl;
	return 0;
}

int main() {
	setlocale(LC_ALL, "russian");
	int t = 0;
	cout << "������� ����� ��� �������: ";
	cin >> t;
	for (int i = 0; i < 100; ++i) {
		future <int> sec = async(launch::async, second, t);
		int x = sec.get();
		future <int> shot = async(launch::async, shooter1);
		future <int> shot1 = async(launch::async, shooter2);
		cout << endl;
	}
	return 0;
}