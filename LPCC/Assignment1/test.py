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

# file = open('input3.txt', 'r')
# fileLines = file.readlines()
#
# file = open("Input3.txt", "w+")
#
# for line in fileLines:
#     file.write(line.split("(")[0] + "\n")

# file = open("EmotArray.json", "r+")
emotArray = [
  {
    "mnemonic": "STOP",
    "class": 1,
    "opcode": "00"
  },
  {
    "mnemonic": "ADD",
    "class": 1,
    "opcode": "01"
  },
  {
    "mnemonic": "SUB",
    "class": 1,
    "opcode": "02"
  },
  {
    "mnemonic": "MULT",
    "class": 1,
    "opcode": "03"
  },
  {
    "mnemonic": "MOVER",
    "class": 1,
    "opcode": "04"
  },
  {
    "mnemonic": "MOVEM",
    "class": 1,
    "opcode": "05"
  },
  {
    "mnemonic": "COMP",
    "class": 1,
    "opcode": "06"
  },
  {
    "mnemonic": "BC",
    "class": 1,
    "opcode": "07"
  },
  {
    "mnemonic": "DIV",
    "class": 1,
    "opcode": "08"
  },
  {
    "mnemonic": "READ",
    "class": 1,
    "opcode": "09"
  },
  {
    "mnemonic": "PRINT",
    "class": 1,
    "opcode": "10"
  },
  {
    "mnemonic": "START",
    "class": 3,
    "opcode": "01"
  },
  {
    "mnemonic": "END",
    "class": 3,
    "opcode": "02"
  },
  {
    "mnemonic": "ORIGIN",
    "class": 3,
    "opcode": "03"
  },
  {
    "mnemonic": "EQU",
    "class": 3,
    "opcode": "04"
  },
  {
    "mnemonic": "LTORG",
    "class": 3,
    "opcode": "05"
  },
  {
    "mnemonic": "DS",
    "class": 2,
    "opcode": "01"
  },
  {
    "mnemonic": "DC",
    "class": 2,
    "opcode": "02"
  },
  {
    "mnemonic": "AREG",
    "class": 4,
    "opcode": "01"
  },
  {
    "mnemonic": "BREG",
    "class": 4,
    "opcode": "02"
  },
  {
    "mnemonic": "CREG",
    "class": 4,
    "opcode": "03"
  },
  {
    "mnemonic": "EQ",
    "class": 5,
    "opcode": "01"
  },
  {
    "mnemonic": "LT",
    "class": 5,
    "opcode": "02"
  },
  {
    "mnemonic": "GT",
    "class": 5,
    "opcode": "03"
  },
  {
    "mnemonic": "NE",
    "class": 5,
    "opcode": "04"
  },
  {
    "mnemonic": "LE",
    "class": 5,
    "opcode": "05"
  },
  {
    "mnemonic": "GT",
    "class": 5,
    "opcode": "06"
  },
  {
    "mnemonic": "ANY",
    "class": 5,
    "opcode": "07"
  }
]

# file = open("Class.json", "r+")
classJson = {
  "1": "IS",
  "2": "DL",
  "3": "AD",
  "4": "RG",
  "5": "CC"
}

for emot in emotArray:
    print(emot['mnemonic'] + " " + classJson[str(emot["class"])] + " " + emot["opcode"] )