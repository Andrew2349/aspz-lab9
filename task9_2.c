#include <stdio.h>
#include <stdlib.h>

int main() {

    int status = system("sudo cat /etc/shadow");

    if (status == -1) {
        perror("Помилка при виконанні команди");
        return 1;
    }

    return 0;
}

