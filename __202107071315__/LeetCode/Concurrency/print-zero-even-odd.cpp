#include <iostream>
#include <thread>
#include <functional>
#include <condition_variable>
#include <mutex>

using namespace std;

void printNumber(int num) {
    cout << num << endl;
}

class ZeroEvenOdd {
    private:
        int n;
        int count;
        int flag;
        mutex mtx;
        condition_variable cv;

    public:
        ZeroEvenOdd(int n) {
            this->n = n;
            this->flag = 0;
            this->count = 1;
        }

        // printNumber(x) outputs "x", where x is an integer.
        void zero(function<void(int)> printNumber) {
            unique_lock<mutex> lk(mtx);
            while (count <= n) {
                cv.wait(lk, [this]{ return flag == 0; });
                if (count <= n) printNumber(0);
                flag = 1;
                cv.notify_all();
            }
        }

        void even(function<void(int)> printNumber) {
            unique_lock<mutex> lk(mtx);
            while (count <= n) {
                cv.wait(lk, [this]{ return ((flag == 1) && (count%2 == 0)); });
                if (count <= n) printNumber(count);
                count++;
                flag = 0;
                cv.notify_all();

            }
        }

        void odd(function<void(int)> printNumber) {
            unique_lock<mutex> lk(mtx);
            while (count <= n) {
                cv.wait(lk, [this]{ return ((flag == 1) && (count%2 != 0)); });
                if (count <= n) printNumber(count);
                count++;
                flag = 0;
                cv.notify_all();

            }
        }
};

int main (int argc, char *argv[]) {
    ZeroEvenOdd obj(5);
    thread t_z(&ZeroEvenOdd::zero, &obj, printNumber);
    thread t_o(&ZeroEvenOdd::odd, &obj, printNumber);
    thread t_e(&ZeroEvenOdd::even, &obj, printNumber);
    t_z.join();
    t_o.join();
    t_e.join();
    return 0;
}

