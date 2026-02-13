#include "Task.h"

int main() {
    Task task1(1, "Купить молоко", 2);
    task1.printTask();
    task1.markCompleted();
    task1.printTask();
    return 0;
}