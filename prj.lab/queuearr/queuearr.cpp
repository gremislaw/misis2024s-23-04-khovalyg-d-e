#include "queuearr.hpp"

QueueArr::QueueArr(QueueArr &&src) noexcept {
  std::swap(size_, src.size_);
  std::swap(front_ind_, src.front_ind_);
  std::swap(data_, src.data_);
}

QueueArr::QueueArr(const QueueArr &src) {
  if (!src.IsEmpty()) {
    front_ind_ = src.front_ind_;
    size_ = front_ind_ * 2;
    data_ = new Complex[size_];
    std::copy(src.data_, src.data_ + src.size_, data_);
  }
}

QueueArr::QueueArr(const Complex &val) {
  front_ind_ += 1;
  size_ += 1;
  data_ = new Complex[size_];
  data_[front_ind_] = val;
}

QueueArr &QueueArr::operator=(QueueArr &&src) noexcept {
  if (this != &src) {
    std::swap(size_, src.size_);
    std::swap(front_ind_, src.front_ind_);
    std::swap(data_, src.data_);
  }
  return *this;
}

QueueArr &QueueArr::operator=(const QueueArr &src) {
  if (this != &src) {
    if (!IsEmpty()) {
      Clear();
    }
    if (size_ <= src.front_ind_) {
      size_ = src.front_ind_ + 1;
      Complex *buf = new Complex[size_];
      std::swap(data_, buf);
      delete[] buf;
    }
    front_ind_ = src.front_ind_;
    std::copy(src.data_, src.data_ + src.front_ind_ + 1, data_);
  }
  return *this;
}

QueueArr::~QueueArr() { delete[] data_; }

bool QueueArr::IsEmpty() const noexcept { return front_ind_ < 0; }

void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    front_ind_ -= 1;
  }
}

void QueueArr::Push(const Complex &val) {
  if (data_ == nullptr) {
    size_ = 1;
    data_ = new Complex[size_];
  } else if (size_ == front_ind_ + 1) {
    Complex *buff = new Complex[size_ * 2];
    std::copy(data_, data_ + size_, buff);
    std::swap(data_, buff);
    delete[] buff;
    size_ *= 2;
  }
  Complex *temp = new Complex[size_];
  std::copy(data_, data_ + front_ind_ + 1, temp + 1);
  std::swap(data_, temp);
  delete[] temp;
  data_[0] = val;
  ++front_ind_;
}

Complex &QueueArr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("get front from empty Queue");
  }
  return data_[front_ind_];
}

const Complex &QueueArr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("get front from empty Queue");
  }
  return data_[front_ind_];
}

Complex &QueueArr::Tail() {
  if (IsEmpty()) {
    throw std::logic_error("get front from empty Queue");
  }
  return data_[0];
}

const Complex &QueueArr::Tail() const {
  if (IsEmpty()) {
    throw std::logic_error("get front from empty Queue");
  }
  return data_[0];
}

void QueueArr::Print() const {
  std::cout << std::endl;
  for (int i = 0; i < front_ind_; i++) {
    std::cout << data_[i] << " >> ";
  }
  std::cout << data_[front_ind_] << std::endl;
}

void QueueArr::Clear() noexcept { front_ind_ = -1; }