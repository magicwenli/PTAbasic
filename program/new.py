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
import time


def main():
    cwd = os.getcwd()
    start_default = 1001
    list = []

    for f in os.listdir(cwd):
        if re.match("1[0-9]{3}.cpp", f) != None:
            list.append(f[:-4])
    while (str(start_default) in list):
        start_default += 1

    markdown = '# PTA Basic\n\n'
    acc_num = 0
    table = '| label | title                    | score | status |\n|-------|--------------------------|-------|--------|\n'

    with open('../info/mark.md', 'r', encoding='UTF-8') as info:
        line = info.readline()
        line = info.readline()
        for i in range(1001, 1095):
            line = info.readline()
            if (str(i) in list):
                acc_num += 1
                table += line[:-1] + '  ✅  |\n'
            else:
                table += line[:-1] + '     |\n'

    markdown += '> This document was generated by a script and was modified on {}.\n\n'.format(
        time.strftime("%B %d, %Y", time.localtime()))
    markdown += '## ' + str(acc_num) + ' / 95\n\n'
    markdown += table
    with open('../README.md', 'w', encoding='UTF-8') as file:
        file.write(markdown)

    # Generation Part
    start = input("Please input the name of the next file(default:{}):".format(
        str(start_default)))
    if start == '':
        start = start_default
    cmd = "cp 100.cpp "+str(start)+".cpp"
    if (not os.system(cmd)):
        print("Creation success. File name:\n" +
              cwd + "/" + str(start) + ".cpp.")
        opencmd = "code " + cwd + "/" + str(start) + ".cpp"
        os.system(opencmd)
    else:
        print("Creation failed.")


if __name__ == '__main__':
    main()
