import os
import glob

#! /usr/bin/env python3

replacements = [
# find, replace
(b'Tenthed_Armor_Misriah_Named', b'z\\10thMod\\addons\\armor_misriah_named')
]
# path to files. here all cpp files in the current working directory
globpath = './**/*.cpp'

import glob
for filepath in glob.iglob(globpath, recursive=True):
    with open(filepath, 'rb') as file:
        s = file.read()
    for f, r in replacements:
        s = s.replace(f, r)
    with open(filepath, "wb") as file:
        file.write(s)
