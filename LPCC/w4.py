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
        if (symbol['symbol'] == rightSymbol):
            address = symbol['address']
    index = 0
    for symbol in symbolTable:
        if (symbol['symbol'] == leftSymbol):
            symbol['address'] = address
            break
        index += 1

    if index == len(symbolTable):
        symbolTable.append({
            "symbol": leftSymbol,
            "address": address,
        })

    return symbolTable, address

def isConstant(variable):
    try:
        int(variable)
        return True
    except ValueError:
        return False



file = open("EmotJSON.json", "r+")
emotJson = json.loads(file.read())

file = open("Class.json", "r+")
classJson = json.loads(file.read())

file = open('Input3.txt', 'r')
fileLines = file.readlines()

outputFile = open("Output.txt", "w+")

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

    newOutput = ""
    incrementLC = True
    for word in line:

        if word in emotJson:
            if line[0] == "LTORG":
                literalTable, lc, poolTable = giveLCToLiterals(literalTable, lc, poolTable)
                for i in range(poolTable[-2], poolTable[-1]):
                    newOutput += "(DL,02) (C," + str(literalTable[i]['newLiteral']) + ") "
                    if(i < poolTable[-1]-1):
                        newOutput += "\n"
                incrementLC = False
                break

            newOutput += "(" + classJson[emotJson[word]['class']] + "," + emotJson[word]['opcode'] + ") "

            if word == "START":
                lc = int(line[1])
                newOutput += "(C," + str(lc) + ")"
                incrementLC = False
                break

            if word == "STOP":
                incrementLC = False
                break

            if word == "END":
                literalTable, lc, poolTable = giveLCToLiterals(literalTable, lc, poolTable)
                break

            if word == "ORIGIN":
                arg = line[1].split("+")
                addTo = arg[0]
                add = int(arg[1])

                lc = handleOrigin(symbolTable, addTo, add)
                newOutput += "(C," + str(lc) + ")"
                incrementLC = False
                break

            if word == "EQU":
                symbolTable, address = handleEqu(symbolTable, line[0], line[2])
                newOutput += "(C," + str(address) + ")"
                incrementLC = False
                break

        else:
            if re.fullmatch("='([0-9]+)'", word):
                newOutput += "(L," + str(len(literalTable)) + ") "
                literalTable.append({
                    "literal": word,
                    "newLiteral": int(word[2:-1]),
                    "address": None
                })
            elif isConstant(word):
                newOutput += "(C," + str(word) + ") "
            else:
                if word == line[0]:
                    index = 0
                    for symbol in symbolTable:
                        if(symbol["symbol"] == word):
                            symbol["address"] = lc
                            break
                        index += 1

                    if index == len(symbolTable):
                        symbolTable.append({
                            "symbol": word,
                            "address": lc,
                        })
                else:
                    index = 0
                    for symbol in symbolTable:
                        if (symbol["symbol"] == word):
                            break
                        index += 1
                    if index == len(symbolTable):
                        symbolTable.append({
                            "symbol": word,
                            "address": None,
                        })


                    newOutput += "(S," + str(index) + ") "

    # print(line, lc)
    outputFile.write(newOutput + "\n")
    if incrementLC:
        lc += 1

headers = {"symbol": "Symbol", "address": "Address"}
print("Symbol Table :- \n", tabulate(symbolTable, headers=headers, tablefmt="pretty"))

headers = {"literal": "Literal", "address": "Address"}
print("\nLiteral Table :- \n", tabulate(literalTable, headers=headers, tablefmt="pretty"))

print("\nPool Table :- ", poolTable)

#         START   200
#         MOVER   AREG,='50'
#         MOVEM   AREG,X
# L1      MOVER   BREG,='3'
#         ORIGIN  L1+3
#         LTORG
# NEXT    ADD         AREG,='1'
#         SUB         BREG,='2'
#         BC          LT, NEXT
#         LTORG
# NEXT    EQU     L1
#         ORIGIN  NEXT+9
#         MULT        CREG, X
#         STOP
# X       DS          1
#         END
