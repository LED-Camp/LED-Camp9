#include "Event.hpp"

#include "iostream"
#include "Controller.hpp"
#include "CommonDefine.hpp"
#include <fcntl.h>
#include <unistd.h>   //_getch; 実機
#include <termios.h>  //_getch; 実機

#define ABS_FLOAT(a) ((a) < 0.0F?(a)*-1.0F:(a))

using namespace webots;
/* int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, F_SETFL, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ch = ungetc(ch, stdin);
        return 1;
    }

    return 0;

}

char getch() {
    char buf = 0;
    struct termios old = { 0 };
    fflush (stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
} */

Event::Event(Controller *controller) {
    this->event = 0;
    this->controller = controller;
    this->keyboard = Keyboard();
    this->old_key = -1;
    keyboard.enable(100);
}

int Event::updateEvent() {
    int key = keyboard.getKey();
    printf("%d\n", key);
    if(key == 'Q'){
        return -1;
    }

    // E_UPイベント判定
    if (key == 'W') {
        this->event |= E_UP;
    } else {
        this->event &= ~E_UP;
    }

    // E_DOWNイベント判定
    if (key == 'S') {
        this->event |= E_DOWN;
    } else {
        this->event &= ~E_DOWN;
    }

    // E_LEFTイベント判定
    if (key == 'A') {
        this->event |= E_LEFT;
    } else {
        this->event &= ~E_LEFT;
    }

    // E_RIGHTイベント判定
    if (key == 'D') {
        this->event |= E_RIGHT;
    } else {
        this->event &= ~E_RIGHT;
    }
    key = -1;
    return 0;
}

unsigned long Event::getEvent() {
    return this->event;
}
