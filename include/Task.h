#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <iomanip>

class Task {
private:
    int id;
    std::string description;
    bool isCompleted;
    int priority; // 1 - высокий, 2 - средний, 3 - низкий

public:
    // Конструкторы
    Task();
    Task(int id, const std::string& description, int priority = 2);
    
    // Геттеры
    int getId() const;
    std::string getDescription() const;
    bool getIsCompleted() const;
    int getPriority() const;
    std::string getPriorityString() const;
    
    // Сеттеры
    void setId(int id);
    void setDescription(const std::string& description);
    void setIsCompleted(bool completed);
    void setPriority(int priority);
    
    // Основные методы
    void markCompleted();
    void updateDescription(const std::string& newDescription);
    void printTask() const;
    std::string toShortString() const;
    
    // Перегрузка операторов для сортировки
    bool operator<(const Task& other) const; // по приоритету
    bool operator>(const Task& other) const; // по приоритету
};

#endif