import re
from tabulate import tabulate

file = open('input2.txt', 'r')
fileLines = file.readlines()

lines = []
for line in fileLines:
    line = line.strip()
    line = re.sub(',', ' ', line)
    line = re.sub('\s+', ' ', line)

    lines.append(line.split(" "))

literalTable = []
# format = {
#     "literal": "somthing",
#     "address": "something"
# }

for line in lines:
    # print (line)
    if re.fullmatch("='([0-9]+)'", line[-1]):
        # print(line[-1])
        literalTable.append({
            "literal": line[-1],
            "address": None
        })

headers = {"literal": "Literal", "address": "Address"}
print(tabulate(literalTable, headers=headers, tablefmt="pretty"))