import re
import os

# ==========================================
# CONFIGURATION
# ==========================================
c_file_path = "CryGame.dll.c"         # Your massive 150MB C file
list_file_path = "tlv_ida_funcs.txt" # Your file with the offsets
output_dir = "Extracted_TLVs"        # Folder where all the TXT files will go

IMAGE_BASE = 0x10000000              # Base address
# ==========================================

def get_grouped_targets(filepath):
    """ Parses the TLV list and groups entry points by their base TLV name. """
    print(f"[*] Parsing offset list from {filepath}...")
    # Dictionary format: {"UnkTlv0014": {"SUB_10119A80": "TLV::UnkTlv0014::Read", ...}, ...}
    tlv_groups = {}
    
    with open(filepath, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line or not line.startswith("|"):
                continue
                
            # Parse format: |TLV::UnkTlv0194::Read|CryGame.dll+0x1d90e0|
            parts = line.split('|')
            if len(parts) >= 3:
                friendly_name = parts[1]
                offset_str = parts[2]
                
                # Extract the base TLV name (e.g., "UnkTlv0194" from "TLV::UnkTlv0194::Read")
                name_parts = friendly_name.split("::")
                if len(name_parts) >= 2:
                    base_tlv_name = name_parts[1]
                else:
                    base_tlv_name = "Unknown_TLVs"
                
                if "+" in offset_str:
                    hex_val = offset_str.split('+')[-1]
                    offset = int(hex_val, 16)
                    ea = IMAGE_BASE + offset
                    
                    sub_name = f"sub_{ea:X}".upper()
                    
                    # Group them!
                    if base_tlv_name not in tlv_groups:
                        tlv_groups[base_tlv_name] = {}
                    tlv_groups[base_tlv_name][sub_name] = friendly_name
                    
    print(f"[+] Found {len(tlv_groups)} unique TLV structures to extract.")
    return tlv_groups

def parse_ida_c_file_safely(filepath):
    """ Parses the massive C file using IDA's explicit comment dividers. """
    print(f"[*] Indexing 150MB C file: {filepath} (This takes 5-10 seconds)...")
    functions = {}
    
    current_func_name = None
    body = []
    recording = False

    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if line.startswith("//----- ("):
                if current_func_name and body:
                    functions[current_func_name] = "".join(body)
                
                recording = True
                current_func_name = None
                body = [line]
                continue
                
            if recording:
                body.append(line)
                if not current_func_name:
                    match = re.search(r'\b(sub_[0-9a-fA-F]+)\s*\(', line, re.IGNORECASE)
                    if match and not line.strip().startswith("//"):
                        current_func_name = match.group(1).upper()
                        
    if current_func_name and body:
        functions[current_func_name] = "".join(body)
                    
    print(f"[+] Indexing complete! Found {len(functions)} total sub_ functions.")
    return functions

def spider_and_save(functions, tlv_groups):
    """ Spiders dependencies for EACH TLV group and saves them to separate files. """
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        print(f"[*] Created output directory: {output_dir}")

    print(f"[*] Spidering dependencies and generating files...")
    
    for tlv_name, entry_points in tlv_groups.items():
        extracted_code = {}
        queue = list(entry_points.keys())
        visited = set()

        while queue:
            curr_sub = queue.pop(0).upper()
            
            if curr_sub in visited:
                continue
                
            visited.add(curr_sub)
            
            if curr_sub in functions:
                code = functions[curr_sub]
                friendly_name = entry_points.get(curr_sub, "Internal Helper Function")
                extracted_code[curr_sub] = (friendly_name, code)
                
                # Find internal calls
                calls = re.findall(r'\b(sub_[0-9a-fA-F]+)\s*\(', code, re.IGNORECASE)
                for call in set(calls):
                    call_upper = call.upper()
                    if call_upper not in visited:
                        queue.append(call_upper)
        
        # Write this specific TLV to its own file!
        if extracted_code:
            file_path = os.path.join(output_dir, f"{tlv_name}.c")
            with open(file_path, "w", encoding="utf-8") as out:
                for sub_name, (friendly, code) in extracted_code.items():
                    out.write(f"// {'='*60}\n")
                    out.write(f"// Name: {friendly}\n")
                    out.write(f"// Address Name: {sub_name}\n")
                    out.write(f"// {'='*60}\n")
                    out.write(code + "\n\n")
                    
    print(f"[+] All files successfully generated in the '{output_dir}' folder!")

# ==========================================
# EXECUTION
# ==========================================
if not os.path.exists(c_file_path) or not os.path.exists(list_file_path):
    print(f"[!] ERROR: Ensure '{c_file_path}' and '{list_file_path}' are in this folder.")
else:
    target_dict = get_grouped_targets(list_file_path)
    all_funcs_dict = parse_ida_c_file_safely(c_file_path)
    spider_and_save(all_funcs_dict, target_dict)