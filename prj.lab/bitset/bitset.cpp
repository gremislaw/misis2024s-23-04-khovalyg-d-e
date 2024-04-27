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

BitSet::BitSet(const int32_t val) {
  if (val <= 0) {
    throw std::invalid_argument("Size should be a positive number");
  }
  Resize(val);
  Fill(false);
}

BitSet::~BitSet() {
  delete[] bits_;
  bits_ = nullptr;
}

BitSet::&BitSet operator=(Bitset &&src) {}

int32_t BitSet::Size() const noexcept { return size_; }

void BitSet::Resize(const int32_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Size should be a positive number");
  }
}
