#if !defined(__linux__)
#error It works only on linux
#endif
#include <fcntl.h>      //::open
#include <sys/mman.h>   //::mmap
#include <sys/stat.h>   //::open
#include <sys/types.h>  //::open
#include <unistd.h>     //::lseek
#include <iostream>
// usage: ./exec <file> <byte_size> <mode>

void ERROR(const char* msg) {
  std::cerr << msg << std::endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  size_t file_size = std::stoll(argv[2]);
  auto is_read = std::string(argv[3]) == "READ";
  int fd = is_read ? ::open(argv[1], O_RDONLY) : ::open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (fd == -1)
    ERROR("::open");  // try to get the last byte
  if (::lseek(fd, static_cast<off_t>(file_size - 1), SEEK_SET) == -1)
    ERROR("::lseek");
  if (!is_read && ::write(fd, "", 1) != 1)  // try to write
    ERROR("::write");
  auto mm_mode = (is_read) ? PROT_READ : PROT_WRITE;
  // Open Memory Mapped file
  auto mmap_ptr = static_cast<char*>(
      ::mmap(nullptr, file_size, mm_mode, MAP_SHARED, fd, 0));
  if (mmap_ptr == MAP_FAILED)
    ERROR("::mmap");
  // Advise sequential access
  if (::madvise(mmap_ptr, file_size, MADV_SEQUENTIAL) == -1)
    ERROR("::madvise");
  // MemoryMapped Operations
  // read from/write to "mmap_ptr" as a normal array: mmap_ptr[i]
  // Close Memory Mapped file
  if (::munmap(mmap_ptr, file_size) == -1)
    ERROR("::munmap");
  if (::close(fd) == -1)
    ERROR("::close");
}