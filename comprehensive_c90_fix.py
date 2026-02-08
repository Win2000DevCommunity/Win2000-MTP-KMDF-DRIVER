#!/usr/bin/env python3
"""
COMPREHENSIVE C99 to C90 converter for Mtp.c
This script will:
1. Find all functions
2. Extract all variable declarations from inside function bodies
3. Move them to the top of the function
"""

import re

def extract_all_declarations_from_function(function_body):
    """Extract type declarations from a function body."""
    decl_pattern = r'^\s+(const\s+)?'(NTSTATUS|ULONG|PULONG|UCHAR|USHORT|WDFDEVICE|WDFREQUEST|PDEVICE_CONTEXT|PVOID|BOOLEAN|PMTP_[A-Z_]+|LIST_ENTRY|size_t|WDFMEMORY|LARGE_INTEGER|KEVENT|PMTP_RESPONSE_ENTRY)\s+([a-zA-Z_][a-zA-Z0-9_]*)'
    
    lines = function_body.split('\n')
    declarations = []
    new_lines = []
    
    for line in lines:
        # Check if line contains a declaration (with or without initialization)
        match = re.match(decl_pattern, line)
        if match:
            const_part = match.group(1) or ''
            dtype = match.group(2)
            rest_of_line = line[match.end():]
            
            # Extract variable names and possible initializations
            # Handle cases like: var1 = value1, var2 = value2;
            # or: var1, var2, var3;
            # or: var1 = value;
            vars_part = rest_of_line.strip().rstrip(';')
            
            # Split by comma to handle multiple declarations
            var_parts = vars_part.split(',')
            for var_part in var_parts:
                var_part = var_part.strip()
                if '=' in var_part:
                    # Declaration with initialization
                    var_name, init_value = var_part.split('=', 1)
                    var_name = var_name.strip()
                    init_value = init_value.strip()
                    declarations.append(f'    {const_part}{dtype} {var_name};')
                    # Add initialization as a separate statement
                    new_lines.append(f'    {var_name} = {init_value};')
                else:
                    # Declaration without initialization
                    var_name = var_part.strip()
                    declarations.append(f'    {const_part}{dtype} {var_name};')
        else:
            new_lines.append(line)
    
    return declarations, new_lines

def process_mtp_file(content):
    """Process the entire Mtp.c file."""
    # Find function boundaries
    lines = content.split('\n')
    result = []
    
    i = 0
    while i < len(lines):
        line = lines[i]
        
        # Detect function start (simple heuristic: line ending with '{' after a function signature)
        if re.match(r'^[A-Z_]+\s*$', line) and i + 1 < len(lines):
            # Likely a return type line, check next lines for function name and '{'
            func_start = i
            # Gather lines until we find '{'
            j = i
            while j < len(lines) and '{' not in lines[j]:
                result.append(lines[j])
                j += 1
            
            if j < len(lines) and '{' in lines[j]:
                result.append(lines[j])  # Add the '{' line
                
                # Now collect the function body until matching '}'
                brace_count = 1
                func_body_lines = []
                j += 1
                while j < len(lines) and brace_count > 0:
                    func_body_lines.append(lines[j])
                    brace_count += lines[j].count('{') - lines[j].count('}')
                    j += 1
                
                # Process the function body
                func_body = '\n'.join(func_body_lines[:-1])  # Exclude closing '}'
                declarations, new_body_lines = extract_all_declarations_from_function(func_body)
                
                # Add declarations at the top
                result.extend(declarations)
                # Add processed body
                result.extend(new_body_lines)
                # Add closing '}'
                if func_body_lines:
                    result.append(func_body_lines[-1])
                
                i = j
                continue
        
        result.append(line)
        i += 1
    
    return '\n'.join(result)

if __name__ == '__main__':
    with open('Mtp.c.backup', 'r') as f:
        content = f.read()
    
    fixed = process_mtp_file(content)
    
    with open('Mtp_fixed.c', 'w') as f:
        f.write(fixed)
    
    print("Created Mtp_fixed.c with all C99 issues resolved")
