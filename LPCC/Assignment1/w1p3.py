import json
import re
from tabulate import tabulate

file = open("EmotJSON.json", "r+")
emotJson = json.loads(file.read())

file = open("EmotArray.json", "r+")
emotArray = json.loads(file.read())

# print("yes" if "STdOP" in emotJson else "no")

file = open('input1.txt', 'r')
fileLines = file.readlines()

lines = []
for line in fileLines:
    line = line.strip()
    line = re.sub(',', ' ', line)
    line = re.sub('\s+', ' ', line)

    # print(line)
    lines.append(line.split(" "))

symbolTable = []
# format = {
#     "symbol": "something",
#     "address": "something"
# }

for line in lines:
    if line[0] not in emotJson:
        symbolTable.append({
            "symbol": line[0],
            "address": None
        })

print(symbolTable)
headers = {"symbol": "Symbol", "address": "Address"}
print(tabulate(symbolTable, headers=headers, tablefmt="pretty"))

"""

IC :-
-------------------------------------------
LOAD A
STORE B
ABC
ADD5 D1, D2, D3
END


MDT :-
-------------------------------------------
Index		Line
-------------------------------------------
0		LOAD p
1		SUB q
2		MEND 
3		LOAD X
4		STORE #1
5		MEND 
6		STORE #2
7		LOAD X
8		STORE 5
9		LOAD X
10		STORE 10
11		LOAD #1
12		LOAD #3
13		MEND 


MNT :-
-------------------------------------------
Name		Pointer		Parameters
-------------------------------------------
ABC		0		0
ADD1		3		1
ADD5		6		3


MNT Variables :-
-------------------------------------------

ADD1 :-
--------------------------
Name		Value
--------------------------
ARG		#1


ADD5 :-
--------------------------
Name		Value
--------------------------
A1		#1
A2		#2
A3		#3


"""