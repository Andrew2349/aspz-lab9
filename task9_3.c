#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("testfile.txt", "w");
    if (file == NULL) {
        perror("Не вдалося створити файл");
        return 1;
    }
    fprintf(file, "Це тестовий файл.\n");
    fclose(file);

    system("sudo cp testfile.txt /home/testuser/testfile_copy.txt");

    printf("Спроба змінити файл...\n");
    system("echo 'Додано новий рядок.' >> /home/testuser/testfile_copy.txt");

    printf("Спроба видалити файл...\n");
    system("rm /home/testuser/testfile_copy.txt");

    return 0;
}

