#include "Task.h"
#include <iostream>

Task::Task() : id(0), description(""), isCompleted(false), priority(0) {}

Task::Task(int id, const std::string& description, int priority)
    : id(id), description(description), isCompleted(false), priority(priority) {}

int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
bool Task::getIsCompleted() const { return isCompleted; }
int Task::getPriority() const { return priority; }

void Task::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Task::setPriority(int newPriority) {
    priority = newPriority;
}

void Task::markCompleted() {
    isCompleted = true;
}

void Task::printTask() const {
    std::cout << "ID: " << id 
              << " | Описание: " << description 
              << " | Приоритет: " << priority 
              << " | Статус: " << (isCompleted ? "✅ Выполнено" : "⏳ В работе") 
              << std::endl;
}