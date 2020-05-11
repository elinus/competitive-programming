class DiningPhilosophers {
    public:
        DiningPhilosophers() {

        }

        void wantsToEat(int philosopher,
                function<void()> pickLeftFork,
                function<void()> pickRightFork,
                function<void()> eat,
                function<void()> putLeftFork,
                function<void()> putRightFork) {
            if (philosopher%2) {
                pickRightFork();
                pickLeftFork();
                eat();
                putLeftFork();
                putRightFork();
            } else {
                pickLeftFork();
                pickRightFork();
                eat();
                putRightFork();
                putLeftFork();

            }

        }
};
