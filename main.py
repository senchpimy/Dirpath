#!/usr/bin/python
import os 
path=os.getenv("PWD")
splited=path.split("/")[1:]
if os.getlogin()==splited[1]:
    splited.pop(0)
    splited[0]="~"

for i,_ in enumerate(splited[1:]):
    splited[i]=splited[i][:2]

print("/".join(splited))
