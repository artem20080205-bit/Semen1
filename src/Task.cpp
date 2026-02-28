#include "Task.h"

// Конструктор по умолчанию
Task::Task() : id(0), description("Empty task"), isCompleted(false), priority(2) {}

// Конструктор с параметрами
Task::Task(int id, const std::string& description, int priority) 
    : id(id), description(description), isCompleted(false), priority(priority) {}

// Геттеры
int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
bool Task::getIsCompleted() const { return isCompleted; }
int Task::getPriority() const { return priority; }

std::string Task::getPriorityString() const {
    switch(priority) {
        case 1: return "Высокий";
        case 2: return "Средний";
        case 3: return "Низкий";
        default: return "Неизвестно";
    }
}

// Сеттеры
void Task::setId(int id) { this->id = id; }
void Task::setDescription(const std::string& description) { this->description = description; }
void Task::setIsCompleted(bool completed) { isCompleted = completed; }
void Task::setPriority(int priority) { this->priority = priority; }

// Основные методы
void Task::markCompleted() {
    isCompleted = true;
    std::cout << "  ✓ Задача #" << id << " отмечена как выполненная!\n";
}

void Task::updateDescription(const std::string& newDescription) {
    description = newDescription;
    std::cout << "  ✎ Задача #" << id << " обновлена.\n";
}

void Task::printTask() const {
    std::cout << "  ┌─────────────────────────────────\n";
    std::cout << "  │ Задача #" << std::setw(2) << std::setfill('0') << id << "\n";
    std::cout << "  │ Описание: " << description << "\n";
    std::cout << "  │ Приоритет: " << getPriorityString() << "\n";
    std::cout << "  │ Статус: " << (isCompleted ? "✓ ВЫПОЛНЕНО" : "○ В ОЖИДАНИИ") << "\n";
    std::cout << "  └─────────────────────────────────\n";
}

std::string Task::toShortString() const {
    return "[" + std::to_string(id) + "] " + description + 
           " (" + getPriorityString() + ") - " + 
           (isCompleted ? "✓" : "○");
}

bool Task::operator<(const Task& other) const {
    return priority < other.priority; // Меньше число = выше приоритет
}

bool Task::operator>(const Task& other) const {
    return priority > other.priority;
}