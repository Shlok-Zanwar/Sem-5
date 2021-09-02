import json
import re
from tabulate import tabulate


def giveLCToLiterals(literalTable, lc):
    for literal in literalTable:
        literal['address'] = lc
        lc += 1

    return literalTable, lc

file = open("EmotJSON.json", "r+")
emotJson = json.loads(file.read())

file = open("EmotArray.json", "r+")
emotArray = json.loads(file.read())

# print("yes" if "STdOP" in emotJson else "no")

file = open('input2.txt', 'r')
fileLines = file.readlines()

lines = []
for line in fileLines:
    line = line.strip()
    line = re.sub(',', ' ', line)
    line = re.sub('\s+', ' ', line)

    # print(line)
    lines.append(line.split(" "))

lc = 0
symbolTable = []
# format = {
#     "symbol": "something",
#     "lc": "something"
# }
literalTable = []
# format = {
#     "literal": "somthing",
#     "lc": "something"
# }


for line in lines:
    if line[0] == "START":
        lc = int(line[1])
        continue

    if line[0] == "END":
        literalTable, lc = giveLCToLiterals(literalTable, lc)

    if line[0] not in emotJson:
        symbolTable.append({
            "symbol": line[0],
            "address": lc,

        })

    if re.fullmatch("='([0-9]+)'", line[-1]):
        literalTable.append({
            "literal": line[-1],
            "newLiteral": int(line[-1][2:-1]),
            "address": None
        })

    lc += 1

# print(symbolTable)
headers = {"symbol": "Symbol", "address": "Address"}
print(tabulate(symbolTable, headers=headers, tablefmt="pretty"))

headers = {"literal": "Literal", "address": "Address"}
print(tabulate(literalTable, headers=headers, tablefmt="pretty"))