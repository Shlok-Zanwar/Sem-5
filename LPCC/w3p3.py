import re
import json
from tabulate import tabulate

def giveLCToLiterals(literalTable, lc, poolTable=None):
    if poolTable is None:
        poolTable = [0]

    if poolTable[-1] == len(literalTable):
        return literalTable, lc, poolTable

    for i in range(poolTable[-1], len(literalTable)):
        literalTable[i]['address'] = lc
        lc += 1

    poolTable.append(len(literalTable))
    return literalTable, lc, poolTable

def handleOrigin(symbolTable, addToSymbol, addNum):
    for symbol in symbolTable:
        if(symbol['symbol'] == addToSymbol):
            return symbol['address'] + addNum

def handleEqu(symbolTable, leftSymbol, rightSymbol):
    address = 0
    for symbol in symbolTable:
        if(symbol['symbol'] == rightSymbol):
            address = symbol['address'],
            # symbolTable.append({
            #     "symbol": newSymbol,
            #     "address": symbol['address'],
            # })
            return symbolTable

    index = 0
    for symbol in symbolTable:
        index += 1
        if(symbol['symbol'] == rightSymbol):


file = open("EmotJSON.json", "r+")
emotJson = json.loads(file.read())

file = open('input2.txt', 'r')
fileLines = file.readlines()

lines = []
for line in fileLines:
    line = line.strip()
    line = re.sub(',', ' ', line)
    line = re.sub('\s+', ' ', line)

    lines.append(line.split(" "))

poolTable = [0]
literalTable = []
symbolTable = []
lc = 0

for line in lines:
    if line[0] == "START":
        lc = int(line[1])
        continue

    if line[0] == "END":
        literalTable, lc, poolTable = giveLCToLiterals(literalTable, lc, poolTable)
        continue

    if line[0] == "LTORG":
        # print(poolTable, lc, literalTable)
        literalTable, lc, poolTable = giveLCToLiterals(literalTable, lc, poolTable)
        continue

    if line[0] == "ORIGIN":
        arg = line[1].split("+")
        addTo = arg[0]
        add = int(arg[1])

        lc = handleOrigin(symbolTable, addTo, add)
        continue

    if line[1] == "EQU":
        symbolTable = handleEqu(symbolTable, line[2], line[0])
        continue

    if line[0] not in emotJson:
        symbolTable.append({
            "symbol": line[0],
            "address": lc,
        })
    # print (line)
    if re.fullmatch("='([0-9]+)'", line[-1]):
        # print(line[-1])
        literalTable.append({
            "literal": line[-1],
            "newLiteral": int(line[-1][2:-1]),
            "address": None
        })
    elif line[-1] not in emotJson:
        symbolTable.append({
            "symbol": line[-1],
            "address": None,
        })

    # print(line, lc)
    lc += 1

headers = {"symbol": "Symbol", "address": "Address"}
print("Symbol Table :- \n", tabulate(symbolTable, headers=headers, tablefmt="pretty"))

headers = {"literal": "Literal", "address": "Address"}
print("\nLiteral Table :- \n", tabulate(literalTable, headers=headers, tablefmt="pretty"))

print("\nPool Table :- ", poolTable)
