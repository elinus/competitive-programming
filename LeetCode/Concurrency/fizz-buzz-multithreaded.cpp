#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

void printNumber(int i) {
    cout << i << endl;
}

void printFizz() {
    cout << "fizz" << endl;
}

void printBuzz() {
    cout << "buzz" << endl;
}

void printFizzBuzz() {
    cout << "fizzbuzz" << endl;
}

//enum class Flag { Fizz, Buzz, FizzBuzz, Number };

class FizzBuzz {
    private:
        int n;
        int current = 1;
//        Flag flag = Flag::Number;
        mutex m_;
        condition_variable cv_;
    public:
        FizzBuzz(int n) {
            this->n = n;
        }
/*
        void setFlag() {
            if (current > n) return;
            if (current % 15 == 0) {
                flag = Flag::FizzBuzz;
            } else if (current % 5 == 0) {
                flag = Flag::Buzz;
            } else if (current % 3 == 0) {
                flag = Flag::Fizz;
            } else {
                flag = Flag::Number;
            }
        }
*/
        // printFizz() outputs "fizz".
        void fizz(function<void()> printFizz) {
            unique_lock<mutex> l_(m_);
            while (current <= n) {
                cv_.wait(l_, [this](){ return (current%3 == 0 && current%5 != 0) || current > n; });
                if (current > n) break;
                printFizz();
                current++;
               // setFlag();
                cv_.notify_all();
            }
        }

        // printBuzz() outputs "buzz".
        void buzz(function<void()> printBuzz) {
            unique_lock<mutex> l_(m_);
            while (current <= n) {
                cv_.wait(l_, [this](){ return (current%3 != 0 && current%5 == 0) || current > n; });
                if (current > n) break;
                printBuzz();
                current++;
                //setFlag();
                cv_.notify_all();
            }
        }

        // printFizzBuzz() outputs "fizzbuzz".
        void fizzbuzz(function<void()> printFizzBuzz) {
            unique_lock<mutex> l_(m_);
            while (current <= n) {
                cv_.wait(l_, [this](){ return current%15 == 0 || current > n; });
                if (current > n) break;
                printFizzBuzz();
                current++;
                //setFlag();
                cv_.notify_all();
            }
        }

        // printNumber(x) outputs "x", where x is an integer.
        void number(function<void(int)> printNumber) {
            unique_lock<mutex> l_(m_);
            while (current <= n) {
                cv_.wait(l_, [this](){ return (current%3 != 0 && current%5 != 0) || current > n; });
                if (current > n) break;
                printNumber(current);
                current++;
                //setFlag();
                cv_.notify_all();
            }
        }
};

int main (int argc, char *argv[]) {
    FizzBuzz obj(15);
    thread tn(&FizzBuzz::number, &obj, printNumber);
    thread tf(&FizzBuzz::fizz, &obj, printFizz);
    thread tb(&FizzBuzz::buzz, &obj, printBuzz);
    thread tfb(&FizzBuzz::fizzbuzz, &obj, printFizzBuzz);
    tn.join();
    tf.join();
    tb.join();
    tfb.join();
    return 0;
}

