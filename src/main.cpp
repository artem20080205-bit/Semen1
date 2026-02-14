#include "TaskManager.h"
#include <iostream>
#include <thread>
#include <chrono>

void printHeader() {
    std::cout << "\n╔════════════════════════════════════════════╗\n";
    std::cout << "║     📋 TASK MANAGER SYSTEM 📋              ║\n";
    std::cout << "╚════════════════════════════════════════════╝\n";
}

void printSection(const std::string& title) {
    std::cout << "\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    std::cout << "┃  " << title << "\n";
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

int main() {
    printHeader();
    
    // Создаем менеджер задач
    TaskManager tm;
    
    // === ТЕСТ 1: Добавление задач ===
    printSection("ТЕСТ 1: Добавление задач");
    tm.addTask("Купить продукты", 2);        // Средний приоритет
    tm.addTask("Сдать отчет начальнику", 1);  // Высокий приоритет
    tm.addTask("Позвонить клиенту", 1);       // Высокий приоритет
    tm.addTask("Убраться в комнате", 3);      // Низкий приоритет
    tm.addTask("Прочитать книгу по C++", 2);  // Средний приоритет
    tm.addTask("Сходить в спортзал", 2);      // Средний приоритет
    tm.addTask("Подготовить презентацию", 1); // Высокий приоритет
    
    // === ТЕСТ 2: Просмотр всех задач ===
    printSection("ТЕСТ 2: Все задачи");
    tm.printAllTasks();
    tm.printStatistics();
    
    // === ТЕСТ 3: Отметка задач как выполненных ===
    printSection("ТЕСТ 3: Выполнение задач");
    tm.markTaskCompleted(2);  // Сдать отчет
    tm.markTaskCompleted(4);  // Убраться
    tm.markTaskCompleted(6);  // Сходить в спортзал
    tm.markTaskCompleted(7);  // Подготовить презентацию
    
    // === ТЕСТ 4: Просмотр выполненных задач ===
    printSection("ТЕСТ 4: Выполненные задачи");
    tm.printTasks(tm.getCompletedTasks(), "ВЫПОЛНЕННЫЕ ЗАДАЧИ");
    
    // === ТЕСТ 5: Просмотр задач в ожидании ===
    printSection("ТЕСТ 5: Задачи в ожидании");
    tm.printTasks(tm.getPendingTasks(), "ЗАДАЧИ В ОЖИДАНИИ");
    
    // === ТЕСТ 6: Обновление описания задачи ===
    printSection("ТЕСТ 6: Обновление описания");
    tm.updateTaskDescription(1, "Купить продукты на неделю в магазине");
    
    // === ТЕСТ 7: Сортировка по приоритету ===
    printSection("ТЕСТ 7: Сортировка по приоритету");
    tm.sortByPriority();
    tm.printAllTasks();
    
    // === ТЕСТ 8: Фильтрация по приоритету ===
    printSection("ТЕСТ 8: Высокий приоритет");
    tm.printTasks(tm.getTasksByPriority(1), "ВЫСОКИЙ ПРИОРИТЕТ");
    
    // === ТЕСТ 9: Удаление задачи ===
    printSection("ТЕСТ 9: Удаление задачи");
    tm.removeTask(5);  // Удаляем "Прочитать книгу по C++"
    
    // === ТЕСТ 10: Поиск задачи ===
    printSection("ТЕСТ 10: Поиск задачи по ID");
    Task* task = tm.findTaskById(3);
    if (task) {
        std::cout << "  Найдена задача: " << task->toShortString() << "\n";
    }
    
    // === ТЕСТ 11: Очистка выполненных ===
    printSection("ТЕСТ 11: Очистка выполненных");
    tm.clearCompleted();
    
    // === ТЕСТ 12: Итоговое состояние ===
    printSection("ТЕСТ 12: Итоговое состояние");
    tm.sortById();
    tm.printAllTasks();
    tm.printStatistics();
    
    std::cout << "\n╔════════════════════════════════════════════╗\n";
    std::cout << "║     ✅ ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ✅           ║\n";
    std::cout << "╚════════════════════════════════════════════╝\n\n";
    
    return 0;
}