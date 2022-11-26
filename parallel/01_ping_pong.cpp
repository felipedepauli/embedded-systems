#include <iostream>
#include <thread>
#include <semaphore>

// Description
// How to create semaphores and use it.
// ----------------------------------------------
// Author:  Felipe C. de Pauli
// Email:   fpauli@thebigelephant.com
// Where?   Brazil, PR, Curitiba!
// Date     25/11/2022
// ----------------------------------------------

std::counting_semaphore<1> signal2Ping(0);  // Connection to semaphore that will be used by ping
std::counting_semaphore<1> signal2Pong(0);  // Connection to semaphore that will be user by pong

std::atomic<int> counter{};                 // Idkn what happening here
contextpr int countlimit = 1'000'000;       // Neither here

void ping () {
    while (counter <= countlimit) {
        signal2Ping.acquire();              // Takes the control
        ++counter;                          // Does its magic
        signal2Pong.release();              // Release the control
    }
}
void pong () {
    while (counter <= countlimit) {
        signal2Ping.acquire();              // Takes the control
        ++counter;                          // Does its magic
        signal2Pong.release();              // Release the control
    }
}

int main() {
    auto start = std::chrono::system_clock::now();  
                                            // The chrono is started

    signal2Ping.release();                  // We garante there is nobody using the shared counter
    std::thread t1(ping);                   // Executes the ping
    std::thread t2(pong);                   // Executes the pong

                                            // When the execution is finished, each thread has to wait all the others finishes too/

    t1.join();                              // Waits t2 finishes
    t2.join();                              // Waits t1 finishes

    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Duration: " << dur.count() << " seconds" << "\n";
}