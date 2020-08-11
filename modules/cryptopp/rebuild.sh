#!/bin/sh

export CC=clang-8
export CXX=clang++-8
export CFLAGS="-fsanitize=address,undefined,fuzzer-no-link -O2 -g"
export CXXFLAGS="-fsanitize=address,undefined,fuzzer-no-link -D_GLIBCXX_DEBUG -O2 -g"
export LIBFUZZER_LINK="-fsanitize=fuzzer"

export LIBCRYPTOPP_A_PATH="/home/topcue/cryptopp/libcryptopp.a"
export CRYPTOPP_INCLUDE_PATH="/home/topcue/cryptopp"

make

echo "[*] rebuild CryptoFuzz"

echo `~/cryptofuzz/rebuild.sh`

