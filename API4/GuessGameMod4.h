#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class GuessGameMod4
{
private:
	int minValueRange;
	int maxValueRange;
	int maxAttempts;
	int randomNumber;
	vector<int> guesses;

public:
	GuessGameMod4() {}

	void InitializeGame() {
		srand(time(0));

		cout << "Ingrese el rango de numeros (limite inferior y superior): ";
		cin >> minValueRange >> maxValueRange;
		cout << "Ingrese la cantidad de intentos maximos: ";
		cin >> maxAttempts;

		if (minValueRange >= maxValueRange || maxAttempts <= 0) {
			cout << "Error: Rango invalido o cantidad de intentos invalida." << endl;
			exit(1);
		}

		randomNumber = rand() % (maxValueRange - minValueRange + 1) + minValueRange;
	}

	void PlayGame() {
		for (int i = 1; i <= maxAttempts; i++) {
			int guess = GetGuess();
			int attemptsLeft = i;
			guesses.push_back(guess);
			sort(guesses.begin(), guesses.end());

			if (guess == randomNumber) {
				cout << "Felicidades! Has adivinado el numero en " << i << " intentos." << endl;
				DisplayProgress(i);
				return;
			}
			else if (guess < randomNumber) {
				cout << "El numero es mayor." << endl;
			}
			else {
				cout << "El numero es menor." << endl;
			}
		}
		DisplayProgress(maxAttempts);
		cout << "Lo siento, has agotado tus intentos. El numero era: " << randomNumber << endl;
	}

private:

	int GetGuess() {
		int guess;

		while (true) {
			cout << "Intento " << guesses.size() + 1 << "/" << maxAttempts << ". Ingrese un numero: ";
			cin >> guess;

			if (guess < minValueRange || guess > maxValueRange) {
				cout << "El numero ingresado esta fuera de rango." << endl;
			}
			else if (find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
				cout << "El numero ya fue ingresado anteriormente." << endl;
			}
			else {
				return guess;
			}
		}
	}

	void DisplayProgress(int attempt) {
		cout << "Intentos realizados: " << attempt << "/" << maxAttempts << endl;
		cout << "Intentos restantes: " << maxAttempts - attempt << endl;

		cout << "Numeros ingresados ordenados: ";

		for (int num : guesses) {
			cout << num << " ";
		}
		cout << endl;
	}
};

