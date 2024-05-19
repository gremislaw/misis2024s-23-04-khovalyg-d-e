#include "bitset.hpp"

BitSet::BitSet(BitSet &&src) noexcept : size_(src.size_), bits_(src.bits_) {
  src.size_ = 0;
  src.bits_ = nullptr;
}

BitSet::BitSet(const BitSet &src) {
  Resize(src.Size());
  for (int32_t i = 0; i < src.Size(); i++) {
    bits_[i] = src.bits_[i];
  }
}

BitSet::BitSet(const int32_t size) {
  if (size <= 0) {
    throw std::invalid_argument(
        "BitSet::Bitset size should be a positive number");
  }
  Resize(size);
  Fill(false);
}

BitSet::~BitSet() {
  delete[] bits_;
  size_ = 0;
  bits_ = nullptr;
}

BitSet &BitSet::operator=(BitSet &&src) {
  if (this != &src) {
    delete[] bits_;
    size_ = src.size_;
    bits_ = src.bits_;
    src.size_ = 0;
    src.bits_ = nullptr;
  }
  return *this;
}

BitSet &BitSet::operator=(const BitSet &src) {
  if (this != &src) {
    this->Resize(src.Size());
    for (bool *i = bits_; i < bits_ + size_; i++)
      *(i) = *(src.bits_ + (i - bits_));
  }
  return *this;
}

bool BitSet::operator==(const BitSet &src) const noexcept {
  if (size_ != src.size_) return false;
  for (int32_t i = 0; i < size_; i++) {
    if (bits_[i] != src.bits_[i]) return false;
  }
  return true;
}

bool BitSet::operator!=(const BitSet &src) const noexcept {
  return !(*this == src);
}

BitSet &BitSet::operator&=(const BitSet &src) {
  if (size_ != src.size_)
    std::invalid_argument("BitSet::operator&= sizes are not equal");
  for (int32_t i = 0; i < size_; i++) {
    bits_[i] &= src.bits_[i];
  }
  return *this;
}

BitSet &BitSet::operator|=(const BitSet &src) {
  if (size_ != src.size_)
    std::invalid_argument("BitSet::operator|= sizes are not equal");
  for (int32_t i = 0; i < size_; i++) {
    bits_[i] |= src.bits_[i];
  }
  return *this;
}

BitSet &BitSet::operator^=(const BitSet &src) {
  if (size_ != src.size_)
    std::invalid_argument("BitSet::operator^= sizes are not equal");
  for (int32_t i = 0; i < size_; i++) {
    bits_[i] ^= src.bits_[i];
  }
  return *this;
}

BitSet BitSet::operator~() {
  BitSet new_bitset(size_);
  for (int i = 0; i < new_bitset.size_; i++) {
    new_bitset.bits_[i] = !bits_[i];
  }
  return new_bitset;
}

void BitSet::Resize(const int32_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Size should be a positive number");
  } else if (size < size_) {
    for (bool *i = bits_; i < bits_ + size_; i++) {
      if (i >= bits_ + size) *i = 0;
    }
  } else {
    bool *temp = new bool[2 * size];
    for (bool *i = temp; i < temp + 2 * size; i++) {
      if (i - temp < size_)
        *i = *(bits_ + (i - temp));
      else
        *i = 0;
    }
    delete[] bits_;
    bits_ = temp;
  }
  size_ = size;
}

void BitSet::Set(const int32_t idx, const bool val) {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("BitSet::Set size out of range");
  }
  bits_[idx] = val;
}

bool BitSet::Get(const int32_t idx) const {
  if (idx < 0 || idx >= size_) {
    throw std::out_of_range("BitSet::Set size out of range");
  }
  return bits_[idx];
}

void BitSet::Fill(const bool val) noexcept {
  for (int32_t idx = 0; idx < size_; idx++) {
    bits_[idx] = val;
  }
}

bool BitSet::IsEmpty() const noexcept { return size_ == 0; }

BitSet operator&(const BitSet &lhs, const BitSet &rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::invalid_argument("operator& sizes are not equal");
  }
  BitSet new_bitset(lhs.Size());
  for (int32_t i = 0; i < lhs.Size(); ++i) {
    new_bitset.Set(i, lhs.Get(i) & rhs.Get(i));
  }
  return new_bitset;
}

BitSet operator|(const BitSet &lhs, const BitSet &rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::invalid_argument("operator| sizes are not equal");
  }
  BitSet new_bitset(lhs.Size());
  for (int32_t i = 0; i < lhs.Size(); ++i) {
    new_bitset.Set(i, lhs.Get(i) | rhs.Get(i));
  }
  return new_bitset;
}

BitSet operator^(const BitSet &lhs, const BitSet &rhs) {
  if (lhs.Size() != rhs.Size()) {
    throw std::invalid_argument("operator^ sizes are not equal");
  }
  BitSet new_bitset(lhs.Size());
  for (int32_t i = 0; i < lhs.Size(); ++i) {
    new_bitset.Set(i, lhs.Get(i) ^ rhs.Get(i));
  }
  return new_bitset;
}

bool BitSet::operator[](const int32_t idx) { return Get(idx); }

std::ostream &BitSet::WriteTxt(std::ostream &os) {
  for (int32_t i = 0; i < size_; ++i) {
    os << bits_[i];
  }
  return os;
}

std::ostream &BitSet::WriteBinary(std::ostream &os) {
  for (int32_t i = 0; i < size_; ++i) {
    os.write(reinterpret_cast<char *>(&bits_[i]), sizeof(bits_[i]));
  }
  return os;
}

std::istream &BitSet::ReadTxt(std::istream &is) {
  std::string str;
  is >> str;
  size_ = str.size();
  bits_ = new bool[size_];
  for (int32_t i = 0; i < size_; ++i) {
    bits_[i] = str[i] - '0';
  }
  return is;
}

std::istream &BitSet::ReadBinary(std::istream &is) {
  is.read(reinterpret_cast<char *>(bits_), sizeof(bits_) * size_);
  return is;
}

std::ostream &operator<<(std::ostream &os, const BitSet &bs) {
  for (int32_t i = 0; i < bs.Size(); ++i) {
    os << bs.Get(i);
  }
  return os;
}

std::istream &operator>>(std::istream &is, BitSet &bs) {
  std::string str;
  is >> str;
  bs.Resize(str.size());
  for (int32_t i = 0; i < bs.Size(); ++i) {
    bs.Set(i, str[i] - '0');
  }
  return is;
}
