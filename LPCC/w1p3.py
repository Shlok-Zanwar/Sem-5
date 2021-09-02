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
