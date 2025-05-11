#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Перевірка прав доступу до файлів у домашньому каталозі:\n");
    system("ls -l $HOME | head -n 10");

    printf("\nПеревірка прав доступу до файлів у каталозі /usr/bin:\n");
    system("ls -l /usr/bin | head -n 10");

    printf("\nПеревірка прав доступу до файлів у каталозі /etc:\n");
    system("ls -l /etc | head -n 10");

    const char *files[] = {"/etc/passwd", "/usr/bin/ls", "/etc/shadow"};
    for (int i = 0; i < 3; i++) {
        printf("\nПеревірка доступу до файлу: %s\n", files[i]);
        printf("Чи можна прочитати файл? %s\n", access(files[i], R_OK) == 0 ? "Так" : "Ні");
        printf("Чи можна записати у файл? %s\n", access(files[i], W_OK) == 0 ? "Так" : "Ні");
        printf("Чи можна виконати файл? %s\n", access(files[i], X_OK) == 0 ? "Так" : "Ні");
    }

    return 0;
}

