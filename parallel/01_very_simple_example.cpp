#include <iostream>
#include <thread>
#include <vector>

const int sufx = 1e9;

void act01(int count) {
    for (int i = 0; i < count; i++)
    std::cout << "action 01" << std::endl;
}
void act02(int count) {
    for (int i = 0; i < count; i++)
    std::cout << "action 02 __ " << std::endl;
}

int main() {

    std::thread t01(act01,1*sufx);
    std::thread t02(act02,2*sufx);

    t01.join();
    t02.join();



    return 0;
}