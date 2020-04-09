FROM ubuntu:18.04

RUN apt-get update && apt-get install -y wget gnupg2 software-properties-common &&\
  wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|apt-key add - &&\
  apt-add-repository 'deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-10 main' &&\
  apt-get update && apt-get install -y build-essential cmake libssl-dev ninja-build clang-10 clang-format-10 clang-tidy-10 &&\
  rm -rf /var/lib/apt/lists/* &&\
  ln -sf /usr/bin/clang++-10 /usr/bin/c++ &&\
  ln -sf /usr/bin/clang-10 /usr/bin/cc

RUN mkdir /download && cd /download && wget https://github.com/Kitware/CMake/releases/download/v3.16.5/cmake-3.16.5.tar.gz &&\
  tar -zxvf cmake-3.16.5.tar.gz && cd cmake-3.16.5 && cmake . -G Ninja && ninja install &&\
  rm -rf /download

RUN mkdir /build
WORKDIR /build