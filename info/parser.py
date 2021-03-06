# coding=utf-8
###
#  Author       : magicwenli
#  Date         : 2021-02-05 23:39:23
#  LastEditTime : 2021-02-05 23:39:23
#  Description  : 
#  FilePath     : \bili_uploader\spider.py
#

import requests
import re
import json
import os

def main():
    table='label\ttitle\tscore\n'
    with open('exam.json','r',encoding='UTF-8') as file:
        exams = json.load(file)['problemSetProblems']
        for ex in exams:
            table += ex['label'] + '\t' + ex['title'] + '\t' + str(ex['score']) + '\n'
    with open('list.txt', 'w') as save:
        save.write(table)
        


if __name__ == "__main__":
    main()