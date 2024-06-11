// Kim, Joonbeom
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
// ADDING A NEW COMMENT
namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename T>
class Points2D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    // and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points2D() : size_{0}, sequence_{nullptr}{}

    // Copy-constructor.
    Points2D(const Points2D &rhs){
        std::cout << "copy constructor is called" << std::endl;
        size_ = rhs.size_;

        sequence_ = new std::array<T, 2>[size_];
        for (int i = 0; i < size_; i++){
            sequence_[i] = rhs.sequence_[i];
        }
    };
    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points2D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points2D& operator=(const Points2D &rhs){
        std::cout << "copy assignment is called" << std::endl;
        Points2D copy = rhs;            // creating a copy constructor of rhs
        std::swap(*this, copy);         // swap the original address to copy constructor's address. now original address has rhs's address
        return *this;                   // return the swapped address, which is the address of copy or rhs
    };
        // if(&rhs != this){
        //     size_ = rhs.size_;

        //     delete[] sequence_;
        //     sequence_ = new std::array<T, 2>[rhs.size_];
        //     for(int i = 0; i < size_; i++){
        //         sequence_[i] = rhs.sequence_[i];
        //     }
        // }
        // return *this;


    // Move-constructor.
    Points2D(Points2D &&rhs){
        std::cout << "move constructor is called" << std::endl;

        size_ = rhs.size_;
        sequence_ = rhs.sequence_;

        rhs.size_ = 0;
        rhs.sequence_ = nullptr;
    };

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points2D& operator=(Points2D &&rhs){
        std::cout << "move assignment is called" << std::endl;
        if(&rhs != this){
            std::swap(size_, rhs.size_);
            std::swap(sequence_, rhs.sequence_);
        }
        return *this;
    };

    ~Points2D(){
        std::cout << "destructor is called" << std::endl;
        delete[] sequence_;
    };

    // End of big-five.

    // One parameter constructor.
    Points2D(const std::array<T, 2>& item) {
        size_ = 1;                                  //  now we have one item added
        
        sequence_ = new std::array<T, 2>[size_];
        sequence_[0] = item;                        //  the first element of the sequence_ array store the parameter value, item

    }

    size_t size() const {
        return size_;
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<T, 2>& operator[](size_t location) const {
        if(location < size_){
            return sequence_[location];
        }
        cout << "out of range" << endl;
        std::abort();
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        // Code missing.
    }

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        for (int i = 0; i < some_points.size_; i++){
            out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ")";

        return out;
        }
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        std::size_t size;
        in >> size;     //  inputing the size of the 2D array

        some_points.size_ = size;
        some_points.sequence_ = new std::array<T, 2>[size];

        for(int i = 0; i < some_points.size_; i++){
            in >> some_points.sequence_[i][0] >> some_points.sequence_[i][1];
        }

    return in;
    }


  private:
    // Sequence of points.
    std::array<T, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_