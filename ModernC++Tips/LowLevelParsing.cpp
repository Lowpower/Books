template <int N, unsigned MUL, int INDEX = 0>
struct fastStringToIntStr;
inline unsigned fastStringToUnsigned(const char* str, int length) {
  switch (length) {
    case 10:
      return fastStringToIntStr<10, 1000000000>::aux(str);
    case 9:
      return fastStringToIntStr<9, 100000000>::aux(str);
    case 8:
      return fastStringToIntStr<8, 10000000>::aux(str);
    case 7:
      return fastStringToIntStr<7, 1000000>::aux(str);
    case 6:
      return fastStringToIntStr<6, 100000>::aux(str);
    case 5:
      return fastStringToIntStr<5, 10000>::aux(str);
    case 4:
      return fastStringToIntStr<4, 1000>::aux(str);
    case 3:
      return fastStringToIntStr<3, 100>::aux(str);
    case 2:
      return fastStringToIntStr<2, 10>::aux(str);
    case 1:
      return fastStringToIntStr<1, 1>::aux(str);
    default:
      return 0;
  }
}

template <int N, unsigned MUL, int INDEX>
struct fastStringToIntStr {
  static inline unsigned aux(const char* str) {
    return static_cast<unsigned>(str[INDEX] - '0') * MUL +
           fastStringToIntStr<N - 1, MUL / 10, INDEX + 1>::aux(str);
  }
};
template <unsigned MUL, int INDEX>
struct fastStringToIntStr<1, MUL, INDEX> {
  static inline unsigned aux(const char* str) {
    return static_cast<unsigned>(str[INDEX] - '0');
  }
};