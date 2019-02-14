// 2019 Daniel Varga (vargad88@gmail.com)

// $ clang++ 300_markov.cpp -o 300_markov -O3 -march=native -mtune=native -ftree-vectorize -ffast-math -fopenmp

#include <cassert>
#include <vector>
#include <iostream>

constexpr int Size = 300;

class Vec2
{
public:
    int row, col;
};

class Matrix
{
public:
    Matrix(int size)
        : mSize(size)
        , mData(size*size)
    {}
    Matrix(Matrix const &) = default;
    Matrix(Matrix &&) = default;
    Matrix& operator=(Matrix const &) = default;
    Matrix& operator=(Matrix &&) = default;

    double& operator[](Vec2 const &pos) { return mData[pos.col+pos.row*mSize]; }
    double operator[](Vec2 const &pos) const { return mData[pos.col+pos.row*mSize]; }

    int size() const { return mSize; }
private:
    int mSize;
    std::vector<double> mData;
};

Matrix step(Matrix const &tm, Matrix const &current) {
    assert(tm.size() == current.size());
    Matrix next(tm.size());
#pragma omp parallel for schedule(auto)
    for (int src_state=0; src_state<tm.size(); ++src_state) {
        // note we start from src_state to optimize in this case, as there is no step back to previous state, but this is not correct in general for Markov-chains
        for (int dest_state=src_state; dest_state<tm.size(); ++dest_state) {
            double sum = 0;
            for (int dest=0; dest<tm.size(); ++dest)
                sum += tm[Vec2{src_state,dest}] * current[Vec2{dest, dest_state}];
            next[Vec2{src_state, dest_state}] = sum;
        }
    }
    return next;
}

int main() {
    Matrix tm(Size+1);
    for (int i=0; i<tm.size(); ++i) {
        tm[Vec2{0,i}] = i == 1 ? 1 : 0; // we always move from first state to the next
        tm[Vec2{Size,i}] = i == Size ? 1 : 0; // we always stay in last state
    }
    for (int i=0; i<tm.size(); ++i) {
        for (int j=1; j<tm.size()-1; ++j) {
            if (i == j) { // stay in current state
                tm[Vec2{j,i}] = double(j)/Size;
            } else if (j == i-1) { // step to next state
                tm[Vec2{j,i}] = (double(Size)-j)/Size;
            } else {
                tm[Vec2{j,i}] = 0;
            }
        }
    }

    Matrix n = tm;
    int buy_count = 0;
    while (n[Vec2{0,Size}] < 0.99) {
        std::cout << buy_count << " " << n[Vec2{0,Size}]*100 << std::endl;
        ++buy_count;
        n = step(tm, n);
    }
}

