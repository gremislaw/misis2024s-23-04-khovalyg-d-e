#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "complex/complex.hpp"
#include "doctest.h"
#include "stackarrt/stackarrt.hpp"

TEST_CASE_TEMPLATE("stackarrt constructor", T, Complex) {
  StackArrT<T> stack;
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt move constructor", T, Complex) {
  T c(1, 2);
  StackArrT<T> stack1(c);
  StackArrT<T> stack2(std::move(stack1));
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
  CHECK(stack1.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt push", T, Complex) {
  StackArrT<T> stack;
  T c(1, 2);
  stack.Push(c);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE_TEMPLATE("stackarrt pop", T, Complex) {
  StackArrT<T> stack;
  T c(1, 2);
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt copy constructor", T, Complex) {
  StackArrT<T> stack;
  T c(1, 2);
  stack.Push(c);
  StackArrT<T> stack2(stack);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack.Top(), c);
  CHECK_EQ(stack2.Top(), c);
  stack.Pop();
  CHECK(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
}

TEST_CASE_TEMPLATE("stackarrt assignment operator", T, Complex) {
  StackArrT<T> stack;
  T c(1, 2);
  stack.Push(c);
  StackArrT<T> stack2;
  stack2 = stack;
  CHECK_FALSE(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack.Top(), c);
  CHECK_EQ(stack2.Top(), c);
  stack.Pop();
  CHECK(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
}

TEST_CASE_TEMPLATE("stackarrt clear", T, Complex) {
  StackArrT<T> stack;
  T c(1, 2);
  stack.Push(c);
  stack.Clear();
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt push and pop", T, Complex) {
  StackArrT<T> stack;
  T c1(1, 2);
  T c2(3, 4);
  stack.Push(c1);
  stack.Push(c2);
  CHECK_EQ(stack.Top(), c2);
  stack.Pop();
  CHECK_EQ(stack.Top(), c1);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt resizing", T, Complex) {
  StackArrT<T> stack;
  T value;
  for (ptrdiff_t i = 0; i < 1e6; ++i) {
    value = T(i, i);
    stack.Push(value);
  }
  for (ptrdiff_t i = 1e6 - 1; i >= 0; --i) {
    CHECK_EQ(stack.Top(), T(i, i));
    stack.Pop();
  }
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt resizing and copy", T, Complex) {
  StackArrT<T> stack;
  T value;
  for (ptrdiff_t i = 0; i < 1e6; ++i) {
    value = T(i, i);
    stack.Push(value);
  }
  StackArrT<T> stack2(stack);
  for (ptrdiff_t i = 1e6 - 1; i >= 0; --i) {
    CHECK_EQ(stack.Top(), T(i, i));
    CHECK_EQ(stack2.Top(), T(i, i));
    stack.Pop();
    stack2.Pop();
  }
  CHECK(stack.IsEmpty());
  CHECK(stack2.IsEmpty());
}

TEST_CASE_TEMPLATE("stackarrt resizing and assignment", T, Complex) {
  StackArrT<T> stack;
  T value;
  for (ptrdiff_t i = 0; i < 1e6; ++i) {
    value = T(i, i);
    stack.Push(value);
  }
  StackArrT<T> stack2;
  stack2 = stack;
  for (ptrdiff_t i = 1e6 - 1; i >= 0; --i) {
    CHECK_EQ(stack.Top(), T(i, i));
    CHECK_EQ(stack2.Top(), T(i, i));
    stack.Pop();
    stack2.Pop();
  }
  CHECK(stack.IsEmpty());
  CHECK(stack2.IsEmpty());
}