#!/usr/bin/env python3
"""
Fix C99-style variable declarations to C90-style.
Converts: TYPE var = value; 
To:       TYPE var; ... var = value;
"""

import re
import sys

def fix_c99_declarations(content):
    """Replace C99-style declarations with C90-style."""
    lines = content.split('\n')
    final = []
    
    for i, line in enumerate(lines):
        # Match C99-style declaration with initialization
        match = re.match(r'^(\s+)(NTSTATUS|ULONG|UCHAR|WDFDEVICE|WDFREQUEST|PDEVICE_CONTEXT|PVOID|BOOLEAN|USHORT|PMTP_[A-Z_]+|LIST_ENTRY|size_t|WDFMEMORY|const\s+ULONG)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(.+);(.*)$', line)
        if match:
            indent, dtype, varname, value, comment = match.groups()
            # Split declaration and initialization
            final.append(f'{indent}{dtype} {varname};{comment}')
            # Add initialization on next line
            final.append(f'{indent}{varname} = {value};')
        # Also handle multiple declarations on one line (e.g., "PVOID x; size_t y;")
        elif re.search(r';\s+(NTSTATUS|ULONG|UCHAR|WDFDEVICE|WDFREQUEST|PDEVICE_CONTEXT|PVOID|BOOLEAN|USHORT|PMTP_[A-Z_]+|LIST_ENTRY|size_t)\s+[a-zA-Z_]', line):
            # Split into separate lines
            parts = line.split(';')
            indent = len(line) - len(line.lstrip())
            indent_str = ' ' * indent
            for part in parts:
                if part.strip():
                    final.append(indent_str + part.strip() + ';')
        else:
            final.append(line)
    
    return '\n'.join(final)

if __name__ == '__main__':
    with open('Mtp.c.backup', 'r') as f:
        content = f.read()
    
    fixed = fix_c99_declarations(content)
    
    with open('Mtp.c', 'w') as f:
        f.write(fixed)
    
    print("Fixed C99-style declarations in Mtp.c")

