#include "header/userOperate.hpp"
#include "header/writeJson.hpp"
#include "header/screen.hpp"
#include "header/role.hpp"
#include "header/networking.hpp"
using namespace std;

int main() {
    int* keyValue = new int;
    usleep(100);
    thread keyboardEvent(listenKeyBoard, keyValue);
    while (true) {
        if (*keyValue != -1) {
            addch(char(*keyValue));
            usleep(80); //the computer is too fast to lead inputs have one or more char 
        }
    }
    keyboardEvent.join();
    return 0;
}