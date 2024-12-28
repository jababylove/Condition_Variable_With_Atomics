#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <condition_variable>

using namespace std;

vector<int>         mySharedWork;
mutex               mtx;
condition_variable  condVar;
atomic<bool>        dataReady{false};

void waitingForWork()
{
    cout << "Waiting... " << endl;

    while(!dataReady.load())
    {
        this_thread::sleep_for(chrono::milliseconds(5));
    }

    mySharedWork[1] = 2;
    cout << "Work done..." << endl;
}

void setDataReady()
{
    mySharedWork = {1, 0, 3};
    dataReady = true;
    cout << "\nData prepared...\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "\nExit thread 1 after 5 sec pause.\n" << endl;
}

int main()
{
    cout << "\nLet's go condition variables..! \n" << endl;

    thread t1(waitingForWork);
    thread t2(setDataReady);

    t1.join();
    t2.join();

    for(auto v: mySharedWork)
    {
        cout << v << " ";
    }

    cout << "\n\n";

    return 0;
}
