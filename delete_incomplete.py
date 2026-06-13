import os
import subprocess
import glob
import re

def is_boilerplate(content):
    if not content.strip():
        return True
    
    # Check for empty main function
    if re.search(r'int\s+main\s*\(\)\s*\{\s*\}', content):
        return True
    
    # Check for empty test case loop commonly used in CP
    if re.search(r'while\s*\([^)]+\)\s*\{\s*\}', content):
        return True
        
    # Heuristic for files that are too small and just have imports
    if len(content) < 150:
        return True

    return False

def main():
    cpp_files = glob.glob('*.cpp')
    to_delete = []

    for f in cpp_files:
        path = os.path.join(os.getcwd(), f)
        try:
            with open(path, 'r', encoding='utf-8') as file:
                content = file.read()
            
            if is_boilerplate(content):
                to_delete.append((path, "Empty or boilerplate"))
                continue
                
            # Check for syntax errors
            # Windows g++ might need shell=True or be in PATH
            result = subprocess.run(['g++', '-fsyntax-only', path], 
                                     stdout=subprocess.PIPE, 
                                     stderr=subprocess.PIPE)
            if result.returncode != 0:
                to_delete.append((path, "Syntax errors"))
                continue
                
        except Exception as e:
            print(f"Error processing {f}: {e}")

    for idx, (path, reason) in enumerate(to_delete):
        print(f"Deleting: {os.path.basename(path)} (Reason: {reason})")
        try:
            os.remove(path)
        except Exception as e:
            print(f"Failed to delete {path}: {e}")
            
    print(f"Total deleted: {len(to_delete)}")

if __name__ == '__main__':
    main()
