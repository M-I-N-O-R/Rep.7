#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	double grade;
};

void addStudent(Student *students, int& count, const string& name, double grade){ 
	Student* newStudents = new Student[count + 1];
	
	for (int i = 0; i < count; i++) {
		newStudents[i] = students[i];
	}
	newStudents[count] = { name, grade };
	
	delete[] students;
	students = newStudents;
	count++;
}

void delStudent(Student*& students, int& count, const string& name) {
	int index = -1;
	for (int i = 0; i < count; i++) {
		if (students[i].name == name) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Студента із таким іменем" << name << "не знайдено. \n";
		return;
	}

	Student* newStudents = new Student[count - 1];
	for (int i = 0, j = 0; i < count; i++) {
		if (i != index) {
			newStudents[j++] = students[i];
		}
	}
	delete[] students;
	students = newStudents;
	count--;
	cout << "Студентa " << name << " видалено.\n";
}

double calculateAverageGrade(const Student* students, int count) {
	if (count == 0) return 0.0;
	double sum = 0.0;
	for (int i = 0; i < count; i++) {
		sum += students[i].grade;  
	}
	return sum / count;
}

void showStudents(const Student* students, int count) {
	if (count == 0) {
		cout << "Список студентiв порожнiй.\n";
		return;
	}
	cout << "Список студентiв:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].name << ": " << students[i].grade << endl;
	}
}

int main() {
	setlocale(0, ".1251");
	Student* students = nullptr;
	int count = 0;
	int choice;
	string name;
	double grade;

	do {
		cout << "1. Додати студента" << endl;
		cout << "2. Видалити студента" << endl;
		cout << "3. Список студентiв" << endl;
		cout << "4. Середнiй бал" << endl;
		cout << "5. Вихiд" << endl;
		cout << "------------------------" << endl;
		cout << "Виберіть пункт: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Введiть iм'я студента: ";
			cin >> name;
			cout << "Введiть оцiнку: ";
			cin >> grade;
			addStudent(students, count, name, grade);
			break;
		case 2:
			cout << "Введiть iм'я студента для видалення: ";
			cin >> name;
			delStudent(students, count, name);
			break;
		case 3:
			showStudents(students, count);
			break;

		case 4:
			showStudents(students, count);
			break;
			case 3:
			cout << "Середнiй бал: " << calculateAverageGrade(students, count) << endl;
			break;

		case 5:
			cout << "Вихiд з програми.\n";
			break;
		default:
			cout << "Ви вийшли з програми\n";
		}
	
	} while (choice != 0);

	delete[] students;
	return 0;

}
