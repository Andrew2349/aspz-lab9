#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    FILE *fp = popen("getent passwd", "r");
    if (!fp) {
        perror("Не вдалося виконати getent passwd");
        return 1;
    }


    uid_t my_uid = getuid();
    struct passwd *me = getpwuid(my_uid);

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ":");
        strtok(NULL, ":");
        char *uid_str = strtok(NULL, ":");
        int uid = atoi(uid_str);

        if (uid >= 1000 && uid < 65534 && strcmp(username, me->pw_name) != 0) {
            printf("Звичайний користувач: %s, UID: %d\n", username, uid);
        }
    }

    pclose(fp);
    return 0;
}
