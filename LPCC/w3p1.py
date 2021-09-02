import re
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
# format = {
#     "literal": "somthing",
#     "address": "something"
# }
lc = 0

for line in lines:
    if line[0] == "START":
        lc = int(line[1])
        continue

    if line[0] == "END":
        literalTable, lc, poolTable = giveLCToLiterals(literalTable, lc, poolTable)

    if line[0] == "LTORG":
        # print(poolTable, lc, literalTable)
        literalTable, lc, poolTable = giveLCToLiterals(literalTable, lc, poolTable)
        continue
    # print (line)
    if re.fullmatch("='([0-9]+)'", line[-1]):
        # print(line[-1])
        literalTable.append({
            "literal": line[-1],
            "newLiteral": int(line[-1][2:-1]),
            "address": None
        })

    # print(line, lc)
    lc += 1

headers = {"literal": "Literal", "address": "Address"}
print("Literal Table :- \n", tabulate(literalTable, headers=headers, tablefmt="pretty"))
print("\nPool Table :- ", (poolTable))