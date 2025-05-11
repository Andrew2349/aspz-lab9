#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("tempfile.txt", "w");
    if (file == NULL) {
        perror("Не вдалося створити файл");
        return 1;
    }
    fprintf(file, "Це тимчасовий файл.\n");
    fclose(file);

    system("sudo chown root:root tempfile.txt");
    system("sudo chmod 600 tempfile.txt");

    printf("\nПеревірка прав доступу до файлу:\n");
    system("ls -l tempfile.txt");

    printf("\nСпроба змінити файл:\n");
    system("echo 'Новий рядок.' >> tempfile.txt");

    printf("\nСпроба видалити файл:\n");
    system("rm tempfile.txt");

    return 0;
}
