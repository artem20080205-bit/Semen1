#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string description;
    bool isCompleted;
    int priority;

public:
    // Конструкторы
    Task();
    Task(int id, const std::string& description, int priority);
    
    // Геттеры
    int getId() const;
    std::string getDescription() const;
    bool getIsCompleted() const;
    int getPriority() const;
    
    // Сеттеры (осторожно — не все поля должны изменяться после создания)
    void setDescription(const std::string& newDescription);
    void setPriority(int newPriority);
    
    // Бизнес-логика
    void markCompleted();
    void printTask() const;
};

#endif