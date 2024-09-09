#!/usr/bin/env sh
cd ./cryptopp
export CXX=$1
export MAKEFLAGS="-Wno-unused-command-line-option"
make
mv -f ./libcryptopp.a ./build/$2/libcryptopp.a || mkdir -p ./build/$2 && mv -f ./libcryptopp.a ./build/$2/libcryptopp.a
make clean
# rm -rf ./a.out.aarch64.elf
# rm -rf ./a.out.aarch64.dbg
rm -rf ./cryptest.exe.dbg
