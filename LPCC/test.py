import json
#
# file = open("EmotArray.json", "r+")
# emotArray = json.loads(file.read())
#
# emotJSON = {}
# for index, emot in enumerate(emotArray):
#     emot['class'] = str(emot['class'])
#     print(index)
#     emotJSON[emot['mnemonic']] = {
#         "mnemonic": emot['mnemonic'],
#         "class": emot['class'],
#         "opcode": emot['opcode']
#     }
#
# print(emotJSON)
#
# file = open("EmotJson.json", "w+")
# file.write(json.dumps(emotJSON))
# # emotJson = json.loads(file.read())
#

file = open('input3.txt', 'r')
fileLines = file.readlines()

file = open("Input3.txt", "w+")

for line in fileLines:
    file.write(line.split("(")[0] + "\n")

