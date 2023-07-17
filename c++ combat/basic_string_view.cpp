#include <iostream>
#include <string>

template<typename CharT, typename Traits = std::char_traits<CharT>>
class basic_string_view {
 public:
  using traits_type = Traits;
  using size_type = std::size_t;

  using value_type = CharT;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

  using const_iterator = const value_type*;
  using iterator = const_iterator;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using reverse_iterator = const const_reverse_iterator;

  static constexpr size_type npos = size_type(-1);
 
 public:
  constexpr basic_string_view() noexcept : str_{nullptr}, size_{0} {}
  constexpr basic_string_view(const basic_string_view&) noexcept = default;
  constexpr basic_string_view(basic_string_view&&) noexcept = default;
  constexpr basic_string_view(const CharT* str) : str_(str), size_{traits_type::length(str)} {}
  constexpr basic_string_view(const CharT* str, size_type len) : str_(str), size_{len} {}
  constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;
  constexpr basic_string_view& operator=(basic_string_view&&) noexcept = default;
  constexpr basic_string_view(const std::basic_string<CharT, Traits>& str) noexcept : str_(str.c_str()), size_(str.size()) {}
  explicit constexpr operator std::basic_string<CharT, Traits>() const {
    return std::basic_string<CharT, Traits>(this->str_, this->size_);
  }

 public:
  constexpr const_iterator begin() const noexcept {
    return this->str_;
  }
  constexpr const_iterator end() const noexcept {
    return this->str_ + this->size_;
  }
  const const_iterator cbegin() const noexcept {
    return this->begin();
  }
  const const_iterator cend() const noexcept {
    return this->end();
  }
  constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(this->end());
  }
  constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(this->begin());
  }

 public:
  constexpr size_type size() const noexcept {
    return this->size_;
  }
  constexpr size_type length() const noexcept {
    return this->size_;
  }
  constexpr size_type max_size() const noexcept {
    return npos - 1;
  }
  constexpr bool empty() const noexcept {
    return this->size_ == 0;
  }
  
 public:
  constexpr const_pointer data() const noexcept {
    return this->str_;
  }
  constexpr const_reference operator[](size_type pos) const noexcept {
    return *(this->str_ + pos);
  }
  constexpr const_reference at(size_type pos) const {
    if (pos >= this->size_) {
      throw std::out_of_range{"out of range"};
    }
    return *(this->str_ + pos);
  }
  constexpr const_reference front() const noexcept {
    return *this->str_;
  }
  constexpr const_reference back() const noexcept {
    return *(this->str_ + size_ -1);
  }
  constexpr void remove_prefix(size_type n) noexcept {
    this->str_ += n;
    this->size_ -= n;
  }
  constexpr void remove_suffix(size_type n) noexcept {
    this->size_ -= n;
  }
  constexpr void swap(basic_string_view& v) noexcept {
    std::swap(*this, v);
  }
  constexpr basic_string_view substr(size_type pos = 0, size_type len = npos) const {
    if (pos > this->size_) {
      throw std::out_of_range{"out of range"};
    }
    const size_type n = std::min(len, this->size_ - pos);
    return basic_string_view(this->str_ + pos, n);
  }

 private:
  const CharT* str_;
  size_type size_;
};

template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const basic_string_view<CharT, Traits>& str) {
  os.write(str.data(), static_cast<std::streamsize>(str.size()));
  return os;
}

using string_view = basic_string_view<char>;

int main() {
  std::string str1{"hello world1"};
  std::string str2{"hello world2"};
  string_view sv5{str1};
  string_view sv6{str2};
  std::string stt = static_cast<std::string>(sv5);
  std::cout << sv5 << std::endl;
  sv5.swap(sv6);
  std::cout << sv5 << std::endl;
  return 0;
}