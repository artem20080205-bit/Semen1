#include "TaskManager.h"
#include <iostream>
#include <iomanip>

// Конструктор
TaskManager::TaskManager() : nextId(1) {}

// Добавление задачи
void TaskManager::addTask(const std::string& description, int priority) {
    Task newTask(nextId++, description, priority);
    tasks.push_back(newTask);
    std::cout << "  ➕ Задача добавлена! ID: " << (nextId - 1) << "\n";
}

// Удаление задачи
bool TaskManager::removeTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            std::cout << "  🗑 Задача #" << id << " удалена.\n";
            return true;
        }
    }
    std::cout << "  ❌ Задача #" << id << " не найдена.\n";
    return false;
}

// Отметить как выполненную
bool TaskManager::markTaskCompleted(int id) {
    Task* task = findTaskById(id);
    if (task) {
        task->markCompleted();
        return true;
    }
    std::cout << "  ❌ Задача #" << id << " не найдена.\n";
    return false;
}

// Обновить описание
bool TaskManager::updateTaskDescription(int id, const std::string& newDescription) {
    Task* task = findTaskById(id);
    if (task) {
        task->updateDescription(newDescription);
        return true;
    }
    std::cout << "  ❌ Задача #" << id << " не найдена.\n";
    return false;
}

// Поиск задачи по ID
Task* TaskManager::findTaskById(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }
    return nullptr;
}

const Task* TaskManager::findTaskById(int id) const {
    for (const auto& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }
    return nullptr;
}

// Получить все задачи
std::vector<Task> TaskManager::getAllTasks() const {
    return tasks;
}

// Получить выполненные задачи
std::vector<Task> TaskManager::getCompletedTasks() const {
    return getTasksByStatus(true);
}

// Получить задачи в ожидании
std::vector<Task> TaskManager::getPendingTasks() const {
    return getTasksByStatus(false);
}

// Получить задачи по статусу
std::vector<Task> TaskManager::getTasksByStatus(bool completed) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.getIsCompleted() == completed) {
            result.push_back(task);
        }
    }
    return result;
}

// Получить задачи по приоритету
std::vector<Task> TaskManager::getTasksByPriority(int priority) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (task.getPriority() == priority) {
            result.push_back(task);
        }
    }
    return result;
}

// Сортировка по приоритету
void TaskManager::sortByPriority() {
    std::sort(tasks.begin(), tasks.end());
    std::cout << "  📊 Задачи отсортированы по приоритету.\n";
}

// Сортировка по ID
void TaskManager::sortById() {
    std::sort(tasks.begin(), tasks.end(), 
        [](const Task& a, const Task& b) { return a.getId() < b.getId(); });
}

// Сортировка по статусу (сначала невыполненные)
void TaskManager::sortByStatus() {
    std::sort(tasks.begin(), tasks.end(), 
        [](const Task& a, const Task& b) { 
            return a.getIsCompleted() < b.getIsCompleted(); 
        });
}

// Статистика
int TaskManager::getTotalTasks() const { return tasks.size(); }
int TaskManager::getCompletedCount() const { return getCompletedTasks().size(); }
int TaskManager::getPendingCount() const { return getPendingTasks().size(); }

int TaskManager::getHighPriorityCount() const {
    return getTasksByPriority(1).size();
}

void TaskManager::printStatistics() const {
    std::cout << "\n  📊 СТАТИСТИКА:\n";
    std::cout << "  ┌─────────────────────────────────\n";
    std::cout << "  │ Всего задач: " << std::setw(3) << getTotalTasks() << "\n";
    std::cout << "  │ ✅ Выполнено: " << std::setw(3) << getCompletedCount() << "\n";
    std::cout << "  │ ○ В ожидании: " << std::setw(3) << getPendingCount() << "\n";
    std::cout << "  │ 🔥 Высокий приоритет: " << std::setw(3) << getHighPriorityCount() << "\n";
    std::cout << "  └─────────────────────────────────\n";
}

// Печать всех задач
void TaskManager::printAllTasks() const {
    printTasks(tasks, "ВСЕ ЗАДАЧИ");
}

// Печать произвольного списка задач
void TaskManager::printTasks(const std::vector<Task>& tasksToPrint, const std::string& title) const {
    std::cout << "\n  ═══════════════════════════════════════\n";
    std::cout << "     " << title << "\n";
    std::cout << "  ═══════════════════════════════════════\n";
    
    if (tasksToPrint.empty()) {
        std::cout << "     📭 Нет задач для отображения\n";
    } else {
        for (const auto& task : tasksToPrint) {
            task.printTask();
        }
    }
    std::cout << "  ═══════════════════════════════════════\n";
}

// Очистить выполненные
void TaskManager::clearCompleted() {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
        [](const Task& t) { return t.getIsCompleted(); });
    tasks.erase(it, tasks.end());
    std::cout << "  🧹 Выполненные задачи удалены.\n";
}