# cpp-basics

Basic C++ Project for Tests

## Build Steps

### Conan Preparation

```bash
cd cpp-basics
mkdir conan
cd conan
mkdir clang
mkdir gcc
cd clang
conan install ../.. -s build_type=Debug --build outdated -pr clang
cd ../gcc
conan install ../.. -s build_type=Debug --build outdated
```

### Build Project

Using VS code select `Run Task`>`DebugConfigure` and then `Ctrl+Shift+B

### Debug Project

