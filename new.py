#!/usr/bin/python3
# coding=utf-8

#
#  Author       : magicwenli
#  Date         : 2021-02-04 18:12:55
#  LastEditTime : 2021-02-04 18:12:55
#  Description  : 新建题目
#  FilePath     : /PTAbasic/new.py
#

import os
import re

def main():
    cwd = os.getcwd()
    start = 1001
    list = []

    for f in os.listdir(cwd):
        if re.match("1.*cpp", f) != None:
            list.append(f[:-4])
    while (str(start) in list):
        start += 1

    cmd = "cp 100.cpp "+str(start)+".cpp"
    if (not os.system(cmd)):
        print("Creation success. File name:\n" + cwd + "/" + str(start) + ".cpp.")
        opencmd="code "+ cwd + "/" + str(start) + ".cpp"
        os.system(opencmd)
    else:
        print("Creation failed.")


if __name__ == '__main__':
    main()
