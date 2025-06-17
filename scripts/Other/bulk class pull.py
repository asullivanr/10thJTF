import os

def extract_classes_only(filepath):
    classes = []

    if not os.path.exists(filepath): # For my sanity
        print(f"File not found: {filepath}")
        return ""

    with open(filepath, 'r', encoding='utf-8') as file: # Encoding hell
        for line in file:
            line = line.strip()
            # Arma bs outputs are stupid and make me hate Arma with a burning passion
            if line.startswith("CLASS:"):
                class_line = next(file).strip()
                print(f"Found CLASS: {class_line}")
                classes.append(class_line)

    return ",".join(classes)

# Using import.txt as input and export.txt as its output
input_file = "import.txt"
output_file = "export.txt"

# Extract class names only
output = extract_classes_only(input_file)

# Output to console
print("\nFinal Output:")
print(output)

# Write to export.txt
with open(output_file, 'w', encoding='utf-8') as f:
    f.write(output)

print(f"\nOutput written to {output_file}") # Sanity check

input("\nPress Enter to exit...") # Sanity check
