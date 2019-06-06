#!/usr/bin/env bash


sudo -S ulimit -v 800
klee -debug-print-instructions=all:stderr ./TEST_CASE-llvm-3.6.bc
sudo ulimit -v unlimited
