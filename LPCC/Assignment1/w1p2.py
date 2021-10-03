file1 = open('Input1.txt', 'r')
Lines = file1.readlines()

count = 0
for line in Lines:
    count += 1
    print(line.strip())












#  For Formatting the array.

# import json
# file1 = open("EMOT.json", "r+")
# emots = json.loads(file1.read())

# print(data[0])

# emotDetails = {}
# i = 0
# for emot in emots:
#     emotDetails[emot['Mnemonic']] = i
#     i += 1
#
# print(emotDetails)
#
# file2 = open("EmotJSON.json", "w+")
# file2.write(json.dumps(emotDetails))

# newEmots = []
# for emot in emots:
#     emot['Class'] = int(emot['Class'])
#     if emot['Opcode'] != "10" :
#         emot['Opcode'] = "0" + emot['Opcode']
#
#     emot['mnemonic'] = emot.pop('Mnemonic')
#     emot['class'] = emot.pop('Class')
#     emot['opcode'] = emot.pop('Opcode')
#
# file2 = open("EmotArray.json", "w+")
# file2.write(json.dumps(emots))