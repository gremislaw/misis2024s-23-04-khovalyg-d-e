#pragma once
#ifndef STACKARRT_HPP
#define STACKARRT_HPP

#include <algorithm>
#include <cstddef>
#include <stdexcept>

template <class T>
class StackArrT {
 public:
  StackArrT() = default;
  StackArrT(StackArrT &&);
  StackArrT(const StackArrT &);
  StackArrT(const T &);
  ~StackArrT();

  StackArrT &operator=(const StackArrT &);
  StackArrT &operator=(StackArrT &&);

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;
  void Push(const T &val);

  [[nodiscard]] T &Top();
  [[nodiscard]] const T &Top() const;

  void Clear() noexcept;

 private:
  ptrdiff_t size_ = 0;
  ptrdiff_t top_ind_ = -1;
  T *data_ = nullptr;
};

template <class T>
StackArrT<T>::StackArrT(StackArrT<T> &&src) {
  std::swap(size_, src.size_);
  std::swap(top_ind_, src.top_ind_);
  std::swap(data_, src.data_);
}

template <class T>
StackArrT<T>::StackArrT(const StackArrT<T> &src) {
  if (!src.IsEmpty()) {
    top_ind_ = src.top_ind_;
    size_ = top_ind_ * 2;
    data_ = new T[size_];
    std::copy(src.data_, src.data_ + src.size_, data_);
  }
}

template <class T>
StackArrT<T>::StackArrT(const T &val) {
  top_ind_ += 1;
  size_ += 1;
  data_ = new T[size_];
  data_[top_ind_] = val;
}

template <class T>
StackArrT<T> &StackArrT<T>::operator=(StackArrT<T> &&src) {
  if (this != &src) {
    std::swap(size_, src.size_);
    std::swap(top_ind_, src.top_ind_);
    std::swap(data_, src.data_);
  }
  return *this;
}

template <class T>
StackArrT<T> &StackArrT<T>::operator=(const StackArrT<T> &src) {
  if (this != &src) {
    if (!IsEmpty()) {
      Clear();
    }
    if (size_ <= src.top_ind_) {
      size_ = src.top_ind_ + 1;
      T *buf = new T[size_];
      std::swap(data_, buf);
      delete[] buf;
    }
    top_ind_ = src.top_ind_;
    std::copy(src.data_, src.data_ + src.top_ind_ + 1, data_);
  }
  return *this;
}

template <class T>
StackArrT<T>::~StackArrT() {
  delete[] data_;
}

template <class T>
bool StackArrT<T>::IsEmpty() const noexcept {
  return top_ind_ < 0;
}

template <class T>
void StackArrT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    top_ind_ -= 1;
  }
}

template <class T>
void StackArrT<T>::Push(const T &val) {
  if (data_ == nullptr) {
    size_ = 1;
    data_ = new T[size_];
  } else if (size_ == top_ind_ + 1) {
    T *buff = new T[size_ * 2];
    std::copy(data_, data_ + size_, buff);
    std::swap(data_, buff);
    delete[] buff;
    size_ *= 2;
  }
  data_[++top_ind_] = val;
}

template <class T>
T &StackArrT<T>::Top() {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty stack");
  }
  return data_[top_ind_];
}

template <class T>
const T &StackArrT<T>::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("get top from empty stack");
  }
  return data_[top_ind_];
}

template <class T>
void StackArrT<T>::Clear() noexcept {
  top_ind_ = -1;
}

#endif
