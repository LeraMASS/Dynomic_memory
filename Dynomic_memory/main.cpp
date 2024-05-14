#include <iostream>;
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
//Заполнение массива
template <typename T>
void fill_arr(T arr[], int const length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
//Передача массива в массив
template <typename T>
void arr_app(T*& arr, int& length, int num) { // обязательно полсе * ставится &, иначе мусорное значение.
	//Проверка на кол-во элементов для увеличения размера массива:
	if (num <= 0)
		return;

	//создание нового дин. массива нужного размера:
	T* tmp = new T[length + num]{}; //{} Заполнит num 0, вместо мусорного значения

	//Копирование значений старого массива в элементы нового массива:
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	// Удаление старого массива:
	delete[] arr;

	//Перенаправление указателя на новый массив:
	arr = tmp;

	//Увеличение переменной отвечающей за размер массива
	length += num;
}

template <typename T>
void arr_pop(T*& arr, int& length, int num) {
	if (length <= 0)
		return;

	if (num >= length) {
		delete[] arr;
		arr = nullptr;
		return;
	}
	T* tmp = new T[length - num];
	for (int i = 0; i < length - num; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	length -= num;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Выделение динамической памяти под переменные. (обычно так не делается)
	int* pointer = new int; //создание участка динамической памяти new затем пишется тип int, и сохранение ее адреса в указателе.

	*pointer = 7;// запись в выделенную ранее динамическую память числа 7.
	std::cout << "pointer = " << pointer << std::endl;// показан адрес.
	std::cout << "pointer = " << *pointer << std::endl;// выводит число 7.


	//происходит утечка памяти. 
	delete pointer; // операция освобождение памяти, на которую направлен указатель.

	pointer = new int;//выделяет новый участок памяти. Перенаправление указателя на новую область дин. памяти.
	*pointer = 15;
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "pointer = " << *pointer << std::endl;

	// Динамические массивы.
	std::cout << "Введите размер массива -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];

	std::cout << "Ввод данных в массив:\n";
	for (int i = 0; i < dsize; i++) {
		std::cout << i + 1 << "-е число -> ";
		std::cin >> darr[i];
	}
	std::cout << "Итоговый массив:\n";
	print_arr(darr, dsize);

	delete[] darr; // что удалить массив полностью ставятся [].

	//Двумерный динамический массив
	int rows = 5, cols = 6;
	//int* mx = new int[rows][cols]; не работает
	//Трехмерный массив
	int w = 4, l = 10, h = 8;
	int*** cude = new int** [w];
	for (int i = 0; i < w; i++) {
		cube[i] = new int* [l];
		for (int j = 0; j < l; j++)
			cube[i][j] = new int[h];
	}

	// Выделение памяти
//Указатель на указатель **.
	int** mx = new int* [rows];// Записываем Указатель в указатель.
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];

	//Освобождение памяти.
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;

	//Задача 1. Увеличение размера массива
	std::cout << "Задача 1\n Введите размер массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);

	std::cout << "Введите кол-во элементов для добовления -> ";
	std::cin >> n;

	arr_app(arr1, size1, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr1, size1);

	//Задача 2. Уменьшение размера массива
	std::cout << "Задача 2\n Введите размер массива -> ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr2, size2);


	std::cout << "Введите кол-во элементов для удаления -> ";
	std::cin >> n;

	arr_pop(arr2, size2, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr2, size2);

	return 0;
}