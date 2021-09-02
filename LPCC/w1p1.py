import re

str = "MOVER       ,- AREG,=‘5’"

str = re.sub(',', ' ', str)
str = re.sub('\s+', ' ', str)

print(str)
print(str.split(" "))
