#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <algorithm>
#include <functional>

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    // Конструктор
    TaskManager();
    
    // Добавление/удаление
    void addTask(const std::string& description, int priority = 2);
    bool removeTask(int id);
    bool markTaskCompleted(int id);
    bool updateTaskDescription(int id, const std::string& newDescription);
    
    // Поиск
    Task* findTaskById(int id);
    const Task* findTaskById(int id) const;
    
    // Получение списков
    std::vector<Task> getAllTasks() const;
    std::vector<Task> getCompletedTasks() const;
    std::vector<Task> getPendingTasks() const;
    std::vector<Task> getTasksByPriority(int priority) const;
    std::vector<Task> getTasksByStatus(bool completed) const;
    
    // Сортировка
    void sortByPriority();
    void sortById();
    void sortByStatus();
    
    // Статистика
    int getTotalTasks() const;
    int getCompletedCount() const;
    int getPendingCount() const;
    int getHighPriorityCount() const;
    void printStatistics() const;
    
    // Вывод
    void printAllTasks() const;
    void printTasks(const std::vector<Task>& tasksToPrint, const std::string& title) const;
    
    // Очистка
    void clearCompleted();
};

#endif