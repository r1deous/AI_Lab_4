#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int number = 10; //кол - во чисел
const int column = 9; //кол - во столбцов

int main_selection[number][column + 1] = {
		{0, 0,2,3,4,5,6,7,8,9},
		{1, 2,3,0,5,6,7,8,9,10},
		{2, 3,4,5,6,7,8,9,10,11},
		{3, 4,5,6,7,8,9,10,11,12},
		{4, 5,6,7,0,9,10,11,12,13},
		{5, 6,7,8,9,17,1,6,13,14},
		{6, 7,8,9,10,11,12,13,1,15},
		{7, 8,9,10,11,9,13,14,15,1},
		{8, 9,35,11,12,13,14,55,1,2},
		{9, 10,11,12,-5,14,15,1,2,3},
};


//Цифры в двоичном предствалении
const int number_err_0[number][column + 1] = {
	{0,1,1,0,1,0,1,0,1,1},
	{1,0,0,1,1,0,0,0,1,0},
	{2,0,1,0,1,0,0,1,0,1},
	{3,0,1,1,0,1,0,1,0,0},
	{4,1,0,0,1,1,0,0,1,0},
	{5,1,1,0,0,1,0,0,1,1},
	{6,0,0,1,0,1,1,0,1,1},
	{7,0,1,1,0,0,1,0,0,0},
	{8,1,1,0,1,1,1,0,1,1},
	{9,1,1,0,1,1,0,1,0,0},
}; 
const int number_err_1[number][column + 1] = {
	{0,1,0,0,1,0,1,0,1,1},
	{1,0,0,0,1,0,0,0,1,0},
	{2,1,1,0,1,0,0,1,0,1},
	{3,0,1,0,0,1,0,1,0,0},
	{4,1,0,0,1,1,0,0,1,1},
	{5,1,0,0,0,1,0,0,1,1},
	{6,0,0,1,0,1,0,0,1,1},
	{7,0,1,1,1,0,1,0,0,0},
	{8,1,1,0,1,1,1,0,0,1},
	{9,1,1,0,1,0,0,1,0,0},
};
const int number_err_2[number][column + 1] = {
	{0,1,0,0,0,0,1,0,1,1},
	{1,1,0,0,1,0,0,0,1,0},
	{2,1,1,0,1,0,0,1,0,0},
	{3,0,1,0,0,1,0,1,1,0},
	{4,1,1,0,1,1,0,0,1,1},
	{5,1,0,0,1,1,0,0,1,1},
	{6,1,0,1,0,1,0,0,1,1},
	{7,0,1,1,1,0,1,1,0,0},
	{8,1,0,0,1,1,1,0,0,1},
	{9,1,1,0,1,0,0,1,1,0},
};
const int number_err_3[number][column + 1] = {
	{0,1,0,0,0,0,1,0,1,0},
	{1,1,0,0,1,0,0,1,1,0},
	{2,1,1,0,1,0,1,1,0,0},
	{3,1,1,0,0,1,0,1,1,0},
	{4,1,1,0,1,0,0,0,1,1},
	{5,1,0,0,1,1,0,0,1,0},
	{6,1,0,1,0,1,0,0,1,1},
	{7,1,1,1,1,0,1,1,0,0},
	{8,1,0,0,1,0,1,0,0,1},
	{9,0,1,0,1,0,0,1,1,0},
};
const int number_err_4[number][column + 1] = {
	{0,1,0,0,0,0,1,1,1,0},
	{1,1,0,0,1,1,0,1,1,0},
	{2,1,1,0,0,0,1,1,0,0},
	{3,1,1,0,0,1,1,1,1,0},
	{4,1,1,0,1,0,0,1,1,1},
	{5,1,0,0,1,1,0,1,1,0},
	{6,1,0,0,0,1,0,0,1,1},
	{7,1,0,1,1,0,1,1,0,0},
	{8,1,0,0,0,0,1,0,0,1},
	{9,0,1,1,1,0,0,1,1,0},
};
const int number_err_5[number][column + 1] = {
	{0,1,0,1,0,0,1,1,1,0},
	{1,1,0,0,0,1,0,1,1,0},
	{2,1,1,0,0,0,1,1,1,0},
	{3,1,0,0,0,1,1,1,1,0},
	{4,1,1,0,1,0,1,1,1,1},
	{5,1,0,0,1,0,0,1,1,0},
	{6,1,0,0,1,0,0,0,1,1},
	{7,1,0,1,1,0,1,1,0,1},
	{8,1,0,0,0,0,0,0,0,1},
	{9,0,1,1,0,0,0,1,1,0},
};
const int number_err_6[number][column + 1] = {
	{0,1,0,1,0,0,0,1,1,0},
	{1,1,1,0,0,1,0,1,1,0},
	{2,1,1,0,0,1,1,1,1,0},
	{3,1,0,0,0,1,1,0,1,0},
	{4,0,1,0,1,0,1,1,1,1},
	{5,1,0,0,1,0,0,1,0,0},
	{6,1,0,0,1,0,0,0,1,0},
	{7,1,0,1,1,1,1,1,0,1},
	{8,1,0,1,0,0,0,0,0,1},
	{9,0,1,1,0,0,0,0,1,0},
};
const int number_err_7[number][column + 1] = {
	{0,0,0,1,0,0,0,1,1,0},
	{1,1,1,0,0,1,0,1,1,1},
	{2,1,1,1,0,1,1,1,1,0},
	{3,1,0,0,0,0,1,0,1,0},
	{4,0,1,0,1,0,1,1,0,1},
	{5,1,0,1,1,0,0,1,0,0},
	{6,1,0,0,1,0,0,1,1,0},
	{7,1,0,1,1,1,0,1,0,1},
	{8,1,0,1,0,0,0,1,0,1},
	{9,0,1,1,0,0,1,0,1,0},
};
const int number_err_8[number][column + 1] = {
	{0,0,0,1,0,1,0,1,1,0},
	{1,1,1,0,0,1,0,1,0,1},
	{2,1,1,1,0,1,1,0,1,0},
	{3,1,0,0,1,0,1,0,1,0},
	{4,0,1,1,1,0,1,1,0,1},
	{5,1,0,1,1,0,1,1,0,0},
	{6,1,1,0,1,0,0,1,1,0},
	{7,1,0,0,1,1,0,1,0,1},
	{8,0,0,1,0,0,0,1,0,1},
	{9,0,1,1,0,0,1,0,1,1},
};
const int number_err_9[number][column + 1] = {
	{0,0,0,1,0,1,0,1,0,0},
	{1,1,1,0,0,1,1,1,0,1},
	{2,1,0,1,0,1,1,0,1,0},
	{3,1,0,0,1,0,1,0,1,1},
	{4,0,1,1,0,0,1,1,0,1},
	{5,0,0,1,1,0,1,1,0,0},
	{6,1,1,0,1,0,0,1,0,0},
	{7,1,0,0,1,1,0,1,1,1},
	{8,0,0,1,0,0,0,1,0,0},
	{9,0,0,1,0,0,1,0,1,1},
};


