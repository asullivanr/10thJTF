import os
import sys

directory = os.path.dirname(os.path.realpath(sys.argv[0])) # directory of your script
for subdir, dirs, files in os.walk(directory):
    for filename in files:
        if filename.find('.cpp') > 0:
            newFilename = filename.replace(".cpp", ".hpp") # replace only in filename
            subdirectoryPath = os.path.relpath(subdir, directory) # path to subdirectory
            filePath = os.path.join(subdirectoryPath, filename) # path to file
            newFilePath = os.path.join(subdirectoryPath, newFilename) # new path
            os.rename(filePath, newFilePath) # rename