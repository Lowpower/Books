template <int SIZE, typename Lambda>
constexpr std::array<float, SIZE> build(Lambda lambda) {
  std::array<float, SIZE> array{};
  for (int i = 0; i < SIZE; i++)
    array[i] = lambda(i);
  return array;
}
float log10(int value) {
  constexpr auto lamba = [](int i) { return std::log10f((float)i); };
  static constexpr auto table = build<100>(lambda);
  return table[value];
}