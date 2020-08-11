#!/bin/bash

cd ~/cryptofuzz
python2 gen_repository.py
export CC=clang-8
export CXX=clang++-8
export CFLAGS="-fsanitize=address,undefined,fuzzer-no-link -O2 -g"
# -DCRYPTOFUZZ_NO_OPENSSL -DCRYPTOFUZZ_BOTAN -DCRYPTOFUZZ_CRYPTOPP -DCRYPTOFUZZ_MBEDTLS -DCRYPTOFUZZ_LIBGMP
export CXXFLAGS="-fsanitize=address,undefined,fuzzer-no-link -D_GLIBCXX_DEBUG -O2 -g -DCRYPTOFUZZ_CRYPTOPP -DCRYPTOFUZZ_BOTAN"
export LIBFUZZER_LINK="-fsanitize=fuzzer"

make

echo -e "\n\n\n\n\n\n\n\n[*] Done!"
echo -e "\a"; sleep 0.3; echo -e "\a"; sleep 0.3; echo -e "\a"

# EOF

