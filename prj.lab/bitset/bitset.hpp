#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class BitSet {
  BitSet() = default;
  BitSet(BitSet&&) noexcept;
  BitSet(const BitSet&);
  BitSet(const int32_t);
  ~BitSet();

  BitSet& operator=(const BitSet&);
  BitSet& operator=(BitSet&&);

  [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

  int32_t Size() const noexcept { return size_; }
  void Resize(const int32_t size);
  [[nodiscard]] bool Get(const int32_t idx) const;
  void Set(const int32_t idx, const bool val);
  void Fill(const bool val) noexcept;
  bool IsEmpty() const noexcept;

  [[nodiscard]] BitSet& operator&=(const BitSet& rhs);
  [[nodiscard]] BitSet& operator|=(const BitSet& rhs);
  [[nodiscard]] BitSet& operator^=(const BitSet& rhs);
  [[nodiscard]] BitSet operator~();

  bool operator[](const int32_t);
  std::ostream& WriteTxt(std::ostream&);
  std::ostream& WriteBinary(std::ostream&);
  std::istream& ReadTxt(std::istream&);
  std::istream& RaadBinary(std::istream&);

 private:
  std::int32_t size_ = 0;
  bool* bits_ = nullptr;
};

std::ostream& operator<<(std::ostream&, const BitSet&);
std::istream& operator>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif