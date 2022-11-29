
#include <iostream>
struct Cell{
    int state;
    int count;
    int count_1;
    int count_2;
    int count_3;
    int count_4;
    int count_5;
    int count_6;
    int count_7;
    int count_8;

    explicit
    Cell(int state = 0) : state(state), count_1(0), count_2(0), count_3(0), count_4(0){};

    Cell(const Cell &c) = default;
    Cell& operator=(const Cell &c) = default;

    Cell(Cell &&c) {
        if (this != &c) {
            int tmp_state = c.state;
            int tmp_count = c.count_1;
            c.~Cell();
            this->state = tmp_state;
            this->count_1 = tmp_count;
        }
    };
    Cell& operator=(Cell &&c) {
        if (this == &c) {
            return *this;
        } else {
            int tmp_state = c.state;
            int tmp_count = c.count_1;
            c.~Cell();
            state = tmp_state;
            count_1 = tmp_count;
            return *this;
        }
    };

    ~Cell() = default;

    friend std::ostream& operator<<(std::ostream& out, const Cell& c) {
        out << c.state;
        return out;
    }
};