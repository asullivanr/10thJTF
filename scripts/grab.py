 
import re
import sys

regex = "(?<=class ).*(?= [:{])"

# Read file
fileName = sys.argv[1]
file = open(fileName, "r")
data = file.read()

# Run regex
matches = re.findall(regex, data)

# Filter out cfgBlahBlah classes
filtered = filter(lambda s: s[:3] != "Cfg", matches)

# Remove superclass the stupid way
mapped = map(lambda s: s[:s.find(" :")], filtered)

# Smash it back together with quotes and commas
output = "\",\n\"".join(mapped)

print("\"" + output + "\"")
