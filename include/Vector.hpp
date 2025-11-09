#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>

class Vector{

    private:

        T* data_;
        std::size_t size_;
        std::size_t capacity_;

    public:

        Vector(){
            size_ = 0;
            capacity_ = 0;
            data_ = nullptr;
        }

        explicit Vector(std::size_t  initial_size){
            size_ = 0;
            capacity_ = initial_size;
            data_ = new T[capacity_];
        }

        Vector(const Vector &obj){
            size_ = obj.size_;
            capacity_ = obj.capacity_;

            data_ = new T[capacity_];
            for(std::size_t i = 0; i < size_; i++){
                data_[i] = obj.data_[i];
            }      
        }

        T& operator[](std::size_t index){
            return data_[index];
        }

        const T& operator[](std::size_t index) const{
            return data_[index];
        }

        ~Vector(){
            size_ = 0;
            capacity_ = 0;
            delete[] data_;
            data_ = nullptr;
        }

        void push_back(const T &obj){

            if(size_ == capacity_)  {

                T* newData = new T[capacity_ * 2];

                for(std::size_t i = 0; i < size_; i++){
                    newData[i] = data_[i];
                }
                delete[] data_;
                data_ = newData;
                capacity_ *= 2;
            }
            data_[size_++] = obj;
        }

        T pop(){
            if(size_ == 0){
                throw std::out_of_range("Pop called on empty vector");
            }
            T obj = data_[size_ - 1];
            size_--;
            return obj;
        }
};
