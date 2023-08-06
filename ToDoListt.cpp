#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Класс Task - этот класс представляект задачу, которая имеет заголовок, описание и статус завершенности
class Task {
private:
    string title; // Заголовок задачи
    string description; // Описание задачи
    bool completed; // Статус завершенности задачи

public:
    Task(const string& title, const string& description) { // Конструктор, создает объект задачи с указанными заголовоками и описанием
        this->title = title;
        this->description = description;
        completed = false;
    }

    string getTitle() const { // Возвращает описание задачи
        return title;
    }

    string getDescription() const { // Возврашает описание задачи
        return description;
    }

    bool isCompleted() const { // Возвращает 'true' , если задача завершена, иначе 'false'
        return completed;
    }

    void markAsCompleted() { // Отмечает задачу как завершенную, устаналивая стаут завершенности "true"
        completed = true;
    }
};

class TaskList { // Этот класс представляет список задач, который иммеет имя и вектор задач
private:
    string name; // Имя списка задач
    vector<Task> tasks; // Вектор объектов задач, принадлжещази данном списку

public:
    TaskList(const string& name) { // Конструктор, создает объект списка задач с указанным именем
        this->name = name;
    }

    string getName() const { // Возвращает имя списка задач
        return name;
    }

    vector<Task>& getTasks() { // Вовзрщает ссылку на вектор задач в данном списке
        return tasks;
    }

    void addTask(const Task& task) { // Добавляет задачу в вектор задач списка
        tasks.push_back(task);
    }

    void displayTasks() const { // Выводит информацию о задачах в списке.
        cout << "Задачи в " << name << " списке:" << endl;
        for (const Task& task : tasks) {
            cout << "- " << task.getTitle();
            if (task.isCompleted()) {
                cout << " (Завершено)";
            }
            cout << endl;
        }
    }
};

class TaskManager { // Описывает класс управление задач и их задачами.
private:
    vector<TaskList> lists; 

public:
    void createTaskList(const string& name) { // Создает новый список задач с указанным именем и добавляет его в вектор списков.
        lists.push_back(TaskList(name));
    }

    void addTaskToList(const string& listName, const Task& task) { // Добавляет задачу в указанный список задач
        for (TaskList& taskList : lists) {
            if (taskList.getName() == listName) {
                taskList.addTask(task);
                return;
            }
        }
        cout << "Список не найден!" << endl;
    }

    void displayLists() const { // Выводит информацию о всех созданных списках задач
        cout << "Списки задач:" << endl;
        for (const TaskList& taskList : lists) {
            cout << "- " << taskList.getName() << endl;
        }
    }

    void displayTasksInList(const string& listName) const { // Выводит информацию о всех созданных списках задач
        for (const TaskList& taskList : lists) {
            if (taskList.getName() == listName) {
                taskList.displayTasks();
                return;
            }
        }
        cout << "Список не найден!" << endl;
    }

    void markTaskAsCompleted(const string& listName, const string& taskTitle) { // Отмечает задачу в указанном списке задач как завершенную
        for (TaskList& taskList : lists) {
            if (taskList.getName() == listName) {
                for (Task& task : taskList.getTasks()) {
                    if (task.getTitle() == taskTitle) {
                        task.markAsCompleted();
                        cout << "Задача отмечена как завершенная: " << task.getTitle() << endl;
                        return;
                    }
                }
                cout << "Задача не найдена!" << endl;
                return;
            }
        }
        cout << "Список не найден!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    TaskManager taskManager;

    taskManager.createTaskList("Персональный");
    taskManager.createTaskList("Работа");

    Task task1("Купить продукты", "Молоко, хлеб, яйца");
    Task task2("Готовый отчет", "К пятнице");

    taskManager.addTaskToList("Персональный", task1);
    taskManager.addTaskToList("Работа", task2);

    taskManager.displayLists();
    taskManager.displayTasksInList("Персональный");

    taskManager.markTaskAsCompleted("Персональный", "Купить продукты");

    taskManager.displayTasksInList("Персональный");

    return 0;
}
