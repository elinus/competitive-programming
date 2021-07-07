class FooBar {
private:
    int n;
    std::mutex m_;
    std::condition_variable cv_;
    int counter = 1;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> l_(m_);
            cv_.wait(l_, [this]()
                     {
                         return counter == 1;
                     });
            counter++;
            counter %= 2;
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            cv_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> l_(m_);
            cv_.wait(l_, [this]()
                     {
                         return counter == 0;
                     });
            counter++;
            counter %= 2;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            cv_.notify_one();
        }
    }
};
