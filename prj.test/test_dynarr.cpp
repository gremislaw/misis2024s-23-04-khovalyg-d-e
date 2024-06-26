#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dynarr/dynarr.hpp"

DynArr arr(13);

TEST_CASE("dynarr size ") { CHECK(arr.Size() == 13); }

TEST_CASE("dynarr resize") {
  arr.Resize(17);
  CHECK(arr.Size() == 17);
}

TEST_CASE("dynarr operator[]") {
  for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
    arr[i] = i;
  }
  for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
    CHECK(arr[i] == doctest::Approx(i));
  }
}

TEST_CASE("dynarr out of range") {
  CHECK_THROWS_AS(arr[arr.Size()], std::out_of_range);
  CHECK_THROWS_AS(arr[arr.Size() + 1], std::out_of_range);
}

TEST_CASE("dynarr copy constructor") {
  DynArr arr2(arr);
  CHECK(arr2.Size() == arr.Size());
  for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
    CHECK(arr2[i] == doctest::Approx(arr[i]));
  }
}

TEST_CASE("dynarr copy assignment") {
  DynArr arr2(10);
  arr2 = arr;
  CHECK(arr2.Size() == arr.Size());
  for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
    CHECK(arr2[i] == doctest::Approx(arr[i]));
  }
}
