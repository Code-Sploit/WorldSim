#!/usr/bin/python3

CFLAGS='-c -I include '

csources = []

import fnmatch
import os

for root, dirnames, filenames in os.walk('.'):
    for filename in fnmatch.filter(filenames, '*.c'):
        if "apps" not in os.path.join(root, filename) and "clib" not in os.path.join(root, filename):
            csources.append(os.path.join(root, filename))

for i in range(len(csources)):
    c = csources[i]

    os.system("mkdir -p build/" + c)

    print("[" + str(i + 1) + "/" + str(len(csources)) + "] " + "Compiling: [" + c + "]")

    os.system("gcc " + CFLAGS + c + " -o build/" + c + ".o")

total = ""

for c in csources:
    total += "build/"
    total += c
    total += ".o "

os.system("gcc -o worldsim " + total);
