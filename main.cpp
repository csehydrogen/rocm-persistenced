#include <cstdio>
#include <csignal>
#include <unistd.h>
#include <CL/cl.h>

inline void CHECK_OPENCL(cl_int ret, const char* file = __builtin_FILE(), int line = __builtin_LINE()) {
  if (ret != CL_SUCCESS) {
    printf("[%s:%d] OpenCL error %d\n", file, line, ret);
    exit(EXIT_FAILURE);
  }
}

int main() {
  unsigned num_platforms;
  CHECK_OPENCL(clGetPlatformIDs(0, NULL, &num_platforms));
  printf("%d OpenCL platforms are found. Keeping them awake... (pid=%d)\n", num_platforms, getpid());
  sigset_t mask;
  sigemptyset(&mask);
  while (true) {
    sigsuspend(&mask);
  }
  return 0;
}
