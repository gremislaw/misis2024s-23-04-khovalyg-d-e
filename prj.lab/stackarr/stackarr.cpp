#include "stackarr.hpp"

StackArr::StackArr(StackArr&& src) {
  std::swap(size_, src.size_);
  std::swap(top_ind_, src.top_ind_);
  std::swap(data_, src.data_);
}

StackArr::StackArr(const StackArr &src) {
    if (!src.IsEmpty()) {
        top_ind_ = src.top_ind_;
        size_ = top_ind_ * 2;
        data_ = new Complex[size_];
        std::copy(src.data_, src.data_ + src.size_, data_);
    }
}

StackArr::StackArr(const Complex &val) {
    top_ind_ += 1;
    size_ += 1;
    data_ = new Complex[size_];
    data_[top_ind_] = val;
}

StackArr& StackArr::operator=(StackArr &&src) {
    if (this != &src) {
        std::swap(size_, src.size_);
        std::swap(top_ind_, src.top_ind_);
        std::swap(data_, src.data_);
    }
    return *this;
}

StackArr& StackArr::operator=(const StackArr &src) {
    if (this != &src) {
        if (!IsEmpty()) {
            Clear();
        }
        if (size_ <= src.top_ind_) {
            size_ = src.top_ind_ + 1;
            Complex *buf = new Complex[size_];
            std::swap(data_, buf);
            delete[] buf;
        }
        top_ind_ = src.top_ind_;
        std::copy(src.data_, src.data_ + src.top_ind_ + 1, data_);
    }
    return *this;
}

StackArr::~StackArr() {
    delete[] data_;
}

bool StackArr::IsEmpty() const noexcept {
    return top_ind_ < 0;
}

void StackArr::Pop() noexcept {
    if (!IsEmpty()){
        top_ind_ -= 1;
    }
}

void StackArr::Push(const Complex &val) {
    if (data_ == nullptr) {
        size_ = 1;
        data_ = new Complex[size_];
    } else if (size_ == top_ind_ + 1) {
        Complex *buff = new Complex[size_ * 2];
        std::copy(data_, data_ + size_, buff);
        std::swap(data_, buff);
        delete[] buff;
        size_ *= 2;
    }
    data_[++top_ind_] = val;
}

Complex &StackArr::Top() {
    if (IsEmpty()) {
        throw std::logic_error("get top from empty stack");
    }
    return data_[top_ind_];
}

const Complex &StackArr::Top() const{
    if (IsEmpty()) {
        throw std::logic_error("get top from empty stack");
    }
    return data_[top_ind_];
}

void StackArr::Clear() noexcept{
    top_ind_ = -1;
}