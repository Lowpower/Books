#include <fstream>
#include <iostream>

int main() {
  std::ifstream fin;
  /*
     禁用了C++标准流（如 std::cout）与C标准流（如 printf）之间的同步。
     这样做可以提高C++标准流的I/O性能，因为同步操作通常会导致性能下降。
     */
  std::ios_base::sync_with_stdio(false);  // sync disable
  /*
  默认情况下，std::cin 和 std::cout 是绑定的，意味着每次输入操作前会自动刷新输出缓冲区。
  通过将 fin 的绑定设为 nullptr，可以禁用这种自动刷新，进一步提高性能。
  */
  fin.tie(nullptr);  // flush disable
  // buffer increase
  /*
    创建一个1MB的字符数组作为输入流的缓冲区 
    通过增加缓冲区大小，可以减少对磁盘的读取次数，从而提高文件读取速度。
  */
  const int BUFFER_SIZE = 1024 * 1024;  // 1 MB
  char buffer[BUFFER_SIZE];
  fin.rdbuf()->pubsetbuf(buffer, BUFFER_SIZE);
  std::string filename = "example.txt";  // 假设文件名为 example.txt
  fin.open(filename);                    // Note: open() after optimizations
  // IO operations
  fin.close();
}