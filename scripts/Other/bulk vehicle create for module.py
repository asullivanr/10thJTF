import os

def extract_name_class(filepath):
    result = []
    name = ""
    class_name = ""

    if not os.path.exists(filepath): # For my sanity
        print(f"File not found: {filepath}")
        return ""

    with open(filepath, 'r', encoding='utf-8') as file: # Encoding hell
        for line in file:
            line = line.strip()
            # Arma bs outputs are stupid and make me hate Arma with a burning passion
            if line.startswith("NAME:"):
                name = next(file).strip()
                print(f"Found NAME: {name}")
            elif line.startswith("CLASS:"):
                class_name = next(file).strip()
                print(f"Found CLASS: {class_name}")

                if name and class_name:
                    result.append(f"{name}|{class_name}")
                    name = ""
                    class_name = ""

    return ";".join(result)

# Using import.txt as input and export.txt as its output
input_file = "import.txt"
output_file = "export.txt"

# Extract data
output = extract_name_class(input_file)

# Output to console
print("\nFinal Output:")
print(output)

# Write to export.txt
with open(output_file, 'w', encoding='utf-8') as f:
    f.write(output)

print(f"\nOutput written to {output_file}") # Sanity check

input("\nPress Enter to exit...") # Sanity check
