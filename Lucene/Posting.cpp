#include <vector>
#include <array>

class PostingVector {
};

class Posting {
 private:
  int textStart;
  int docFreq;
  int freqStart;
  int freqTo;
  int proxStart;
  int proxTo;
  int lastDocId;
  int lastDocCode;
  int lastPosition;
  PostingVector vector;
};

class ByteBlockPool {
 public:
  int newSlice(int size) {
    if (byteUpto > BYTE_BLOCK_SIZE) {
      nextBuffer();
    }
    int upto = byteUpto;
    byteUpto += size;
    buffer[byteUpto - 1] = 16;
    return upto; 
  }
 private:
  std::array<std::vector<char>, 10> buffers;
  int bufferUpto = -1;
  int byteUpto = BYTE_BLOCK_SIZE;
  std::vector<int8_t> buffer;
  int byteOffset = - BYTE_BLOCK_SIZE;
};