int MAIN_FUNC(int counter_check[], const int num[][column + 1], int main_selection[][column+1]);

int main() {
	//Код написал: Иванов Данила

	setlocale(LC_ALL, "Russian");

	cout << "Начальная матрица весов" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}cout << endl;

	int counter_check[1] = { 0 };

	cout << "0 помех" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_0, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "1 помеха" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_1, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "2 помехи" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_2, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "3 помехи" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_3, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "4 помехи" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_4, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "5 помех" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_5, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "6 помех" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_6, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "7 помех" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_7, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "8 помех" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_8, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	cout << endl; counter_check[0] = { 0 };

	cout << "9 помех" << endl;
	while (counter_check[0] < 10) { MAIN_FUNC(counter_check, number_err_9, main_selection); }
	cout << endl;
	cout << "Персептрон обучился" << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}
	counter_check[0] = { 0 };
}

int MAIN_FUNC(int counter_check[], const int num[][column+1], int m_selection[][column + 1]) {

	for (int point = 0; point < number; point++) {
	start:
		bool flag = false;

		vector <int> weights = {}; //вектор полученных весов
		vector <int> number_weight = {}; //номер числа полученного веса

		for (int i = 0; i < number; i++) {
			int temp = 0;
			for (int j = 1; j < column + 1; j++) {
				temp += m_selection[i][j] * num[point][j];
			}
			weights.push_back(temp);
		}

		int temp_max = *max_element(weights.begin(), weights.end());
		for (int i = 0; i < weights.size(); i++) {
			if (weights[i] >= temp_max) { number_weight.push_back(i); } //если пришли одиновые макс числа, то записываем их номер тоже
		}

		if (num[point][0] == number_weight[0] and number_weight.size() == 1) { flag = true; } //веса побранны
		else {
			for (int iter = 0; iter < number_weight.size(); iter++) {
				int temp = number_weight[iter];
				for (int i = 1; i < column + 1; i++) {
					if (num[point][i] == 1) {
						m_selection[temp][i]--;
					}
				}
			}
			int temp = num[point][0];
			for (int i = 1; i < column + 1; i++) {
				if (num[point][i] == 1) {
					m_selection[temp][i]++;
				}
			}
		}
		if (flag != true) { counter_check[0] = 0; goto start; }
		return counter_check[0] += 1;
	}
}