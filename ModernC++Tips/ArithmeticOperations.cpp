bool mainGuT(uint32_t i1, uint32_t i2,  // if i1, i2 are int32 t, the code
             uint8_t *block) {          // uses half of the instructions!!
  uint8_t c1, c2;
  // 1 // why? if i1, i2 are uint32 t the compiler
  c1 = block[i1], c2 = block[i2];  // must copy them into 32-bit registers to
  if (c1 != c2) return (c1 > c2);  // ensure wrap-around behavior before passing
  i1++, i2++;                      // them to the subscript operator (size_t)
  // 2 // On the other hand, int32 t overflow is
  c1 = block[i1], c2 = block[i2];  // undefined behavior and the compiler can
  if (c1 != c2) return (c1 > c2);  // assume it never happens
  i1++, i2++;
  // ... continue repeating the // the code is also optimal with size t on 64-bit
}  // code multiple times // arch because block cannot be larger than it
